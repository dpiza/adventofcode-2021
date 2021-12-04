/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 08:25:14 by dpiza             #+#    #+#             */
/*   Updated: 2021/12/04 01:19:59 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "part_two.h"

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

int	filter_data(int mask, int index, char *input_file, char const *name)
{
	char	*output_file;
	int		fd_r;
	int		fd_w;
	char	*input_line;
	int		entries;

	output_file = file_name(name, index);
	fd_r = open(input_file, O_RDONLY);
	fd_w = open(output_file, O_RDWR | O_CREAT | O_APPEND, 0644);
	input_line = get_next_line(fd_r);
	entries = 0;
	while (input_line)
	{
		if (input_line[index] - '0' == mask)
		{
			write(fd_w, input_line, 13);
			entries++;
		}
		free (input_line);
		input_line = get_next_line(fd_r);
	}
	close(fd_r);
	close(fd_w);
	free (output_file);
	return (entries);
}

char	*calc_rate(int type, char *in_file, const char *output_file, int bits)
{
	int		**occur;
	int		mask;
	char	*file;
	int		i;
	char	*input;

	i = -1;
	file = ft_strdup(in_file);
	while (++i < bits)
	{
		occur = sum_occurrence(file);
		mask = 1;
		if ((occur[0][i] > occur[1][i] && type == O2)
			|| (occur[0][i] <= occur[1][i] && type == CO2))
			mask = 0;
		free_matrix(occur);
		if (filter_data(mask, i, file, output_file) == 1)
			bits = i;
		free(file);
		file = file_name(output_file, i);
	}
	input = get_next_line(open(file, O_RDONLY));
	free(file);
	return (input);
}

int	main(int argc, char **argv)
{
	char	*o2_rate;
	char	*co2_rate;

	o2_rate = calc_rate(O2, argv[1], "output/Generator", BITS);
	co2_rate = calc_rate(CO2, argv[1], "output/Scrubber", BITS);
	ft_printf("O2 Gen Rate: %d\nCO2 Scrub Rate: %d\nMultiplied: %d\n",
		abtoi(o2_rate), abtoi(co2_rate), abtoi(o2_rate) * abtoi(co2_rate));
	free (o2_rate);
	free (co2_rate);
	return (0);
}
