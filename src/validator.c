/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 20:46:07 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/02/25 20:57:40 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	is_num(char c)
{
	return ('0' <= c && c <= '9');
}

static int	valid_arg(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (++i < argc)
	{
		j = -1;
		while (argv[i][++j])
		{
			if (!is_num(argv[i][j]))
				return (FALSE);
		}
	}
	return (TRUE);
}

int	validate(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (FALSE);
	if (!valid_arg(argc, argv))
		return (FALSE);
	return (TRUE);
}
