/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_two_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 00:02:39 by dpiza             #+#    #+#             */
/*   Updated: 2021/12/04 00:58:06 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "part_two.h"

char	*file_name(const char *name, int i)
{
	char	*i_arr;
	char	*ret;

	i_arr = ft_itoa(i);
	ret = ft_strjoin(name, i_arr);
	free (i_arr);
	return (ret);
}

int	abtoi(char *arr)
{
	int	i;
	int	ret;

	ret = 0;
	i = -1;
	while (++i < 12)
	{
		if (arr[i] == '1')
			ret = ret << 1 | 1;
		else
			ret = ret << 1 | 0;
	}
	return (ret);
}

void	free_matrix(int	**matrix)
{
	free(matrix[0]);
	free(matrix[1]);
	free(matrix);
}
