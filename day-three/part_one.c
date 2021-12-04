/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 08:25:14 by dpiza             #+#    #+#             */
/*   Updated: 2021/12/03 21:31:58 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/includes/libft.h"
#include "libft/includes/get_next_line.h"
#include "libft/includes/ft_printf.h"
#include <fcntl.h>

int	**sum_occurrence(char *file_name)
{
	int		fd;
	char	*input;
	int		**occur;
	int		i;

	occur = (int **)ft_calloc(2, sizeof(int *));
	occur[0] = (int *)ft_calloc(12, sizeof(int));
	occur[1] = (int *)ft_calloc(12, sizeof(int));
	fd = open(file_name, O_RDONLY);
	input = get_next_line(fd);
	while (input)
	{
		i = -1;
		while (++i < 12)
		{
			if (input[i] == '0')
				occur[0][i]++;
			else
				occur[1][i]++;
		}
		free (input);
		input = get_next_line(fd);
	}
	close(fd);
	return (occur);
}

void	print_occurrence(int **occur)
{
	int		i;

	i = -1;
	ft_printf("Occurrence[0]: ");
	while (++i < 12)
		ft_printf("%i ", occur[0][i]);
	ft_printf("\nOccurrence[1]: ");
	i = -1;
	while (++i < 12)
		ft_printf("%i ", occur[1][i]);
	ft_printf("\n");
}

int	*calc_rates(int **occur)
{
	int	i;
	int	*rates;

	i = -1;
	rates = ft_calloc(2, sizeof(int));
	while (++i < 12)
	{
		if (occur[0][i] > occur[1][i])
		{
			rates[0] = rates[0] << 1 | 0;
			rates[1] = rates[1] << 1 | 1;
		}
		else
		{
			rates[0] = rates[0] << 1 | 1;
			rates[1] = rates[1] << 1 | 0;
		}
	}
	return (rates);
}

int	main(int argc, char **argv)
{
	int		**occur;
	int		*rates;

	occur = sum_occurrence(argv[1]);
	print_occurrence(occur);
	rates = calc_rates(occur);
	ft_printf("Rates[0]: %i \nRates[1]: %i\nPower Consumption: %i\n",
		rates[0], rates[1], rates[0] * rates[1]);
	free(occur[0]);
	free(occur[1]);
	free(occur);
	free(rates);
	return (0);
}
