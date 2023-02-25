/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:12:00 by znichola          #+#    #+#             */
/*   Updated: 2023/02/25 01:17:35 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	*death_routine(void *philo);

void	rest(t_philo *p, int sleep_in_ms)
{
	// check for death during this long sleep
	(void)p;
	usleep(sleep_in_ms * 100);
}

int	launch_deathtimer(pthread_t *death_timer, t_philo *p)
{
	if (pthread_create(death_timer, NULL, death_routine, p))
		return (FATAL_ERROR);
	return (0);
}

static void	*death_routine(void *philo)
{
	t_philo		*me;

	me = (t_philo*)philo;
	while (1)
	{
		if (try_reserve(&me->ate_lock, &me->ate_state))
			;
	}
	return (NULL);
}
