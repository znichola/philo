/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 16:55:57 by znichola          #+#    #+#             */
/*   Updated: 2023/02/24 14:14:51 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_philos(t_app *a)
{
	t_philo	*t;
	t_philo	*foo;

	t = a->philo;
	if (t == NULL)
		return ;
	if (t->to_left == NULL)
	{
		// printf("exception freeing philo id %d at adress \033[31m%p\033[0m\n", t->id, t);
		free(t);
		return ;
	}
	while(t->to_left && t->id != a->philo_count)
	{
		// printf("      freeing philo id %d at adress \033[31m%p\033[0m left is \033[31m%p\033[0m\n", t->id, t, t->to_left);
		foo = t->to_left;
		free(t);
		t = foo;
	}
	// printf("final freeing philo id %d at adress \033[31m%p\033[0m left is \033[31m%p\033[0m\n", t->id, t, t->to_left);
	free(t);
}

int	init_philos(t_app *a)
{
	int		i;
	t_philo	*t;
	t_philo	*old;
	i = 0;

	while (i++ < a->philo_count)
	{
		// printf("       making philo id %d at adress ", i);
		t = (t_philo *)malloc(sizeof(t_philo) * 1);
		if (!t)
			return (MALLOC_ERROR);
		if (i == 1)
			a->philo = t;
		else
			old->to_left = t;
		// printf("\033[31m%p\033[0m\n", t);
		t->id = i;
		t->diet = a->ttdie;
		t->eatt = a->tteat;
		t->sleept = a->ttsleep;
		t->meals = a->meals;
		t->mutex = &a->mutex;
		if (i % 2)
			t->x_fork_status = dirty;
		else
			t->x_fork_status = clean;
		t->to_left = NULL;
		old = t;
		// t = t->to_left;
		// not setting to_left to NULL correctly
	}
	old->to_left = a->philo;
	return (0);
}

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
void	*philo_routine(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	printf("made a new thread for: %d\n", p->id);
	// print_philo(p);
	return (NULL);
}

int	thread_philos(t_app *a)
{
	t_philo	*t;
	int		i;

	i = 0;
	t = a->philo;
	while(i++ < a->philo_count)
	{
		if (pthread_create(&t->thread, NULL, &philo_routine , t))
			return (10);
		t = t->to_left;
	}
	return (0);
}

int	join_philos(t_app *a)
{
	t_philo	*t;
	int		i;

	i = 0;
	t = a->philo;
	while(i++ < a->philo_count)
	{
		if (pthread_join(t->thread, NULL))
			return (11);
		t = t->to_left;
	}
	return (0);
}
