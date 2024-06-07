/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:08:59 by kdaniely          #+#    #+#             */
/*   Updated: 2024/06/07 14:14:26 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <libft.h>
# include <ft_printf.h>
# include <mlx.h>
# include <stdio.h>
# include <math.h>

# include "defines.h"
# include "camera.h"
# include "ui.h"
# include "shapes.h"

/* Type definitions */
typedef struct s_control	t_control;
typedef struct s_thread		t_thread;
typedef struct s_job		t_job;

/* Multithreading */
struct s_task
{
	t_point2	from;
	t_point2	to;
};

struct s_thread
{
	int			id;
	pthread_t	*thread;
	t_control	*ctl;
};

struct s_job
{
	bool		busy;
	t_point2	from;
	t_point2	to;
	t_compute	shader;
};

/* The control structure */
struct s_control
{
	void			*mlx_ptr;
	void			*win_ptr;
	int				win_u;
	int				win_v;
	int				worker_c;
	pthread_mutex_t	qmux;
	t_list			*job_q;
	t_thread		*pool;
	t_camera		cam;
	t_darray		world;
	t_darray		lights;
	t_image			render;
	t_image			light_icon;
};

/* Program logic functions. */
void		init_ui(t_control *ctl);

bool		scan(t_control *ctl, char *filename);

void		run(t_control *ctl);

/* Shaders */

t_color		map(uint32_t color);

t_point2	compute_sphere_uv(t_hitrecord *hr);

t_color		ray_shader(t_control *ctl, t_ray *r, int bounce);

t_color		ambient_shader(t_control *ctl, t_hitrecord *hr);

t_color		blinn_phong_shader(t_control *ctl, t_hitrecord *hr);

t_color		skybox_shader(t_control *ctl, t_ray *ray);

t_color		color_shader(t_control *ctl, t_hitrecord *hr);

t_color		linear_to_gamma(t_color c);

/* Utils */
uint64_t	get_time(bool to_init);

void		put_render(t_control *ctl);
void		print_bar(t_control *ctl, int done);
void		fill_image(t_image *image, int color);

void		raster_light_sources(t_control *ctl);

/* Utility Functions */

void		create_image(char *name, int *pixels, int w, int h);
void		new_image(void *mlx_ptr, int width, int height, t_image *image);
double		ft_map(double num);

/* Floating point operations */

bool		float_equal(float a, float b);

float		clamp(float value, float min, float max);
double		clamp_d(double value, double min, double max);

/* Get the pixel in position [i,j]. */
static inline int	*get_pixel(t_control *ctl, int i, int j)
{
	return ((ctl->render.data + i * ctl->render.width) + j);
}
#endif
