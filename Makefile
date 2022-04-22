PROJ_NAME		:= so_long
MAIN_DIR		:=
NAME			:= $(addprefix $(MAIN_DIR), $(PROJ_NAME))
CFLAGS			:= -Wall -Wextra -Werror -c
OFLAGS			:= -Wall -Wextra -Werror -o
SRC_DIR			:= source/
OBJ_DIR			:= objects/so_long_objs/
SRCS_FILES		:=	map_checker.c\
					get_next_line.c\
					get_next_line_utils.c\
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
					en_behavior.c
OBJS_FILES		:= $(SRCS_FILES:.c=.o)
SRCS			:= $(addprefix $(SRC_DIR), $(SRCS_FILES))
OBJS			:= $(addprefix $(OBJ_DIR), $(OBJS_FILES))
RM				:= rm -rf
LIBFTDIR_PATH	:= libft/
LIBFT			:= $(addprefix $(LIBFTDIR_PATH), libft.a)
HEADER			:= includes/map.h includes/game.h
MAP_DIR			:= resources/maps/
MAPS_FILES		:= 	wrong_extension.txt\
					empty_map.ber\
					simple_valid_map.ber
MAPS			:= $(addprefix $(MAP_DIR), $(MAPS_FILES))
EXEC			:= $(addprefix ./, $(NAME))
MINILIBX		:= mlx/
LMLX			:= -lmlx -framework OpenGL -framework AppKit

all: obj $(NAME)

obj: $(SRCS)
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	gcc -Imlx $(CFLAGS) $< -o $@

$(NAME): $(OBJS) $(HEADER)
	make -C $(LIBFTDIR_PATH)
	make -C $(MINILIBX)
	gcc $(OBJS) $(LIBFTDIR_PATH)libft.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

play: all $(MAPS)

$(MAPS):
	$(EXEC) $?

clean:
	make clean -C $(LIBFTDIR_PATH)
	rm -rf $(OBJ_DIR)

fclean: clean
	make fclean -C $(LIBFTDIR_PATH)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
