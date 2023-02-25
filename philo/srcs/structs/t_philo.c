/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_philo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:14 by znichola          #+#    #+#             */
/*   Updated: 2023/02/25 17:53:19 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_mutexes(t_philo *p);

/*
	philo_factory(&(t_philo){thread, id, eat, sleep, die, meals, fork, left});
 */
int	philo_factory(t_philo *p, t_philo *blueprint)
{
	p->my_thread = 0;
	p->id_number = blueprint->id_number;
	p->eat_time = blueprint->eat_time;
	p->sleep_time = blueprint->sleep_time;
	p->time_to_die = blueprint->time_to_die;
	p->meals_left = blueprint->meals_left;
	p->fork_state = 0;
	p->death_state = blueprint->death_state;
	p->death_lock = blueprint->death_lock;
	// p->death_log_state = 0;
	p->last_meal_time = ret_time_in_ms();
	if (init_mutexes(p))
		return (FATAL_ERROR);
	p->to_left = 0;
	return (0);
}

static int	init_mutexes(t_philo *p)
{
	if (pthread_mutex_init(&p->fork_lock, NULL))
		return (FATAL_ERROR);
	// if (pthread_mutex_init(&p->death_lock, NULL))
	// {
	// 	pthread_mutex_destroy(&p->fork_lock);
	// 	return (FATAL_ERROR);
	// }
	// if (pthread_mutex_init(&p->death_log_lock, NULL))
	// {
	// 	pthread_mutex_destroy(&p->fork_lock);
	// 	pthread_mutex_destroy(&p->death_lock);
	// 	return (FATAL_ERROR);
	// }
	// if (pthread_mutex_init(&p->last_meal_lock, NULL))
	// {
	// 	pthread_mutex_destroy(&p->fork_lock);
	// 	pthread_mutex_destroy(&p->death_lock);
	// 	return (FATAL_ERROR);
	// }
	return (0);
}
