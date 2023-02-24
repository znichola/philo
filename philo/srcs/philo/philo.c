/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:03:49 by znichola          #+#    #+#             */
/*   Updated: 2023/02/24 20:29:10 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* functions a philo thread can do */

#include "philo.h"

static void	sleeping(t_philo *p);
static void	eating(t_philo *p);
static void	thinking(t_philo *p);

void	*routine(void *philo)
{
	t_philo	*me;

	me = (t_philo*)philo;
	printf("I, #%d have been launched!\n", me->id_number);
	// sleep(me->id_number);
	thinking(me);
	sleeping(me);
	print_log(me->id_number, e_msg_is_dead);
	return (NULL);
}

static void	sleeping(t_philo *p)
{
	print_log(p->id_number, e_msg_is_sleeping);
	usleep(p->sleep_time);
}

static void	eating(t_philo *p)
{
	print_log(p->id_number, e_msg_is_eating);
	usleep(p->eat_time);
}

static void	thinking(t_philo *p)
{
	pthread_mutex_lock(&p->to_left->fork);
	print_log(p->id_number, e_msg_taken_fork);
	pthread_mutex_lock(&p->fork);
	print_log(p->id_number, e_msg_taken_fork);
	eating(p);
	pthread_mutex_unlock(&p->fork);
	pthread_mutex_unlock(&p->to_left->fork);
}

int	can_i_eat(t_philo *p)
{
	int	ret;

	ret = SUCCESS;
	(void)p;
	return (ret);
}
