/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdaniely <kdaniely@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 19:54:02 by kdaniely          #+#    #+#             */
/*   Updated: 2024/04/12 19:06:32 by kdaniely         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UI_H
# define UI_H

/* Here we define user interface specific things, including user events. */

# include "defines.h"

typedef struct s_image	t_image;
typedef struct s_ui		t_ui;

struct s_image
{
	void	*mlx_image;
	int		*data;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
};

struct s_ui
{
	int		info_shift_u;
	int		info_shift_v;
	t_image	background;
	t_image	preview;
	t_image	info;
};

void	init_ui(t_control *ctl);

int		on_destroy(t_control *ctl);
int		on_keypress(int key, t_control *ctl);

enum e_event
{
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17,
	NAE = 7
};

/* Platform Specific Code*/
# ifdef __APPLE__

typedef enum e_keycode
{
	W = 13,
	A = 0,
	S = 1,
	D = 2,
	ESC = 53,
	UP = 126,
	DOWN = 125,
	RIGHT = 124,
	LEFT = 123
}	t_code;

# elif __linux__

typedef enum e_keycode
{
	W = 119,
	A = 97,
	S = 115,
	D = 100,
	ESC = 65307,
	UP = 65362,
	DOWN = 65364,
	RIGHT = 65363,
	LEFT = 65361
}	t_code;
# endif

#endif
