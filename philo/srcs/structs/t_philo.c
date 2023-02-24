/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_philo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:14 by znichola          #+#    #+#             */
/*   Updated: 2023/02/24 22:31:41 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	p->fork_state = e_not_in_use;
	pthread_mutex_init(&p->fork_lock, NULL);
	if (p == NULL)
		return (FATAL_ERROR);
	p->to_left = 0;
	return (0);
}
