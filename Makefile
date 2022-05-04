##
## EPITECH PROJECT, 2021
## my_ls
## File description:
## Makefile
##

SRC =	ls_standard.c	\
		ls_l.c	\
		ls_upper_r.c	\
		sort.c	\
		free_info_file.c	\
		get_info.c	\
		get_info_folder.c	\
		get_info_a.c	\
		find_options.c

MAIN =	main.c

NAME =	my_ls

all:    $(NAME)

$(NAME):
	make -C ./lib/my/
	gcc -Wall -Wextra -o $(NAME) $(SRC) $(MAIN) -g -Iinclude -Llib/my/ -lmy

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
