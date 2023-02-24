/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:03:49 by znichola          #+#    #+#             */
/*   Updated: 2023/02/24 23:30:00 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* functions a philo thread can do */

#include "philo.h"

static void	sleeping(t_philo *p);

void	*routine(void *philo)
{
	t_philo	*me;

	me = (t_philo*)philo;
	// printf("I, #%d have been launched! ", me->id_number);
	// printf("checking my left %d\n", me->to_left->id_number);
	while (me->meals_left > 0 || me->meals_left == -1)
	{
		thinking(me);
		sleeping(me);
	}
	print_log(me->id_number, e_msg_is_dead);
	return (NULL);
}

static void	sleeping(t_philo *p)
{
	print_log(p->id_number, e_msg_is_sleeping);
	usleep(p->sleep_time);
}

int	can_i_eat(t_philo *p)
{
	int	ret;

	ret = SUCCESS;
	(void)p;
	return (ret);
}
