NAME = fractol

CFLAGS = -Wall -Werror -Wextra -fsanitize=address

SRCS = check_errors.c fractals_utilis.c fractol_main.c julia.c libft_utils.c mandelbrot.c burning_ship.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(SRCS)
		cc $(CFLAGS)  -Lmlx -lmlx -framework OpenGL -framework AppKit $(SRCS) -o $(NAME)

clean :
		@rm -rf $(OBJS)

fclean : clean
		@rm -rf $(NAME)

re :	fclean all
