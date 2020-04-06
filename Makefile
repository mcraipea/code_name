CC = gcc

NAME = code_name

SRC = 	main.c   \
		ft_joueur.c	\
		ft_utils.c \
		ft_mail.c \
		ft_jeu.c

OBJ = $(SRC:.c=.o)

CFLAGS = `pkg-config --cflags --libs gtk+-2.0` -GDK_DISABLE_DEPRECATION_WARNINGS

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) -o $@ $(OBJ) $(CFLAGS)

clean: 
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all