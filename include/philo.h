/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:15:58 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/02/23 21:01:40 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_philo
{
	pthread_t	philo;
	int			id;
	int			eat_cnt;
}	t_philo;

typedef struct s_table
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_num;
	long long		start_time;
	t_philo			*philo;
	pthread_mutex_t	*fork;
}	t_table;

int		err_return(char *str);
int		ft_atoi(const char *str);

int		init_struct(char **argv, t_table *table);
int		init_thread_and_mutex(t_table *table);
int		init_table(char **argv, t_table *table);

#endif
