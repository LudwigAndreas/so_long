PROJ_NAME		:= so_long
NAME			:= $(addprefix $(MAIN_DIR), $(PROJ_NAME))
CFLAGS			:= -Wall -Wextra -Werror -c
OFLAGS			:= -Wall -Wextra -Werror -o
SRC_DIR			:= source/
OBJ_DIR			:= objects/so_long_objs/
SRCS_FILES		:=	map_checker.c\
					map_validator.c\
					init_game.c\
					main.c\
					utils.c\
					sprites.c\
					play.c\
					redraw.c\
					entities.c\
					ft_go_dir.c\
					load_dir.c\
					score.c\
					enemies.c\
					en_behavior.c\
					move.c

OBJS_FILES		:= $(SRCS_FILES:.c=.o)
SRCS			:= $(addprefix $(SRC_DIR), $(SRCS_FILES))
OBJS			:= $(addprefix $(OBJ_DIR), $(OBJS_FILES))
RM				:= rm -rf
LIBFTDIR_PATH	:= libft/
LIBFT			:= $(addprefix $(LIBFTDIR_PATH), libft.a)
HEADER			:= includes/map.h includes/game.h
MINILIBX		:= mlx/
LMLX			:= -Lmlx -lmlx -framework OpenGL -framework AppKit

all: objects $(NAME)

objects:
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	gcc -Imlx $(CFLAGS) $< -o $@

$(NAME): $(OBJS) $(HEADER)
	make -C $(LIBFTDIR_PATH)
	make -C $(MINILIBX)
#	gcc $(OBJS) $(LIBFTDIR_PATH)libft.a -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	gcc $(OBJS) $(LIBFTDIR_PATH)libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)


play: all
	./$(NAME) resources/maps/valid_maps/zero_map.ber
	./$(NAME) resources/maps/valid_maps/line_map.ber
	./$(NAME) resources/maps/valid_maps/minimal_map.ber
	./$(NAME) resources/maps/valid_maps/big_map.ber
	./$(NAME) resources/maps/valid_maps/pacman_mini_map.ber
	./$(NAME) resources/maps/valid_maps/simple_valid_map.ber
	./$(NAME) resources/maps/valid_maps/full_map.ber
	./$(NAME) resources/maps/valid_maps/google_map.ber
	./$(NAME) resources/maps/valid_maps/pacman_origin_map.ber
	./$(NAME) resources/maps/valid_maps/full1_map.ber

clean:
	make clean -C $(LIBFTDIR_PATH)
	rm -rf objects/

fclean: clean
	make fclean -C $(LIBFTDIR_PATH)
	make clean -C mlx
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
