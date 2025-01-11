# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 13:10:24 by aryamamo          #+#    #+#              #
#    Updated: 2025/01/11 17:02:15 by aryamamo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = srcs/pipex.c\
	srcs/utils.c

NAME = pipex

CC = cc
CFLAGS = -Wall -Werror -Wextra

VALGRIND    := valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes -q


LIBFTDIR = ./libft_v2

LIBFT = $(LIBFTDIR)/libft.a

OBJS = $(SRCS:.c=.o)

all: $(NAME)


%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

$(LIBFT):
	make -C $(LIBFTDIR)


clean:
	rm -f $(OBJS)
	make -C $(LIBFTDIR) clean

run: $(NAME)
	@./$(NAME) "infile" "cat" "cat" "test-xx.txt"
	cat test-xx.txt

val: $(NAME)
	$(VALGRIND) ./$(NAME) "infile" "ls -l" "grep Make" "outfile"
	cat outfile


fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

re: fclean all
