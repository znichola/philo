/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:54:51 by znichola          #+#    #+#             */
/*   Updated: 2023/02/24 17:40:35 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// memset, printf, malloc, free, write,
// usleep, gettimeofday, pthread_create, pthread_detach, pthread_join,
// pthread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock

// number_of_philosophers time_to_die time_to_eat time_to_sleep
// [number_of_times_each_philosopher_must_eat]

// int	x = 0;
// pthread_mutex_t	mutex;

// void	*routine()
// {
// 	printf("test of a new thread pid%d\n", getpid());
// 	for (int i = 0; i < 1000000; i++)
// 	{
// 		pthread_mutex_lock(&mutex);
// 		x += 1;
// 		pthread_mutex_unlock(&mutex);
// 	}
// 	sleep(3);
// 	printf("ending thread x:%d\n", x);
// 	return (NULL);
// }

// void	*roll_dice()
// {
// 	int	value = rand() % 6 + 1;
// 	int	*res = (int *)malloc(sizeof(int) * 1);
// 	*res = value;
// 	printf("value:%d\n", value);
// 	return ((void *)res);
// }

	// // mutex stuff
	// pthread_t	t[a.philo_count];
	// if (pthread_mutex_init(&mutex, NULL))
	// 	return (1);
	// // print_app(&a);

	// i = -1;
	// while (++i < a.philo_count)
	// {
	// 	if (pthread_create(t + i, NULL, &roll_dice, NULL))
	// 		return (1);
	// 	printf("thread:%d started\n", i);
	// }
	// i = -1;
	// while (++i < a.philo_count)
	// {
	// 	if (pthread_join(t[i], (void **) &res))
	// 		return (2);
	// 	printf("thread:%d has finished with:%d\n", i, *res);
	// 	free(res);
	// 	res = NULL;
	// }

	// if (pthread_mutex_destroy(&mutex))
	// 	return (1);
	// // end mutex stuff


int	main(int ac, char **av)
{
	t_app		a;
	// int			i;
	// int			*res;

	srand(time(NULL));
	if (input_check_assign(ac, av, &a))
		return (FAILURE);
	init_philos(&a);
	// print_all_philos(&a);
	printf("\n");
	printf("thread ret:%d\n", thread_philos(&a));

	// printf("join   ret:%d\n", join_philos(&a));
	usleep(100000);
	free_philos(&a);
	pthread_mutex_destroy(&a.mutex);
	return (SUCCESS);
}
