/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:03:49 by znichola          #+#    #+#             */
/*   Updated: 2023/02/27 23:54:01 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* functions a philo thread can do */

#include "philo.h"

// static void	*announce_death(t_philo *p);

void	*routine(void *philo)
{
	t_philo		*me;

	me = (t_philo *)philo;
	while(get_mutex_state(me->death_lock, me->death_state) == 2)
		usleep(100);
	if (!(me->id_number % 2))
		usleep(500);
	me->last_meal_time = get_time_in_ms();
	while (me->meals_left > 0 || me->meals_left == -1)
	{
		if (thinking_and_eating(me))
			return (NULL);
		if (sleeping(me))
			return (NULL);
	}
	return (NULL);
}

// static void	*announce_death(t_philo *p)
// {
// 	print_log(p->id_number, e_msg_is_dead);
// 	return (NULL);
// }
