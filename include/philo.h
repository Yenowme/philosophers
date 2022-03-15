/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejeong <yejeong@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:15:58 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/03/15 16:28:34 by yejeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

# define FALSE 0
# define TRUE 1

typedef struct s_table	t_table;
typedef struct s_philo
{
	pthread_t	philo;
	int			id;
	int			left;
	int			right;
	int			eat_cnt;
	long long	eat_start;
	long long	sleep_start;
	t_table		*table;
}	t_philo;

typedef struct s_table
{
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_num;
	long long		start_time;
	int				exit;
	int				eat_philo_cnt;
	t_philo			*philo;
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
}	t_table;

int			err_return(char *str);
long long	ft_atoi(const char *str);
long long	get_time(void);
int			free_philo(t_table *table);
size_t		ft_strlen(const char *s);

int			validate_atoi(char *str);

int			init(char **argv, t_table *table);

int			philo_start(t_table *table);
long long	ft_time(void);
int			validate(int argc, char **argv);

void		print_philo(t_philo *philo, long long time, char *str);
void		eatting(t_philo *philo);
void		sleeping(t_philo *philo);
void		thinking(t_philo *philo);

int			monitor(t_table *table);

#endif
