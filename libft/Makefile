# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: didguill <didguill@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/03 14:09:04 by didguill          #+#    #+#              #
#    Updated: 2025/07/28 18:00:34 by didguill         ###   ########.fr        #
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
#      DIRECTORY PATHS      #
# ------------------------- #
NAME 				= libft.a

SRCS_DIR			= src/
LIBFT_DIR			= $(SRCS_DIR)libft/
FT_PRINTF_DIR		= $(SRCS_DIR)ft_printf/
OBJ_DIR				= $(SRCS_DIR)obj/

# ------------------------- #
#       SOURCE FILES        #
# ------------------------- #
SRCS_LIBFT		= ft_atoi.c ft_isdigit.c ft_memmove.c ft_split.c ft_strlcpy.c ft_strtrim.c \
				ft_bzero.c ft_isprint.c ft_memset.c ft_strchr.c ft_strlen.c ft_substr.c \
				ft_calloc.c ft_itoa.c ft_putchar_fd.c ft_strdup.c ft_strmapi.c \
				ft_tolower.c ft_isalnum.c ft_memchr.c ft_putendl_fd.c ft_striteri.c \
				ft_strncmp.c ft_toupper.c ft_isalpha.c ft_memcmp.c ft_putnbr_fd.c \
				ft_strjoin.c ft_strnstr.c ft_isascii.c ft_memcpy.c ft_putstr_fd.c \
				ft_lstadd_back_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
				ft_lstsize_bonus.c ft_lstadd_front_bonus.c ft_lstdelone_bonus.c ft_lstlast_bonus.c \
				ft_lstnew_bonus.c ft_strlcat.c ft_strrchr.c

SRCS_PRINTF		= format_handler_bonus.c formatted_letters_printer_bonus.c ft_printf_bonus.c \
				put_utils_bonus.c format_parser_bonus.c formatted_numbers_printer_bonus.c \
				miscellaneous_utils_bonus.c structs_utils_bonus.c

SRC_FILES		= $(addprefix $(LIBFT_DIR), $(SRCS_LIBFT)) \
				  $(addprefix $(FT_PRINTF_DIR), $(SRCS_PRINTF))

OBJ_FILES		= $(patsubst $(SRCS_DIR)%.c, $(OBJ_DIR)%.o, $(SRC_FILES))

# ------------------------- #
#       COMPILER FLAGS      #
# ------------------------- #
CC 			= cc
CFLAGS		= -Wall -Wextra -Werror -I ./inc/ -MMD -MP
RM			= rm -rf
AR			= ar rcs

MAKEFLAGS	+= --no-print-directory

# ------------------------- #
#         TARGETS           #
# ------------------------- #
all: $(NAME)

$(NAME): $(OBJ_FILES)
	@echo -n "$(CYAN)Creating $(NAME)... $(DEF_COLOR)"
	@$(AR) $(NAME) $(OBJ_FILES)
	@echo "$(GREEN)Done!$(DEF_COLOR)"
	@echo "$(GREEN)(o_o) $(RED)$(NAME) $(GREEN)generated!\n$(DEF_COLOR)"

# Patter rule with mkdir fallback
$(OBJ_DIR)%.o: $(SRCS_DIR)%.c
	@echo "$(MAGENTA)Compiling:$(YELLOW) $< ...$(DEF_COLOR)"
	@mkdir -p $(dir $@)
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

-include $(OBJ_FILES:.o=.d)

.PHONY: all clean fclean re
