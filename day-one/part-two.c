/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part-two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 23:25:12 by dpiza             #+#    #+#             */
/*   Updated: 2021/12/02 16:26:19 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
#include "libft/includes/ft_printf.h"
#include <fcntl.h>

typedef struct s_group
{
	int	n_one;
	int	n_two;
	int	n_three;
	int	sum;
}	t_group;

int	sum_group(t_group *group)
{
	int	sum;

	sum = group->n_one + group->n_two + group->n_three;
	return (sum);
}

int	init(t_group *group, int fd)
{
	char		*input;
	int			sum;

	input = get_next_line(fd);
	group->n_one = ft_atoi(input);
	free(input);
	input = get_next_line(fd);
	group->n_two = ft_atoi(input);
	free(input);
	input = get_next_line(fd);
	group->n_three = ft_atoi(input);
	free(input);
	sum = sum_group(group);
	return (sum);
}

int	main(int argc, char **argv)
{
	int			count;
	int			fd;
	char		*input;
	t_group		group;
	int			temp_sum;

	count = 0;
	fd = open(argv[1], O_RDONLY);
	temp_sum = init(&group, fd);
	while (1)
	{
		input = get_next_line(fd);
		if (!input)
			break ;
		group.n_three = ft_atoi(input);
		group.sum = sum_group(&group);
		if (temp_sum < group.sum)
			count++;
		group.n_one = group.n_two;
		group.n_two = group.n_three;
		temp_sum = group.sum;
		free (input);
	}
	ft_printf("Increased sums: %i\n", count);
}
