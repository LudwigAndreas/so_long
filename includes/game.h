/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsherry <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 18:31:24 by lsherry           #+#    #+#             */
/*   Updated: 2022/04/29 18:31:26 by lsherry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "map.h"

/*Game sprites sizes*/
# define SIZE 48
# define LOGO_W 256
# define LOGO_L 64
# define SCORE_W 192

/*Rate of game animations*/
# define GAME_RATE 5

/* Variations of enemies:
 * (O)rc, (n)ecromancer, (s)lime, (K)ing_goblin, (G)host */
# define ENEMIES "ONSKG"

enum e_keys
{
	W_KEY = 13,
	A_KEY = 0,
	S_KEY = 1,
	D_KEY = 2,
	ESC_KEY = 53,
	UP_KEY = 126,
	LEFT_KEY = 123,
	DOWN_KEY = 125,
	RIGHT_KEY = 124,
};

enum e_direction
{
	ST = 0,
	N = 1,
	S = -1,
	E = -2,
	W = 2
};

/*Структура для описания позиции*/
typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

/*Структура для хранения листов спрайтов сущностей*/
typedef struct s_en_sprites
{
	t_list	*up;
	t_list	*st_up;
	t_list	*down;
	t_list	*st_down;
	t_list	*right;
	t_list	*st_right;
	t_list	*left;
	t_list	*st_left;
	t_list	*st;
}				t_en_sprites;

typedef struct s_font
{
	void	*zero;
	void	*one;
	void	*two;
	void	*three;
	void	*four;
	void	*five;
	void	*six;
	void	*seven;
	void	*eight;
	void	*nine;
}				t_font;

/*Структура содержащая спрайты игры*/
typedef struct s_sprites
{
	void			*logo;
	void			*score;
	void			*wall;
	void			*exit;
	void			*open_ex;
	void			*empty;
	void			*hero;
	void			*coin;
	t_list			*death_r;
	t_list			*death_l;
	t_list			*death_st_r;
	t_list			*death_st_l;
	t_font			font;
}					t_sprites;

/*Структура содержащая данные о доступном направлении:
 * (n)orth, (s)outh, (e)ast, (w)est.*/
typedef struct s_legal_act
{
	int	n;
	int	s;
	int	e;
	int	w;
}				t_legal_act;

/*Структура хранения данных об объекте*/
typedef struct s_entity
{
	t_pos			pos;
	t_pos			w_pos;
	int				dir;
	int				prev_dir;
	int				move;
	t_en_sprites	sprite;
	t_legal_act		legal;
	struct s_entity	*next;
}				t_entity;

/*Структура содержащая всю информацию об игре*/
typedef struct s_game
{
	int			width;
	int			length;
	void		*mlx_id;
	void		*window;
	t_params	*params;
	char		**map;
	t_sprites	sprites;
	t_entity	*heroes;
	t_entity	*enemies;
	int			next_dir;
	int			all_coins;
	int			dead_ind;
	int			frames;
	int			moves;
	int			redraw;
	int			g_rate;
}				t_game;

/* Initialize game start settings */
void		init_game(t_params *params, char **map);
/* Initialize sprites xmp */
t_sprites	init_sprites(t_game *game);
/* Update frame or part of frame */
int			ft_update(t_game *game);
/* Освобождает спрайты */
void		free_sprites(t_game *game);
/* render not animated parts */
void		ft_render_map(t_game *game, int x, int y);
/* Выход из игры с освобождением всей памяти */
int			close_game(t_game *game);
void	ft_free_en_list(t_game *game);
/**/
void		next_direct(t_game *game, int key);
/* Определяет, можно ли пойти в конкретном направлении */
int			ft_is_mov_legal(t_entity *entity, int dir);
/* Определение возможного направления движения */
void		ft_update_legal_act(t_game *game, t_entity *en);
/* Движение врага */
void		ft_move_en(int dir, t_entity *entity, t_game *g);
/* Функция определяет направление врагов */
void		ft_update_en(t_game *game);
/* Создание координате x, y */
t_pos		ft_new_pos(int x, int y);
/* Добавляет существ в linked-list */
void		ft_add_entities(t_game *game);
/* Отрисовка героя на экране */
void		ft_put_hero(t_game *game);
/* Выводит на экран врага */
void		ft_put_enemies(t_game *game);
/* Переопределяет изображение врага на экране */
void		ft_redraw_enemies(t_game *game);
/* Попиксельное перемещение героя по экрану */
void		ft_redraw_hero(t_game *game);
/* Проверяет возможно ли движение в направлении и передвигает сущность */
void		ft_next_dir(t_game *game);
/* Выгружает смерть */
t_list		*load_death_l(t_game *game);
/* Выгружает смерть */
t_list		*load_death_r(t_game *game);
/* Выгружает анимацию движения в стороны */
t_list		*ft_load_south(t_game *game, char *path, int mode);
t_list		*ft_load_west(t_game *game, char *path, int mode);
t_list		*ft_load_north(t_game *game, char *path, int mode);
t_list		*ft_load_east(t_game *game, char *path, int mode);
/* Загрузка всех анимаций героя */
void		ft_load_hero(t_game *game);
/* Загрузка всех анимаций врагов */
void		ft_load_enemies(t_game *game);
/* Открытие дверей */
void		ft_open_doors(t_game *game);
/* Определяет следующее направление движения */
void		next_direct(t_game *game, int dir);
/* Счетчик на экране и в консоли */
void		ft_update_score(t_game *game);
/* Высчитывает евклидово расстояние между двумя координатами */
int			evclid(t_pos p1, t_pos p2);
/* Функция определения нужного спрайта для передвижения в сторону */
void		ft_go_west(t_game *game, t_entity *entity);
void		ft_go_south(t_game *game, t_entity *entity);
void		ft_go_east(t_game *game, t_entity *entity);
void		ft_go_north(t_game *game, t_entity *entity);
/* Определяет, есть ли враг на координатах */
int			ft_is_there_en(t_game *game, int x, int y);

#endif
