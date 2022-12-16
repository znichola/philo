/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:54:51 by znichola          #+#    #+#             */
/*   Updated: 2022/12/16 12:10:27 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// memset, printf, malloc, free, write,
// usleep, gettimeofday, pthread_create, pthread_detach, pthread_join,
// pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock

// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]

int	x = 0;
pthread_mutex_t	mutex;

void	*routine()
{
	printf("test of a new thread pid%d\n", getpid());
	for (int i = 0; i < 1000000; i++)
	{
		pthread_mutex_lock(&mutex);
		x += 1;
		pthread_mutex_unlock(&mutex);
	}
	sleep(3);
	printf("ending thread x:%d\n", x);
	return (NULL);
}

int	main(int ac, char **av)
{
	t_app a;
	
	if (ac > 6 || ac < 5)
		return (1);
	if(ft_safe_atoi(&a.philo_count, av[1]) + ft_safe_atoi(&a.ttdie, av[2]) 
		+ ft_safe_atoi(&a.tteat, av[3]) + ft_safe_atoi(&a.ttsleep, av[4]))
		return (1);
	if (ac == 6)
		if (ft_safe_atoi(&a.meals, av[5]))
			return (1);
	
	pthread_t	t[a.philo_count];

	if (pthread_mutex_init(&mutex, NULL))
		return (1);

	print_app(&a);
	int	i;

	i = -1;
	while (++i < a.philo_count)
	{
		if (pthread_create(t + i, NULL, &routine, NULL))
			return (1);
		printf("thread:%d started\n", i);
	}
	i = -1;
	while (++i < a.philo_count)
	{
		if (pthread_join(t[i], NULL))
			return (2);
		printf("thread:%d has finished\n", i);
	}
	
	if (pthread_mutex_destroy(&mutex))
		return (1);
	
	printf("final x:%d", x);
	return (SUCCESS);
}