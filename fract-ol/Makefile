# 

NAME= fract-ol
CFILES= main.c 
OBJ = $(CFILES:.c=.o)
CFLAGS = -Wall -Wextra -Werror 
CC = gcc
all = $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ 

#generating the compile files 
$(NAME): $(OBJ)
	$(CC) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean: 
	rm -rf $(NAME) $(OBJ)
fclean: clean 
	rm -rf $(NAME)
	
re: clean all 	
