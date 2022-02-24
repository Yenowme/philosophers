/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:52:39 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/02/25 00:26:15 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

//static void	philo_print(char *str, t_table *table)
//{
//	pthread_mutex_lock(&table->print);
//	printf("%s", str);
//	printf("%d", table->must_eat_num);
//	pthread_mutex_unlock(&table->print);
//}

static void	*ft_thread(void *philo_void)
{
	t_philo	*philo;

	philo = (t_philo *)philo_void;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (philo->table->exit == FALSE)
	{
		eatting(philo);
		sleeping(philo);
		thinking(philo);
	}
	return ((void *)NULL);
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

