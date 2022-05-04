/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:15:22 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/05/04 15:20:01 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	err_return(char *str)
{
	write(2, "Error\n", 6);
	write(2, str, ft_strlen(str));
	return (1);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (!validate(argc, argv))
		return (err_return("Invalid arguments."));
	if (init(argv, &table))
		return (err_return("Faile to init data."));
	if (philo_start(&table))
		return (err_return("Faile to start philo"));
	return (monitor(&table));
}
