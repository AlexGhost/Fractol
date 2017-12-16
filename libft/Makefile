# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acourtin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 10:27:54 by acourtin          #+#    #+#              #
#    Updated: 2017/12/11 11:07:17 by acourtin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CCFLAGS = -Wall -Wextra -Werror
SRC.C = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_isspace.c ft_islower.c ft_isupper.c \
		ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memccpy.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c \
		ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c \
		ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
		ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
		ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
		ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
		ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
		ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c \
		ft_strtrim.c ft_tolower.c ft_toupper.c ft_lstnew.c ft_lstdel.c \
		ft_lstdelone.c ft_lstadd.c ft_lsttail.c ft_lstiter.c ft_lstmap.c \
		ft_lstsize.c ft_lstat.c ft_lstrev.c ft_lstlast.c ft_strnjoin.c \
		get_next_line.c ft_abs.c

SRC.O 		= 	$(SRC.C:.c=.o)

all: $(NAME)

$(NAME): $(SRC.O)
	@ar rc $(NAME) $(SRC.O)
	@ranlib $(NAME)
	@printf "\r\033[K"
	@echo "\033[33m/------------------------------------\ \\033[0m"
	@echo "\033[33m|----------- $(NAME) crée -----------| \\033[0m"
	@echo "\033[33m\------------------------------------/ \\033[0m"

%.o: %.c
	@$(CC) $(CCFLAGS) -o $@ -c $< -Iincludes
	@printf "\r\033[K""\033[36m - Compilation de \033[0m$<\033[0m"

clean:
	@rm -rf $(SRC.O)
	@echo "\033[31mSuppression - objs\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[31mSuppression - $(NAME)\033[0m"

re: fclean $(NAME)
