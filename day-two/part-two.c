/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part-two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 09:12:40 by dpiza             #+#    #+#             */
/*   Updated: 2021/12/02 09:21:35 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
#include "libft/includes/ft_printf.h"
#include <fcntl.h>

typedef struct s_position
{
	int		horiz;
	int		depth;
	int		aim;
}	t_position;

void	move(t_position *pos, char **movement)
{
	if (ft_strncmp(movement[0], "up", 3) == 0)
		pos->aim -= ft_atoi(movement[1]);
	if (ft_strncmp(movement[0], "down", 5) == 0)
		pos->aim += ft_atoi(movement[1]);
	if (ft_strncmp(movement[0], "forward", 8) == 0)
	{
		pos->horiz += ft_atoi(movement[1]);
		pos->depth += pos->aim * ft_atoi(movement[1]);
	}
}

int	main(int argc, char **argv)
{
	int			fd;
	t_position	pos;
	char		*buffer;
	char		**movement;

	fd = open(argv[1], O_RDONLY);
	pos.horiz = 0;
	pos.aim = 0;
	pos.depth = 0;
	while (1)
	{
		buffer = get_next_line(fd);
		if (!buffer)
			break ;
		movement = ft_split(buffer, 32);
		move(&pos, movement);
		free (buffer);
		free (movement);
	}
	ft_printf("Depth: %i\nHoriz: %i\nMultiplied: %i\n",
		pos.depth, pos.horiz, pos.depth * pos.horiz);
	return (0);
}
