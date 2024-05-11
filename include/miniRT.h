/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armhakob <armhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 19:08:59 by kdaniely          #+#    #+#             */
/*   Updated: 2024/05/11 19:33:13 by armhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <libft.h>
# include <ft_printf.h>
# include <mlx.h>
# include <stdio.h>

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
	struct s_point2	from;
	struct s_point2	to;
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
};

/* */
char		scan(t_control *ctl, char *filename);

void		init_ui(t_control *ctl);

void		run(t_control *ctl);

/* Shaders */

t_color		ray_shader(t_control *ctl, t_ray *r, int bounce);

t_color		diffuse_shader(t_control *ctl, t_hitrecord *hr);

t_color		skybox_shader(t_ray *ray);

/* Utils */
uint64_t	get_time(bool to_init);

void		put_render(t_control *ctl);
void		print_bar(t_control *ctl, int done);
void		fill_image(t_image *image, int color);

/* Utility Functions */

void		create_image(char *name, int *pixels, int w, int h);
void		new_image(void *mlx_ptr, int width, int height, t_image *image);
double		ft_map(int num);

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
