/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeong-yena <jeong-yena@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 15:15:22 by jeong-yena        #+#    #+#             */
/*   Updated: 2022/02/23 21:11:04 by jeong-yena       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	err_return(char *str)
{
	printf("Error\n");
	printf("%s", str);
	return (-1);
}

void *ft_thread(void *str)
{
	//usleep(1);
	printf("hi %d\n", *((int *)str));
	return (void *)NULL;
}

int	main(int argc, char **argv)
{
	t_table	table;
	int		i;

	//if (validate(argc, argv))
	if (argc != 5 && argc != 6)
		return (err_return("The number of arguments must be four or five."));
	if (init_table(argv, &table))
		return (err_return("Faile to init data."));
	i = 0;
	while (i++ < table.philo_num)
	{
		pthread_create(&(table.philo[i].philo), NULL, ft_thread, (void *)&i);
	}
	pthread_join(table.philo[0].philo, NULL);
	pthread_join(table.philo[1].philo, NULL);
	printf("end\n");
}
