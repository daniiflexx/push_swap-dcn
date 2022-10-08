NAME = push_swap
LIBFT = libft/libft.a
SRCS = src/push_swap.c src/libstack.c src/algorithms.c src/libstack2.c src/libstack3.c
OBJS = $(patsubst src/%, obj/%, $(SRCS:.c=.o))
############################
$(NAME): $(OBJS) $(LIBFT)
	gcc -g $^ -o $@ -Llibft -lft 

$(LIBFT): 
	make bonus -C libft

all: $(NAME)

obj/%.o: src/%.c
	gcc -c -g $< -o $@ -Ilibft -Iinclude

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)
	make fclean -C libft

re: fclean $(NAME)