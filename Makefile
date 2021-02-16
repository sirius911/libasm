# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: clorin <clorin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/03 09:58:07 by clorin            #+#    #+#              #
#    Updated: 2021/02/03 09:58:11 by clorin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libasm.a

HEADER			= includes/libasm.h

HEADER_BONUS	= includes/libasm_bonus.h

SRCS 			= srcs/ft_strlen.s srcs/ft_strcpy.s srcs/ft_strcmp.s srcs/ft_strdup.s \
				  srcs/ft_read.s srcs/ft_write.s

SRCS_BONUS		=srcs/ft_list_size_bonus.s srcs/ft_list_push_front_bonus.s srcs/ft_list_sort_bonus.s \
				srcs/ft_list_remove_if_bonus.s srcs/ft_atoi_base_bonus.s
	
OBJS 			= $(SRCS:.s=.o)

OBJS_BONUS 		= $(SRCS_BONUS:.s=.o)

.s.o:	
		@$(ASM) $(ASM_FLAGS) $< -o ${<:.s=.o}
		@echo "Compilation : "$< "\033[32mok\033[0m"

ASM			= nasm

CC			= clang

ASM_FLAGS	= -f elf64 -g -F dwarf

FLAGS 		= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS) $(HEADER)

bonus:	$(OBJS) $(OBJS_BONUS)
	ar -rcs $(NAME) $(OBJS) $(OBJS_BONUS) $(HEADER_BONUS)

test: tests/main.c $(NAME) $(OBJS)
	@$(CC) $(FLAGS) tests/main.c -o test -L. -lasm -I includes/libasm.h
	@echo "création de test sans bonus: \033[32mok\033[0m"

test_bonus: tests/main_bonus.c $(NAME) $(OBJS) $(OBJS_BONUS)
	@$(CC) $(FLAGS) tests/main_bonus.c -o test -L. -lasm -I includes/libasm_bonus.h
	@echo "création de test avec bonus : \033[32mok\033[0m"
clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)
	$(RM) test

re: fclean all
