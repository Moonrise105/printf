# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ctobias <ctobias@student.21.ru>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/25 16:07:08 by ctobias           #+#    #+#              #
#    Updated: 2020/07/28 00:37:40 by ctobias          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS_DIR = ./
OBJS_DIR = ./
DEPS_DIR = ./
INC_DIR = ./

SRCS = 	ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memccpy.c\
		ft_memmove.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strlen.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strnstr.c\
		ft_strncmp.c\
		ft_atoi.c\
		ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c \
		ft_strnew.c

SRCS_BONUS =	ft_lstnew.c\
				ft_lstadd_front.c\
				ft_lstsize.c\
				ft_lstlast.c\
				ft_lstadd_back.c\
				ft_lstdelone.c\
				ft_lstclear.c\
				ft_lstiter.c\
				ft_lstmap.c

OBJS = $(addprefix $(OBJS_DIR), $(SRCS:.c=.o))
OBJS_BONUS = $(addprefix $(OBJS_DIR), $(SRCS_BONUS:.c=.o))

DEPS = $(addprefix $(DEPS_DIR), $(SRCS:.c=.d))
DEPS_BONUS = $(addprefix $(DEPS_DIR), $(SRCS_BONUS:.c=.d))

ifdef WITH_BONUS
	RES_OBJS = $(OBJS) $(OBJS_BONUS)
else
	RES_OBJS = $(OBJS)
endif

CFLAGS = -Wall -Werror -Wextra -c -MMD

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	gcc $(CFLAGS) $< -o $@

$(NAME): $(RES_OBJS)
	ar rcs $(NAME) $(RES_OBJS)

all: $(NAME)

bonus:
	$(MAKE) WITH_BONUS=1 $(NAME)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)
	rm -f $(DEPS) $(DEPS_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all

-include $(DEPS) $(DEPS_BONUS)

.PHONY: all bonus clean fclean re