/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   behavior.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 21:17:56 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/02/25 14:51:02 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	eatting(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->fork[philo->left]);
	print_philo(philo, get_time(), "\x1B[32mis taken a fork\x1B[0m");
	pthread_mutex_lock(&philo->table->fork[philo->right]);
	print_philo(philo, get_time(), "\x1B[32mis taken a fork\x1B[0m");
	print_philo(philo, get_time(), "\x1B[33mis eating\x1B[0m");
	philo->eat_start = get_time();
	while (get_time() - philo->eat_start
		< philo->table->time_to_eat)
		usleep(1000);
	pthread_mutex_unlock(&philo->table->fork[philo->left]);
	pthread_mutex_unlock(&philo->table->fork[philo->right]);
	philo->eat_cnt++;
}

void	sleeping(t_philo *philo)
{
	philo->sleep_start = get_time();
	print_philo(philo, philo->sleep_start, "\x1B[34mis sleeping\x1B[0m");
	while (get_time() - philo->sleep_start
		< philo->table->time_to_sleep)
		usleep(1000);
}

void	thinking(t_philo *philo)
{
	print_philo(philo, get_time(), "\x1B[35mis thinking\x1B[0m");
}

void	print_philo(t_philo *philo, long long time, char *str)
{
	pthread_mutex_lock(&philo->table->print);
	if (philo->table->exit == FALSE)
	{
		printf("%lld ", time - philo->table->start_time);
		printf("%d ", philo->id);
		printf("%s\n", str);
	}
	pthread_mutex_unlock(&philo->table->print);
}
