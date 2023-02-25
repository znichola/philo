/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:03:49 by znichola          #+#    #+#             */
/*   Updated: 2023/02/25 01:19:28 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* functions a philo thread can do */

#include "philo.h"

static void	sleeping(t_philo *p);

void	*routine(void *philo)
{
	t_philo		*me;
	pthread_t	death_timer;

	me = (t_philo*)philo;
	// if (launch_deathtimer(&death_timer, me))
	// 	return (NULL);
	while (me->meals_left > 0 || me->meals_left == -1)
	{
		thinking_and_eating(me);
		sleeping(me);
	}
	// pthread_join(death_timer, NULL);
	print_log(me->id_number, e_msg_is_dead);
	return (NULL);
}

static void	sleeping(t_philo *p)
{
	print_log(p->id_number, e_msg_is_sleeping);
	rest(p, p->sleep_time);
}
