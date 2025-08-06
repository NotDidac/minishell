/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:31:40 by didguill          #+#    #+#             */
/*   Updated: 2025/08/04 11:06:34 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/command_list.h"
#include "colors.h"

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "parser/command_list.h"
#include <stdlib.h>


// Test 1: echo hola
t_command *test_echo_hola(void)
{
	t_command *cmd = malloc(sizeof(t_command));
	cmd->args = malloc(sizeof(char *) * 3);
	cmd->args[0] = strdup("echo");
	cmd->args[1] = strdup("hola");
	cmd->args[2] = NULL;
	cmd->input_file = NULL;
	cmd->output_file = NULL;
	cmd->is_pipe = false;
	cmd->next = NULL;
	return cmd;
}

// Test 2: echo hola mundo | wc -w
t_command *test_echo_wc(void)
{
	t_command *cmd1 = malloc(sizeof(t_command));
	t_command *cmd2 = malloc(sizeof(t_command));

	cmd1->args = malloc(sizeof(char *) * 4);
	cmd1->args[0] = strdup("echo");
	cmd1->args[1] = strdup("hola");
	cmd1->args[2] = strdup("mundo");
	cmd1->args[3] = NULL;
	cmd1->is_pipe = true;
	cmd1->input_file = NULL;
	cmd1->output_file = NULL;
	cmd1->next = cmd2;

	cmd2->args = malloc(sizeof(char *) * 3);
	cmd2->args[0] = strdup("wc");
	cmd2->args[1] = strdup("-w");
	cmd2->args[2] = NULL;
	cmd2->is_pipe = false;
	cmd2->input_file = NULL;
	cmd2->output_file = NULL;
	cmd2->next = NULL;

	return cmd1;
}

// Test 3: ls | wc -l
t_command *test_ls_wc(void)
{
	t_command *cmd1 = malloc(sizeof(t_command));
	t_command *cmd2 = malloc(sizeof(t_command));

	cmd1->args = malloc(sizeof(char *) * 2);
	cmd1->args[0] = strdup("ls");
	cmd1->args[1] = NULL;
	cmd1->is_pipe = true;
	cmd1->input_file = NULL;
	cmd1->output_file = NULL;
	cmd1->next = cmd2;

	cmd2->args = malloc(sizeof(char *) * 3);
	cmd2->args[0] = strdup("wc");
	cmd2->args[1] = strdup("-l");
	cmd2->args[2] = NULL;
	cmd2->is_pipe = false;
	cmd2->input_file = NULL;
	cmd2->output_file = NULL;
	cmd2->next = NULL;

	return cmd1;
}

void	executor(t_command *commands)
{
	t_command	*cmd = commands;
	int			prev_fd = -1;      // read-end del pipe anterior
	int			pipe_fd[2];        // para el pipe actual
	pid_t		pid;
	int			status;

	printf(BLUE "[Executor] " RESET "Executing commands...\n");

	while (cmd)
	{
		// Si hay pipe, creamos pipe
		if (cmd->is_pipe)
		{
			if (pipe(pipe_fd) == -1)
			{
				perror("pipe");
				exit(EXIT_FAILURE);
			}
		}

		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			// --- HIJO ---

			// Redirección de entrada si viene de pipe anterior
			if (prev_fd != -1)
			{
				if (dup2(prev_fd, STDIN_FILENO) == -1)
				{
					perror("dup2 prev_fd");
					exit(EXIT_FAILURE);
				}
				close(prev_fd);
			}

			// Redirección de salida si hay pipe actual
			if (cmd->is_pipe)
			{
				close(pipe_fd[0]); // Cierra read end
				if (dup2(pipe_fd[1], STDOUT_FILENO) == -1)
				{
					perror("dup2 pipe_fd[1]");
					exit(EXIT_FAILURE);
				}
				close(pipe_fd[1]);
			}

			// --- Redirección de archivos ---
			if (cmd->input_file)
			{
				int fd_in = open(cmd->input_file, O_RDONLY);
				if (fd_in < 0)
				{
					perror("open input_file");
					exit(EXIT_FAILURE);
				}
				if (dup2(fd_in, STDIN_FILENO) == -1)
				{
					perror("dup2 input_file");
					exit(EXIT_FAILURE);
				}
				close(fd_in);
			}

			if (cmd->output_file)
			{
				int fd_out = open(cmd->output_file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
				if (fd_out < 0)
				{
					perror("open output_file");
					exit(EXIT_FAILURE);
				}
				if (dup2(fd_out, STDOUT_FILENO) == -1)
				{
					perror("dup2 output_file");
					exit(EXIT_FAILURE);
				}
				close(fd_out);
			}

			// Ejecutar comando
			execvp(cmd->args[0], cmd->args);
			perror("execvp");
			exit(EXIT_FAILURE);
		}
		else
		{
			// --- PADRE ---

			if (prev_fd != -1)
				close(prev_fd);

			if (cmd->is_pipe)
			{
				close(pipe_fd[1]);     // padre no escribe
				prev_fd = pipe_fd[0];  // read-end para el siguiente
			}
			else
			{
				prev_fd = -1;
			}

			cmd = cmd->next;
		}
	}

	// Esperamos a todos los hijos
	while (wait(&status) != -1 || errno == EINTR)
		;
}

