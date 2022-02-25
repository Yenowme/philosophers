/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 17:47:38 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/02/25 14:50:56 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"


long long	ft_time(void)
{
	struct timeval	time;
	long long		ms;

	gettimeofday(&time, NULL);
	ms = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (ms);
}


int	free_philo(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_num)
	{
		pthread_mutex_destroy(&table->fork[i]);
		if (pthread_join(table->philo[i].philo, NULL))
			return (-1);
		i++;
	}
	pthread_mutex_destroy(&table->print);
	free(table->philo);
	free(table->fork);
	return (0);
}

int	monitor(t_table *table)
{
	int			i;
	long long	starve_time;

	table->eat_philo_cnt = 0;
	while (TRUE)
	{
		i = 0;
		while (i < table->philo_num)
		{
			//printf("%d", table->exit);
			if (table->philo[i].eat_start == 0)
				starve_time = table->start_time;
			else
				starve_time = table->philo[i].eat_start;
			if (get_time() - starve_time >= table->time_to_die)
			{
				print_philo(&table->philo[i], get_time(),
					" \x1B[31mis dead\x1B[0m\n");
				table->exit = TRUE;
				return (free_philo(table));
			}
			if (table->must_eat_num != -1 && table->philo[i].eat_cnt >= table->must_eat_num)
				table->eat_philo_cnt++;
			usleep(1000);
			i++;
		}
		if (table->eat_philo_cnt == table->philo_num)
		{
			table->exit = TRUE;
			printf("philosophers are full~\n");
			return (free_philo(table));
		}
		table->eat_philo_cnt = 0;
	}
	return (0);
}
