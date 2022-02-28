/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 20:46:07 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/02/28 17:52:26 by jeong-yena       ###   ########.fr       */
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

int	validate_atoi(char *str)
{
	long long	num;

	if (ft_strlen(str) > 10)
		return (-2);
	num = ft_atoi(str);
	if (num < 0 || num > 2147483647)
		return (-2);
	return (num);
}

int	validate(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (FALSE);
	if (!valid_arg(argc, argv))
		return (FALSE);
	return (TRUE);
}
