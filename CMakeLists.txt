cmake_minimum_required(VERSION 3.21)
project(so_long C)

set(CMAKE_C_STANDARD 99)

add_executable(so_long source/map_checker.c source/map_validator.c
        source/init_game.c source/main.c source/utils.c source/sprites.c source/play.c source/redraw.c source/entities.c
        source/ft_go_dir.c source/load_dir.c source/score.c source/enemies.c source/en_behavior.c)

target_link_libraries(so_long /Users/lsherry/42Course/so_long/mlx/libmlx.a "-framework OpenGL" "-framework AppKit")
target_link_libraries(so_long /Users/lsherry/42Course/so_long/libft/libft.a)