NAME			= libasm.a

HEADER			= libasm.h

SRCS 			= srcs/ft_strlen.s srcs/ft_strcpy.s

OBJS 			= $(SRCS:.s=.o)

.s.o:	
		$(ASM) $(ASM_FLAGS) $< -o ${<:.s=.o}
		@echo "Compilation : "$< "\033[32mok\033[0m"

H_FILES		= libasm.h

ASM			= nasm

CC			= clang

ASM_FLAGS	= -f elf64

FLAGS 		= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS) $(HEADER)

test: main.c $(NAME)
	$(CC) $(FLAGS) main.c -o test -L. -lasm
	@echo "création de Cub3D : \033[32mok\033[0m"

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)
	$(RM) test

re: fclean all
