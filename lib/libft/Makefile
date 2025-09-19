# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timmi <timmi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/06 14:43:16 by timmi             #+#    #+#              #
#    Updated: 2025/09/19 16:22:24 by timmi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKEFLAGS += --no-print-directory

CC = cc

CFLAGS = -Wall -Werror -Wextra

CFILES = ft_atoi.c\
		 ft_bzero.c\
		 ft_calloc.c\
		 ft_isalnum.c\
		 ft_isalpha.c\
		 ft_isascii.c\
		 ft_isdigit.c\
		 ft_isprint.c\
		 ft_isspace.c\
		 ft_itoa.c\
		 ft_memchr.c\
		 ft_memcmp.c\
		 ft_memcpy.c\
		 ft_memmove.c\
		 ft_memset.c\
		 ft_putchar_fd.c\
		 ft_putendl_fd.c\
		 ft_putnbr_fd.c\
		 ft_putstr_fd.c\
		 ft_split.c\
		 ft_strchr.c\
		 ft_strdup.c\
		 ft_striteri.c\
		 ft_strjoin.c\
		 ft_strlcat.c\
		 ft_strlcpy.c\
		 ft_strlen.c\
		 ft_strmapi.c\
		 ft_strncmp.c\
		 ft_strnstr.c\
		 ft_strrchr.c\
		 ft_strtrim.c\
		 ft_substr.c\
		 ft_tolower.c\
		 ft_toupper.c\
		 w_free.c\
		 w_close.c\
		 get_next_line.c\

OFILES = $(CFILES:.c=.o)

NAME = libft.a

all: $(NAME)

$(NAME): $(OFILES)
	@ar rcs $(NAME) $(OFILES)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -f $(OFILES)

fclean: clean
	@rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re