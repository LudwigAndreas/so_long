#ifndef GAME_H
# define GAME_H

# include "../minilibx_opengl/mlx.h"
# include "../libft/libft.h"
# include "map.h"

# define SIZE 32
# define LOGO_SIZE 80

/*Структура для описания позиции*/
typedef struct	s_pos
{
	int	x;
	int	y;
}				t_pos;

/*Структура для хранения листов спрайтов сущностей*/
typedef struct	s_en_sprites
{
	t_list	*up;
	t_list	*down;
	t_list	*right;
	t_list	*left;
	t_list	*panic;
}				t_en_sprites;

/*Структура содержащая спрайты игры*/
typedef struct	s_sprites
{
	void		*logo;
	void		*wall;
	void		*exit;
	void		*empty;
//	t_font		*font;
}				t_sprites;

/*Структура содержащая данные о доступном направлении:
 * (N)orth, (S)outh, (E)ast, (W)est.*/
typedef struct	s_legal_act
{
	int	N;
	int	S;
	int E;
	int	W;
}				t_legal_act;

/*Структура хранения данных об объекте*/
typedef struct	s_entity
{
	t_pos			pos;
	t_pos			to_go;
	int				dir;
	int				move;
	t_en_sprites	sprite;
	t_legal_act		legal;
	struct s_entity	*next;
}				t_entity;

/*Структура содержащая всю информацию об игре*/
typedef struct	s_game
{
	int			width;
	int			length;
	void		*mlx_id;
	void		*window;
	t_params	*params;
	char		**map;
	t_sprites	*sprites;
	t_entity 	*pac;
	t_entity 	*gh;
	int 		*dir;
	int			all_coins;
	int 		dead_ind;
	int			panic_ind;
	int			frames;
	int			moves;
	int			redraw;
	int			g_rate; // ???
}				t_game;

void	init_game(t_params *params, char **map);
char	**ft_duplicate_matrix(char **map);

#endif
