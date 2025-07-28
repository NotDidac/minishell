# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: didguill <didguill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/28 16:58:13 by didguill          #+#    #+#              #
#    Updated: 2025/07/28 16:59:29 by didguill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------- #
#         COLORS            #
# ------------------------- #
DEF_COLOR       = \033[0;39m
RED             = \033[0;91m
GREEN           = \033[0;92m
YELLOW          = \033[0;93m
MAGENTA         = \033[0;95m
CYAN            = \033[0;96m

# ------------------------- #
#      DIRECTORY PATHS      #
# ------------------------- #
NAME		= minishell

SRCS_DIR	= src/
MAIN_DIR	= $(SRCS_DIR)main/
UTILS_DIR	= $(SRCS_DIR)utils/
OBJS_DIR	= $(SRCS_DIR)obj/


# ------------------------- #
#       SOURCE FILES        #
# ------------------------- #
SRCS_MAIN	= main.c

SRCS_UTILS	= utils.c

SRC_FILES	= $(addprefix $(MAIN_DIR), $(SRCS_MAIN))\
			$(addprefix $(UTILS_DIR), $(SRCS_UTILS))

OBJ_FILES = $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRC_FILES))

# ------------------------- #
#       COMPILER FLAGS      #
# ------------------------- #
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -I ./inc/ -MMD -MP
RM			= rm -rf

MAKEFLAGS	+= --no-print-directory

# ------------------------- #
#         TARGETS           #
# ------------------------- #

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo -n "$(CYAN)Compiling and linking $(NAME)... $(DEF_COLOR)"
	@$(CC) $(OBJ_FILES) -o $(NAME)
	@echo "$(GREEN)Done!$(DEF_COLOR)"
	@echo "$(GREEN)(o_o) $(RED)$(NAME) $(GREEN)generated!\n$(DEF_COLOR)"

# Pattern rule to compile .c to .o in obj folder, creating directories as needed
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@echo "$(MAGENTA)Compiling:$(YELLOW) $< ...$(DEF_COLOR)"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo -n "$(CYAN)Removing object files... $(DEF_COLOR)"
	@$(RM) $(OBJS_DIR)
	@echo "$(GREEN)Done!$(DEF_COLOR)"

fclean: clean
	@echo -n "$(CYAN)Removing executable $(NAME)... $(DEF_COLOR)"
	@$(RM) $(NAME)
	@echo "$(RED)(×_×) $(NAME) $(GREEN)removed!\n$(DEF_COLOR)"

re: fclean all

-include $(OBJ_FILES:.o=.d)

.PHONY: all clean fclean re
