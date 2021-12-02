/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:13:35 by dpiza             #+#    #+#             */
/*   Updated: 2021/12/01 23:39:22 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
#include "libft/includes/ft_printf.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*input;
	int		bigger;
	int		count;

	fd = open(argv[1], O_RDONLY);
	bigger = 0;
	count = 0;
	input = get_next_line(fd);
	bigger = ft_atoi(input);
	while (input)
	{
		free (input);
		input = get_next_line(fd);
		if (!input)
			break ;
		if (ft_atoi(input) > bigger)
			count++;
		bigger = ft_atoi(input);
	}
	close(fd);
	ft_printf("Increased measurements: %i\n", count);
}
