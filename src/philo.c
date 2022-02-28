/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:52:39 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/02/28 15:59:49 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static void	*philo_one(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork[philo->left]);
	print_philo(philo, get_time(), "\x1B[32mhas taken a fork\x1B[0m");
	pthread_mutex_unlock(&philo->table->fork[philo->left]);
	while (get_time() - philo->table->start_time
		< philo->table->time_to_die)
		usleep(1000);
	print_philo(philo, get_time(),
		" \x1B[31mis dead\x1B[0m\n");
	return ((void *) NULL);
}

static void	*ft_thread(void *philo_void)
{
	t_philo	*philo;

	philo = (t_philo *)philo_void;
	if (philo->table->philo_num == 1)
		return (philo_one(philo));
	if (philo->id % 2 == 0)
		usleep(philo->table->time_to_eat * 500);
	while (philo->table->exit == FALSE)
	{
		eatting(philo);
		sleeping(philo);
		thinking(philo);
	}
	return ((void *) NULL);
}

int	philo_start(t_table *table)
{
	int		i;

	i = 0;
	table->start_time = get_time();
	while (i < table->philo_num)
	{
		if (pthread_create(&(table->philo[i].philo), NULL, ft_thread,
				(void *)&table->philo[i]))
			return (-1);
		i++;
	}
	i = 0;
	return (0);
}
