/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 21:00:08 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/02/24 20:34:58 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static int	init_struct(char **argv, t_table *table)
{
	memset(table, 0, sizeof(t_table));
	table->philo_num = ft_atoi(argv[1]);
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->must_eat_num = -1;
	if (argv[5])
		table->must_eat_num = ft_atoi(argv[5]);
	return (0);
}

static int	init_thread_and_mutex(t_table *table)
{
	int	i;

	table->philo = (t_philo *)malloc(sizeof(t_philo) * table->philo_num);
	if (!table->philo)
		return (-1);
	table->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t)
			* table->philo_num);
	if (!table->fork)
		return (-1);
	if (pthread_mutex_init(&table->print, NULL))
		return (-1);
	i = 0;
	while (i < table->philo_num)
	{
		if (pthread_mutex_init(&table->fork[i], NULL))
			return (-1);
		i++;
	}
	return (0);
}

static int	init_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_num)
	{
		memset(&table->philo[i], 0, sizeof(t_philo));
		table->philo[i].id = i;
		table->philo[i].left = i;
		table->philo[i].right = (i + 1) % table->philo_num;
		table->philo[i].table = table;
		i++;
	}
	return (0);
}

int	init(char **argv, t_table *table)
{
	if (init_struct(argv, table) == -1)
		return (-1);
	if (init_thread_and_mutex(table) == -1)
		return (-1);
	if (init_philo(table) == -1)
		return (-1);
	return (0);
	//return (monitor_philo(table));
}
