# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: iidzim <iidzim@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/21 20:36:50 by iidzim            #+#    #+#              #
#    Updated: 2021/01/18 15:04:06 by iidzim           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

SRC =	bmp.c cast.c collect_data.c color.c free.c main.c\
		get_next_line.c get_next_line_utils.c utils.c utils2.c\
		init_struct.c keys.c map_error.c player_sprite.c\
		read_file.c resize_map.c split.c sprite.c texture.c walls.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit -g 

all: $(NAME)

$(OBJ): $(SRC)
	gcc -c $(SRC)

$(NAME): $(OBJ)
	gcc $(OBJ) $(FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
