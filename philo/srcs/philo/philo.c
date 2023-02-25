/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:03:49 by znichola          #+#    #+#             */
/*   Updated: 2023/02/25 23:42:36 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* functions a philo thread can do */

#include "philo.h"

static int	sleeping(t_philo *p);
// static void	*announce_death(t_philo *p);

void	*routine(void *philo)
{
	t_philo		*me;

	me = (t_philo *)philo;
	while (me->meals_left > 0 || me->meals_left == -1)
	{
		if (thinking_and_eating(me))
			return (NULL);
		if (sleeping(me))
			return (NULL);
	}
	return (NULL);
}

static int	sleeping(t_philo *p)
{
	if (check_death(p))
		return (1);
	print_log(p->id_number, e_msg_is_sleeping);
	return (do_activity(p, p->sleep_time));
}

// static void	*announce_death(t_philo *p)
// {
// 	print_log(p->id_number, e_msg_is_dead);
// 	return (NULL);
// }
