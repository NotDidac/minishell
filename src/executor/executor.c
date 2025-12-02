/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: didguill <didguill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 23:31:40 by didguill          #+#    #+#             */
/*   Updated: 2025/11/27 20:53:27 by didguill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser/command_list.h"
#include "free/clear_commands.h"
#include "../libft/inc/libft.h"
#include "colors.h"

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>

static void	builtin_echo(char **args);
static void	builtin_cd(char **args);
static void	builtin_pwd(char **args);
static void	builtin_export(char **args);
static void	builtin_unset(char **args);
static void	builtin_env(char **args);
static void	builtin_exit(char **args);

static void	handle_input_redirect(char *file)
{
    int	fd;

    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        perror(file);
        return;
    }
    dup2(fd, STDIN_FILENO);
    close(fd);
}

static void	handle_output_redirect(char *file)
{
    int	fd;

    fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
    {
        perror(file);
        return;
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
}

static void	handle_append_redirect(char *file)
{
    int	fd;

    fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd < 0)
    {
        perror(file);
        return;
    }
    dup2(fd, STDOUT_FILENO);
    close(fd);
}

static void	handle_heredoc(char *delimiter)
{
    (void)delimiter;
}

static bool	is_builtin(char *cmd)
{
    if (!cmd)
        return (false);
    if (strcmp(cmd, "echo") == 0 || strcmp(cmd, "cd") == 0 ||
        strcmp(cmd, "pwd") == 0 || strcmp(cmd, "export") == 0 ||
        strcmp(cmd, "unset") == 0 || strcmp(cmd, "env") == 0 ||
        strcmp(cmd, "exit") == 0)
        return (true);
    return (false);
}

static void	execute_builtin(char **args)
{
    if (strcmp(args[0], "echo") == 0)
        builtin_echo(args);
    else if (strcmp(args[0], "cd") == 0)
        builtin_cd(args);
    else if (strcmp(args[0], "pwd") == 0)
        builtin_pwd(args);
    else if (strcmp(args[0], "export") == 0)
        builtin_export(args);
    else if (strcmp(args[0], "unset") == 0)
        builtin_unset(args);
    else if (strcmp(args[0], "env") == 0)
        builtin_env(args);
    else if (strcmp(args[0], "exit") == 0)
        builtin_exit(args);
}

static void	execute_external_command(char **args)
{
    pid_t	pid;

    pid = fork();
    if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
        {
            perror(args[0]);
            exit(127);
        }
    }
    else if (pid > 0)
        waitpid(pid, NULL, 0);
    else
        perror("fork");
}

static void	handle_redirections(t_redirection *redirs)
{
    t_redirection	*current;

    current = redirs;
    while (current)
    {
        if (current->type == TOKEN_REDIRECT_IN)
            handle_input_redirect(current->file);
        else if (current->type == TOKEN_REDIRECT_OUT)
            handle_output_redirect(current->file);
        else if (current->type == TOKEN_REDIRECT_APPEND)
            handle_append_redirect(current->file);
        else if (current->type == TOKEN_HEREDOC)
            handle_heredoc(current->file);

        current = current->next;
    }
}

static void	execute_command(t_command *cmd)
{
    if (is_builtin(cmd->args[0]))
        execute_builtin(cmd->args);
    else
        execute_external_command(cmd->args);
}

int	executor(t_command *commands, int last_exit_status)
{
    t_command	*current;

    if (!commands)
        return (last_exit_status);

    current = commands;
    while (current)
    {
        if (current->is_valid)
        {
            if (current->redirs)
                handle_redirections(current->redirs);
            if (current->args && current->args[0])
                execute_command(current);
        }

        current = current->next;
    }
	return (last_exit_status);
}

static void	builtin_echo(char **args)
{
    int	i;
    int	newline;

    newline = 1;
    i = 1;
    if (args[1] && strcmp(args[1], "-n") == 0)
    {
        newline = 0;
        i = 2;
    }
    while (args[i])
    {
        printf("%s", args[i]);
        if (args[i + 1])
            printf(" ");
        i++;
    }
    if (newline)
        printf("\n");
}

static void	builtin_cd(char **args)
{
    char	*path;

    if (!args[1] || strcmp(args[1], "~") == 0)
        path = getenv("HOME");
    else
        path = args[1];

    if (chdir(path) != 0)
        perror("cd");
}

static void	builtin_pwd(char **args)
{
    char	*cwd;

    (void)args;
    cwd = getcwd(NULL, 0);
    if (cwd)
    {
        printf("%s\n", cwd);
        free(cwd);
    }
    else
        perror("pwd");
}

static void	builtin_export(char **args)
{
    int	i;

    if (!args[1])
    {
        extern char **environ;
        i = 0;
        while (environ[i])
        {
            printf("declare -x %s\n", environ[i]);
            i++;
        }
    }
    else
    {
        i = 1;
        while (args[i])
        {
            if (putenv(args[i]) != 0)
                perror("export");
            i++;
        }
    }
}

static void	builtin_unset(char **args)
{
    int	i;

    i = 1;
    while (args[i])
    {
        if (unsetenv(args[i]) != 0)
            perror("unset");
        i++;
    }
}

static void	builtin_env(char **args)
{
    extern char **environ;
    int	i;

    (void)args;
    i = 0;
    while (environ[i])
    {
        printf("%s\n", environ[i]);
        i++;
    }
}

static void	builtin_exit(char **args)
{
    int	exit_code;

    exit_code = 0;
    if (args[1])
        exit_code = atoi(args[1]);

    printf("exit\n");
    exit(exit_code);
}
