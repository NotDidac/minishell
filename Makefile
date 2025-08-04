# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: didguill <didguill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/28 16:58:13 by didguill          #+#    #+#              #
#    Updated: 2025/08/04 10:38:22 by didguill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------- #
#         COLORS            #
# ------------------------- #
DEF_COLOR	= \033[0;39m
RED			= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m

# ------------------------- #
#         VARIABLES         #
# ------------------------- #

NAME	= minishell

# Directories
SRC_DIR				= src/

SRC_LEXER_DIR		= lexer/
SRC_PARSER_DIR		= parser/
SRC_EXECUTOR_DIR	= executor/
SRC_BUILTINS_DIR	= builtins/
SRC_UTILS_DIR		= utils/
SRC_FREE_DIR		= free/
SRC_PRINT_LOGS_DIR	= print_logs/

OBJ_DIR				= build/
INC_DIR				= inc/

# Libft
LIBFT_DIR	= libft/
LIBFT_INC	= $(LIBFT_DIR)inc/
LIBFT_A		= $(LIBFT_DIR)libft.a

# Source files
SRC_LEXER		= lexer.c operator_handler.c lexer_utils.c token_list.c
SRC_PARSER		= parser.c parser_utils.c
SRC_EXECUTOR	= executor.c
SRC_BUILTINS	= builtins.c
SRC_UTILS		= startup_checks.c err_exit.c
SRC_FREE		= clear_tokens.c clear_commands.c
SRC_PRINT_LOGS	= lexer_log.c parser_log.c readline_log.c

SRCS			= $(addprefix $(SRC_READLINE_DIR),  $(SRC_READLINE))     \
				  $(addprefix $(SRC_LEXER_DIR),     $(SRC_LEXER))        \
				  $(addprefix $(SRC_PARSER_DIR),    $(SRC_PARSER))       \
				  $(addprefix $(SRC_EXECUTOR_DIR),  $(SRC_EXECUTOR))     \
				  $(addprefix $(SRC_BUILTINS_DIR),  $(SRC_BUILTINS))     \
				  $(addprefix $(SRC_UTILS_DIR),     $(SRC_UTILS))        \
				  $(addprefix $(SRC_FREE_DIR),      $(SRC_FREE))	     \
				  $(addprefix $(SRC_PRINT_LOGS_DIR), $(SRC_PRINT_LOGS))  \
				  main.c readline.c

SRCS			:= $(addprefix $(SRC_DIR), $(SRCS))

OBJS			 = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

# Compiler
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -I$(INC_DIR) -I$(LIBFT_INC) -MMD -MP
LDFLAGS		= -lreadline
RM			= rm -rf

MAKEFLAGS	+= --no-print-directory

# ------------------------- #
#         TARGETS           #
# ------------------------- #

all: $(NAME)

debug: fclean all
	@echo "$(CYAN)Running $(NAME) with Valgrind...$(DEF_COLOR)"
	@valgrind --leak-check=full --show-leak-kinds=definite --track-origins=yes ./$(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	@echo -n "$(CYAN)Linking $(NAME)... $(DEF_COLOR)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT_A) $(LDFLAGS) -o $(NAME)
	@echo "$(GREEN)Done!$(DEF_COLOR)"
	@echo "$(GREEN)(o_o) $(RED)$(NAME) $(GREEN)generated!\n$(DEF_COLOR)"

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

# Compile each object
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@echo "$(MAGENTA)Compiling:$(YELLOW) $< ...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo -n "$(CYAN)Cleaning $(NAME) object files... $(DEF_COLOR)"
	@$(RM) $(OBJ_DIR)
	@echo "$(GREEN)Done!$(DEF_COLOR)"

fclean:
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo -n "$(CYAN)Cleaning $(NAME) object files... $(DEF_COLOR)"
	@$(RM) $(OBJ_DIR)
	@echo "$(GREEN)Done!$(DEF_COLOR)"
	@echo -n "$(CYAN)Removing $(NAME) binary... $(DEF_COLOR)"
	@$(RM) $(NAME)
	@echo "$(RED)(×_×) $(NAME) $(GREEN)removed!\n$(DEF_COLOR)"

re: fclean all

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re debug
