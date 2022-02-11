/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:15:22 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/02/10 18:50:23 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	err_return(char *str)
{
	printf("Error\n");
	printf("%s", str);
	return (-1);
}

int	init_table(char **argv, t_table *table)
{
	memset(table, 0, sizeof(t_table));
	table->philo_num = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->must_eat_num = ft_atoi(argv[5]);
	return (0);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (argc != 5 && argc != 6)
		return (err_return("The number of arguments must be four or five."));
	if (init_table(argv, &table))
		return (err_return("Faile to init data."));
}
