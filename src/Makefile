# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 20:36:50 by iidzim            #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2021/01/16 17:46:05 by iidzim           ###   ########.fr        #
=======
#    Updated: 2021/01/14 19:38:36 by iidzim           ###   ########.fr        #
>>>>>>> c272cd0d3117a81cf40e9c4b649cd7647f17fdeb
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC =	bmp.c cast.c collect_data.c color.c free.c\
		get_next_line.c get_next_line_utils.c\
		init_struct.c keys.c map_error.c player.c\
		read_file.c resize_map.c split.c\
		sprite.c sprite2.c texture.c walls.c\
		utils.c utils2.c main.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
<<<<<<< HEAD
	gcc *.c -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -g -fsanitize=address  -o $(NAME)
=======
	gcc *.c -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -g -fsanitize=address -o $(NAME)
>>>>>>> c272cd0d3117a81cf40e9c4b649cd7647f17fdeb

run:
	./$(NAME) map4.cub
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -f $(NAME)
re:
	fclean all	
