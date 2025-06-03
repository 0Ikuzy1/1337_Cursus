/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozouine <ozouine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:44:58 by ozouine           #+#    #+#             */
/*   Updated: 2025/06/04 00:01:25 by ozouine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <mlx.h>

# define MAX_WIDTH 800
# define MAX_HEIGHT 600
# define PI 3.14159265359
# define PLAYER_SIZE 0.25
# define FOV_SCALE 1
# define STEP 0.3
# define ANGLE_STEP 5
# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3

typedef struct s_vector
{
	double		x;
	double		y;
}				t_vector;

typedef struct s_map
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			no_set;
	int			so_set;
	int			we_set;
	int			ea_set;
	int			c;
	int			f;
	int			**map_arr;
	int			rows;
	int			cols;
}				t_map;

typedef struct s_image
{
	void		*img_ptr;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_image;

typedef struct s_texture
{
	t_image		img;
	int			height;
	int			width;
}				t_texture;

typedef struct s_line
{
	float		x;
	float		y;
	int			dx;
	int			dy;
	int			steps;
	float		x_increment;
	float		y_increment;
}				t_line;

typedef struct s_raycasting
{
	t_vector	ray_dir;
	t_vector	ray_step_size;
	t_vector	curr_map_pos;
	t_vector	ray_length_1d;
	t_vector	step;
	double		distance;
	int			side;
}				t_raycasting;

typedef struct s_wall
{
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			color;
	double		wall_x;
	int			tex_x;
	double		step;
	double		tex_pos;
	int			tex_y;
}				t_wall;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_image		image;
	t_map		map;
	t_vector	player_pos;
	t_vector	player_dir;
	t_vector	init_pdir;
	int			angle;
	t_vector	camera;
	t_vector	camera_plane;
	bool		render;
	t_texture	textures[4];
}				t_data;

int				plant_pixel(t_image *image, int x, int y, int color);
void			draw_line(t_data *cub3d, t_vector start, t_vector end,
					int color);
void			reset_screen(t_data *cub3d);
int				get_color(int r, int g, int b);
t_vector		vector_multiply(t_vector vec, double scalar);
t_vector		vector_rotate(t_vector vec, double angle);
t_vector		vector_add(t_vector v1, t_vector v2);
double			degrees_to_radians(double degrees);
void			get_texture_pixel(t_texture *texture, int x, int y, int *color);
void			load_texture(t_data *cub3d, t_texture *texture, char *path);
void			raycasting(t_data *cub3d);
void			step_x(t_raycasting *ray_vars);
void			step_y(t_raycasting *ray_vars);
void			paint_wall(t_data *cub3d, int x, t_raycasting ray_vars,
					t_wall wall_vars);
int				handle_events(int keysym, t_data *cub3d);
int				close_window(t_data *cub3d);
void			exit_cube(t_data *cub3d, int exit_code, char *exit_message);
int				check_collision(t_data *cub3d);
void			move_player(t_data *cub3d, int keysym);
void			player_movement(t_data *cub3d, int keysym);
void			update_direction(t_data *cub3d);
void			rotate_player(t_data *cub3d, int direction);
int				validate_rgb(char **split);
int				parse_color(char *str);
char			*parse_texture_path(char *line);
int				parse_and_validate_element(char *line, t_data *cub3d);
int				process_element_line(char *line, t_data *cub3d);
int				flood_fill(char **map, int max_rows, int row, int col);
int				validate_map_flood_fill(char **clean_map, int rows,
					int player_pos[2]);
int				is_valid_map_char(char c);
int				check_map_characters(char **map, int rows, int player_pos[2]);
int				validate_map(char **map, int rows, int cols);
void			free_clean_map(char **clean_map, int rows);
char			**create_clean_map(char **map, int rows);
int				fill_int_map(t_data *cub3d, char **charMap, int i);
void			set_player_direction(t_data *cub3d, char dir);
int				create_int_map(t_data *cub3d, char **charMap);
void			get_map_dimensions(char **map, int *rows, int *cols);
int				is_map_element(char *line);
int				count_map_lines(int fd, int *map_line_count);
int				read_map_line(char *line, int *in_map, char **map_lines,
					t_data *cub3d);
int				read_map_elements(int fd, char **map_lines, t_data *cub3d);
char			**allocate_map_lines(int map_line_count, t_data *cub3d);
int				validate_required_elements(t_data *cub3d, char **map_lines);
int				process_map_data(t_data *cub3d, char **map_lines);
void			cleanup_map_lines(char **map_lines);
int				parse_map(t_data *cub3d, char *file_path);
int				is_map_surrounded(t_map *d);

#endif