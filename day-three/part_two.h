/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part_two.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 00:06:44 by dpiza             #+#    #+#             */
/*   Updated: 2021/12/04 01:30:03 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PART_TWO_H
# define PART_TWO_H

# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include "libft/includes/ft_printf.h"
# include <fcntl.h>

# define O2		0
# define CO2	1
# define BITS	12

char	*file_name(const char *name, int i);
int		abtoi(char *arr);
void	free_matrix(int	**matrix);

#endif
