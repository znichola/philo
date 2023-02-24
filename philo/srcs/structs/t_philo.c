/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_philo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 14:51:14 by znichola          #+#    #+#             */
/*   Updated: 2023/02/24 17:35:46 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	philo_factory(&(t_philo){thread, id, eat, sleep, die, meals, fork, left});
 */
t_philo	*philo_factory(t_philo *blueprint)
{
	t_philo	*p;

	p = (t_philo *)malloc(sizeof(t_philo) * 1);
	if (p == NULL)
		return (NULL);
	if (blueprint)
	{
		p->my_thread = 0;
		p->id_number = blueprint->id_number;
		p->eat_time = blueprint->eat_time;
		p->sleep_time = blueprint->sleep_time;
		p->time_to_die = blueprint->time_to_die;
		p->meals_left = blueprint->meals_left;
		pthread_mutex_init(&p->fork, NULL);
		if (p == NULL)
			return (NULL);
		p->to_left = 0;
	}
	else
		printf("error! use the blueprint when making a philo\n");
	return (p);
}
