# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: didguill <didguill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/28 16:58:13 by didguill          #+#    #+#              #
#    Updated: 2025/07/28 19:14:34 by didguill         ###   ########.fr        #
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
#         VARIABLES         #
# ------------------------- #

NAME			= minishell

# Directories
SRC_DIR			= src/
SRC_MAIN_DIR	= $(SRC_DIR)main/
SRC_UTILS_DIR	= $(SRC_DIR)utils/
OBJ_DIR			= $(SRC_DIR)obj/
INC_DIR			= inc/

# Libft
LIBFT_DIR		= libft/
LIBFT_INC		= $(LIBFT_DIR)inc/
LIBFT_A			= $(LIBFT_DIR)libft.a

# Source files
SRC_MAIN	= main.c

SRC_UTILS	= utils.c

SRCS		= $(addprefix $(SRC_MAIN_DIR), $(SRC_MAIN)) \
			  $(addprefix $(SRC_UTILS_DIR), $(SRC_UTILS))

OBJS 		= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

# Compiler
CC			= cc
CFLAGS		= -Wall -Werror -Wextra -I$(INC_DIR) -I$(LIBFT_INC) -MMD -MP
RM			= rm -rf

MAKEFLAGS	+= --no-print-directory

# ------------------------- #
#         TARGETS           #
# ------------------------- #

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	@echo -n "$(CYAN)Linking $(NAME)... $(DEF_COLOR)"
	@$(CC) $(OBJS) $(LIBFT_A) -o $(NAME)
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

.PHONY: all clean fclean re
