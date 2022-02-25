/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:47:38 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/02/25 20:18:58 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static long long	set_starve_time(t_table *table, int id)
{
	long long	starve_time;

	if (table->philo[id].eat_start == 0)
		starve_time = table->start_time;
	else
		starve_time = table->philo[id].eat_start;
	return (starve_time);
}

static int	return_full(t_table *table)
{
	table->exit = TRUE;
	return (free_philo(table));
}

static int	return_die(t_table *table, int id)
{
	pthread_mutex_lock(&table->print);
	print_philo(&table->philo[id], get_time(),
		" \x1B[31mis dead\x1B[0m\n");
	table->exit = TRUE;
	return (free_philo(table));
}

static void	check_philo_eat(t_table *table, int id)
{
	if (table->must_eat_num != -1
		&& table->philo[id].eat_cnt >= table->must_eat_num)
		table->eat_philo_cnt++;
}

int	monitor(t_table *table)
{
	int			i;
	long long	starve_time;

	table->eat_philo_cnt = 0;
	while (TRUE)
	{
		i = -1;
		while (++i < table->philo_num)
		{
			starve_time = set_starve_time(table, i);
			if (get_time() - starve_time >= table->time_to_die)
				return (return_die(table, i));
			check_philo_eat(table, i);
			usleep(1000);
		}
		if (table->eat_philo_cnt == table->philo_num)
			return (return_full(table));
		table->eat_philo_cnt = 0;
	}
	return (0);
}
