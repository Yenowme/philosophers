/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:56:10 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/04/14 16:36:15 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

static unsigned long	atoi_sub(const char *str)
{
	int				i;
	unsigned long	rt;

	rt = 0;
	i = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		rt += (int)str[i] - '0';
		if (str[i + 1] >= '0' && str[i + 1] <= '9')
			rt *= 10;
		i++;
	}
	return (rt);
}

long long	ft_atoi(const char *str)
{
	int				i;
	int				sum;
	unsigned long	rt;

	sum = 1;
	i = 0;
	rt = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sum = -1;
		i++;
	}
	if (str[i] >= '0' && str[i] <= '9')
		rt = atoi_sub(&str[i]);
	if (sum == 1 && rt > 9223372036854775807)
		return (-1);
	else if (sum == -1 && rt > 9223372036854775807)
		return (0);
	return (rt * sum);
}

long long	get_time(void)
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
		pthread_join(table->philo[i].philo, NULL);
		i++;
	}
	pthread_mutex_destroy(&table->print);
	free(table->philo);
	free(table->fork);
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
