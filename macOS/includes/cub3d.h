/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allanganoun <allanganoun@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/14 20:36:56 by allanganoun       #+#    #+#             */
/*   Updated: 2021/05/10 16:01:15 by allanganoun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <mlx.h>
# include <sys/stat.h>
# include "get_next_line.h"

# define LEFT_ARR  123
# define RIGHT_ARR 124
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53
# define KEY_SHIFT 257

# define KEY_PRESS 2
# define KEY_RELEASE 3

typedef struct			s_params
{
	int					h_res;
	int					v_res;
	int					floor_r;
	int					floor_g;
	int					floor_b;
	int					ceil_r;
	int					ceil_g;
	int					ceil_b;
	char				*no_path;
	char				*so_path;
	char				*we_path;
	char				*ea_path;
	char				*sprite;
	int					save;
	int					done;
}						t_params;

typedef struct			s_map
{
	char				*premap;
	char				**map;
	int					premap_found;
	int					mapfound;
	int					mapdone;
}						t_map;

typedef struct			s_errors
{
	int					init_errors;
	int					params_malloc;
	int					map_malloc;
	int					datastruct_malloc;
	int					map_not_closed;
	int					map_invalid_char;
	int					res_col_errors;
	int					double_params;
	int					wrong_ext;
	int					keys_malloc;
	int					ray_malloc;
	int					player_malloc;
	int					window_malloc;
	int					image_malloc;
	int					player_found;
}						t_errors;

typedef struct			s_keys
{
	int					left;
	int					right;
	int					w;
	int					a;
	int					s;
	int					d;
	int					shift;
	int					esc;
}						t_keys;

typedef struct			s_player
{
	double				x;
	double				y;
	double				dir_x;
	double				dir_y;
	double				plan_x;
	double				plan_y;
	double				mov_speed;
	double				rot_speed;
	int					found;
}						t_player;

typedef struct			s_ray
{
	int					x;
	int					y;
	int					map_x;
	int					map_y;
	int					step;
	int					step_x;
	int					step_y;
	int					hit;
	int					side;
	int					line_h;
	int					draw_start;
	int					draw_end;
	int					text_x;
	int					text_y;
	double				dir_x;
	double				dir_y;
	double				side_x;
	double				side_y;
	double				delta_x;
	double				delta_y;
	double				camera_x;
	double				walldist_p;
	double				wall_x;
	double				*z_buffer;
}						t_ray;

typedef struct			s_window
{
	int					width;
	int					height;
	int					max_width;
	int					max_height;
	void				*mlx_ptr;
	void				*win_ptr;
}						t_window;

typedef struct			s_image
{
	int					bpp;
	int					size_line;
	int					endian;
	int					width;
	int					height;
	void				*img_ptr;
	char				*img_data;
	char				*path;
	int					pos;
}						t_image;

typedef struct			s_sprite
{
	int					x;
	int					y;
}						t_sprite;

typedef struct			s_sprites
{
	int					x;
	int					y;
	int					draw_start_x;
	int					draw_end_x;
	int					draw_start_y;
	int					draw_end_y;
	int					sprite_screen_x;
	int					sprite_height;
	int					sprite_width;
	int					text_x;
	int					text_y;
	double				distance;
	double				sprite_x;
	double				sprite_y;
	double				inv_det;
	double				transform_x;
	double				transform_y;
	t_sprite			*sprite;
	struct s_sprites	*next;
}						t_sprites;

typedef struct			s_all
{
	t_params			*params;
	t_map				*map_s;
	t_errors			*errors;
}						t_all;

typedef struct			s_game
{
	int					map_started;
	int					map_stopped;
	int					ccol;
	int					fcol;
	int					save;
	char				**map;
	char				*no_path;
	char				*so_path;
	char				*we_path;
	char				*ea_path;
	char				*sprite;
	t_keys				*keys;
	t_ray				*ray;
	t_player			*player;
	t_window			*window;
	t_image				*image;
	t_sprites			*sprites_begin;
	t_all				*all;
}						t_game;

/*
** ================================| Init |====================================
*/

int						overall_create(t_all **all);
int						game_create(t_game **game);
int						keys_create(t_game **game, t_all **all);
int						ray_create(t_game **game, t_all **all);
int						player_create(t_game **game, t_all **all);
int						window_create(t_game **game, t_all **all);
int						image_create(t_game **game, t_all **all);
int						params_create(t_all **all);
int						map_create(t_all **all);
int						errors_create(t_all **all);
t_sprites				*sprites_init(t_sprite *sprite, double distance);
void					image_init(t_image **image);

/*
** ================================| Utils |===================================
*/

int						ft_strlen(char *str);
int						ft_strlen_nl(char *str);
int						ft_atoi_width(char *str);
int						ft_atoi_height(char *str);
int						ft_atoi_col(char *str);
int						ft_digitnb(int nb);
int						create_bitmap(t_game *game);
void					check_whitespace(char **str);
char					*ft_strcpy(char *src, char *dest);
void					ft_bzero(void *s, size_t n);
void					*ft_calloc(size_t count, size_t size);
char					*ft_itoa_b16(int nb);
int						write_argument_errors(int option);
int						write_map_errors(int option);
int						write_missing_parameter(t_params *params);
int						write_parameters_errors(int option);
int						write_init_errors(int option);
int						write_init_errors2(int option);
int						close_window(t_game *game);

/*
** ================================| Check |===================================
*/

int						extension_checker(char *str, char *ext);
int						first_wall(char *str);
int						last_wall(char *str);
int						check_args(int argc, char **argv);
int						map_checker(t_all **all);
int						check_back_walls(char *str1, char *str2);
int						check_front_walls(char *topline, char *botline);
int						check_holes(char *topline, char *botline);
int						double_params(char *str, t_params **params);
int						check_textures(t_params *params);

/*
** ==============================| Parsing |===================================
*/

int						params_parsing(char *str, t_all **all);
int						params_checker(t_all *all);
int						ft_res_extract(char *str, t_all **all);
int						no_text_extract(char *str, t_all **all);
int						so_text_extract(char *str, t_all **all);
int						we_text_extract(char *str, t_all **all);
int						ea_text_extract(char *str, t_all **all);
int						s_text_extract(char *str, t_all **all);
void					ft_extraction(char *str, t_params **params);
int						f_col_extract(char *str, t_all **all);
int						c_col_extract(char *str, t_all **all);
int						map_extraction(char *str, t_map **map_s);
int						map_builder(t_map **map_s);

/*
** ============================| Raycasting |==================================
*/

int						wall_finder(t_game **game, t_ray **ray);
void					rendering(t_all **all);
int						params_picker(t_game **game, t_all *all);
int						raycasting(t_game **game);
void					ray_calculations(t_ray **ray, t_player *player,
						t_window *window);
void					texture_choice(t_image **text, t_game *game,
						t_ray *ray);
int						get_textures_info(t_image **text, t_window *window);
int						draw_walls(t_game **game, t_ray **ray);
void					sprite_process(t_game *game, t_ray *ray);
int						draw_sprites(t_game **game, t_window *window,
						t_ray *ray);
void					projection_sprite(t_player *player, t_window *window,
						t_sprites **current);
void					size_sprite(t_sprites **current, t_window *window);
int						player_parsing(t_all **all, t_game **game);
void					perp_height(t_ray **ray, t_player *player,
						t_window *window);
void					key_manager(t_game *game);
int						key_pressed(int key_code, t_game *game);
int						key_released(int key_code, t_game *game);
void					move_forward(char **map, t_player **player);
void					move_backward(char **map, t_player **player);
void					move_right(char **map, t_player **player);
void					move_left(char **map, t_player **player);
void					rotate_left(t_player **player);
void					rotate_right(t_player **player);

/*
** ==============================| Free |=====================================
*/

void					free_params(t_params **params);
void					free_map(t_map **map_s);
void					free_errors(t_errors **errors);
void					free_sprites_chain(t_sprites **begin);
void					free_image(t_image **image, t_window **window);
int						free_game(t_game **game);
int						free_all(t_all **all);
void					game_exit(t_game **game, t_all **all);

#endif
