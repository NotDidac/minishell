# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: didguill <didguill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/03 14:09:04 by didguill          #+#    #+#              #
#    Updated: 2025/07/30 16:46:26 by didguill         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ------------------------- #
#         COLORS            #
# ------------------------- #
DEF_COLOR		= \033[0;39m
RED             = \033[0;91m
GREEN           = \033[0;92m
YELLOW          = \033[0;93m
MAGENTA			= \033[0;95m
CYAN            = \033[0;96m

# ------------------------- #
#        VARIABLES          #
# ------------------------- #

NAME 				= libft.a

# Directories
SRC_DIR				= src/
SRC_LIBFT_DIR		= $(SRC_DIR)libft/
SRC_FT_PRINTF_DIR	= $(SRC_DIR)ft_printf/
SRC_EXTRA_DIR		= $(SRC_DIR)extra/
OBJ_DIR				= $(SRC_DIR)obj/
INC_DIR				= inc/

# Source files
SRC_LIBFT		= ft_atoi.c ft_isdigit.c ft_memmove.c ft_split.c ft_strlcpy.c ft_strtrim.c \
				ft_bzero.c ft_isprint.c ft_memset.c ft_strchr.c ft_strlen.c ft_substr.c \
				ft_calloc.c ft_itoa.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c \
				ft_tolower.c ft_isalnum.c ft_memchr.c ft_putendl_fd.c ft_striteri.c \
				ft_strncmp.c ft_toupper.c ft_isalpha.c ft_memcmp.c ft_putnbr_fd.c \
				ft_strjoin.c ft_strnstr.c ft_isascii.c ft_memcpy.c ft_putstr_fd.c \
				ft_lstadd_back_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
				ft_lstsize_bonus.c ft_lstadd_front_bonus.c ft_lstdelone_bonus.c ft_lstlast_bonus.c \
				ft_lstnew_bonus.c ft_strlcat.c ft_strrchr.c

SRC_FT_PRINTF	= format_handler_bonus.c formatted_letters_printer_bonus.c ft_printf_bonus.c \
				put_utils_bonus.c format_parser_bonus.c formatted_numbers_printer_bonus.c \
				miscellaneous_utils_bonus.c structs_utils_bonus.c

SRC_EXTRA		= ft_isspace.c ft_strndup.c

SRCS			= $(addprefix $(SRC_LIBFT_DIR), $(SRC_LIBFT)) \
				  $(addprefix $(SRC_FT_PRINTF_DIR), $(SRC_FT_PRINTF)) \
				  $(addprefix $(SRC_EXTRA_DIR), $(SRC_EXTRA))

OBJS			= $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

# Compiler
CC 			= cc
CFLAGS		= -Wall -Wextra -Werror -I$(INC_DIR) -MMD -MP
RM			= rm -rf
AR			= ar rcs

MAKEFLAGS	+= --no-print-directory

# ------------------------- #
#         TARGETS           #
# ------------------------- #

all: $(NAME)

$(NAME): $(OBJS)
	@echo -n "$(CYAN)Creating $(NAME)... $(DEF_COLOR)"
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)Done!$(DEF_COLOR)"
	@echo "$(GREEN)(o_o) $(RED)$(NAME) $(GREEN)generated!\n$(DEF_COLOR)"

# Compile each object
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(dir $@)
	@echo "$(MAGENTA)Compiling:$(YELLOW) $< ...$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo -n "$(CYAN)Cleaning libft object files... $(DEF_COLOR)"
	@$(RM) $(OBJ_DIR)
	@echo "$(GREEN)Done!$(DEF_COLOR)"

fclean: clean
	@echo -n "$(CYAN)Removing $(NAME)... $(DEF_COLOR)"
	@$(RM) $(NAME)
	@echo "$(RED)(×_×) $(NAME) $(GREEN)removed!\n$(DEF_COLOR)"

re: fclean all

-include $(OBJS:.o=.d)

.PHONY: all clean fclean re
