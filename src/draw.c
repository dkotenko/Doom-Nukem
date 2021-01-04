/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clala <clala@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 18:21:35 by clala             #+#    #+#             */
/*   Updated: 2020/10/18 18:23:36 by clala            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		draw_line(SDL_Surface *surface,
t_point start, t_point end, int color)
{
	t_point	d;
	t_point	s;
	int		err;
	int		e2;

	d.x = abs(end.x - start.x);
	d.y = abs(end.y - start.y);
	s.x = start.x < end.x ? 1 : -1;
	s.y = start.y < end.y ? 1 : -1;
	err = (d.x > d.y ? d.x : -d.y) / 2;
	while (1)
	{
		if (start.x > W || start.x < 0 || start.y > H || start.y < 0)
			break ;
		set_pixel(surface, start.x, start.y, color);
		if (start.x == end.x && start.y == end.y)
			break ;
		e2 = err;
		err = e2 > -d.x ? err - d.y : err;
		start.x = e2 > -d.x ? start.x + s.x : start.x;
		err = e2 < d.y ? err + d.x : err;
		start.y = e2 < d.y ? start.y + s.y : start.y;
	}
}

void		draw_rectangle(SDL_Surface *surface, t_point start,
t_point width_height, int color)
{
	int		i;
	int		j;
	t_point	temp;

	i = -1;
	while (++i < width_height.y)
	{
		j = -1;
		temp.y = i + start.y;
		while (++j < width_height.x)
		{
			temp.x = j + start.x;
			set_pixel(surface, temp.x, temp.y, color);
		}
	}
}


void		draw_background(SDL_Surface *surface)
{
	int		i;
	int		j;

	i = -1;
	while (++i < W)
	{
		j = -1;
		while (++j < H)
		{
			set_pixel(surface, i, j, COLOR_BLACK);
		}
	}
}


#define RED 0xFF0000
// Function to put pixels 
// at subsequence points 
static void drawCircle(SDL_Surface *surface, int xc, int yc, int x, int y) 
{
	if (xc+x < W)
	{
		if (yc+y < H)
			set_pixel(surface, xc+x, yc+y, RED);
		if (yc-y > -1)
			set_pixel(surface, xc+x, yc-y, RED);
	}
	if (xc-x > -1)
	{
		if (yc+y < H)
			set_pixel(surface, xc-x, yc+y, RED);
		if (yc-y > -1)
			set_pixel(surface, xc-x, yc-y, RED);
	}
	if (xc-y > -1)
	{
		if (yc+x < H)
			set_pixel(surface, xc-y, yc+x, RED);
		if (yc-x > -1)
			set_pixel(surface, xc-y, yc-x, RED);
	}
	if (xc+y < W)
	{
		if (yc+x < H)
			set_pixel(surface, xc+y, yc+x, RED);
		if (yc-x > -1)
			set_pixel(surface, xc+y, yc-x, RED);
	}
} 
  

void draw_circle(SDL_Surface *surface, int xc, int yc, int r) 
{ 
    int x = 0, y = r; 
    int d = 3 - 2 * r; 
    drawCircle(surface, xc, yc, x, y); 
    while (y >= x) 
    { 
        x++; 
  
      
        if (d > 0) 
        { 
            y--;  
            d = d + 4 * (x - y) + 10; 
        } 
        else
            d = d + 4 * x + 6; 
        drawCircle(surface, xc, yc, x, y);
    } 
} 
