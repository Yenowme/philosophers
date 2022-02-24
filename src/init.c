/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:00:08 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/02/23 21:07:03 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_struct(char **argv, t_table *table)
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

int	init_thread_and_mutex(t_table *table)
{
	int	i;
	int	err;

	table->philo = (t_philo *)malloc(sizeof(t_philo) * table->philo_num);
	if (!table->philo)
		return (-1);
	table->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* table->philo_num);
	if (!table->fork)
		return (-1);
	i = 0;
	while (i++ < table->philo_num)
	{
		err = pthread_mutex_init(&table->fork[i], NULL);
		//if (!err)
		//	return (-1);
		printf("%s\n", table->fork[i].__opaque);
	}
	return (0);
}

int	init_table(char **argv, t_table *table)
{
	if (init_struct(argv, table) == -1)
		return (-1);
	if (init_thread_and_mutex(table) == -1)
		return (-1);
	return (0);
}
