/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:03:49 by znichola          #+#    #+#             */
/*   Updated: 2022/12/30 14:49:21 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* functions a philo thread can do */

#include "philo.h"

int	can_i_eat(t_philo *p)
{
	int	ret;

	ret = SUCCESS;
	// pthread_mutex_lock(p->mutex);
	// state = p->x_fork_status;
	if (p->x_fork_lock == true || p->to_left->x_fork_lock == true)
		ret = FAILURE;
	if (p->x_fork_status == dirty)
		ret = FAILURE;
	if (p->to_left->x_fork_status == clean)
		ret = FAILURE;
	// pthread_mutex_unlock(p->mutex);
	return (ret);
}

void	eating(t_philo *p)
{
	// pthread_mutex_lock(p->mutex);
	p->x_fork_lock = true;
	p->to_left->x_fork_lock = true;
	usleep(p->eatt * 100);
	p->x_fork_lock = false;
	p->to_left->x_fork_lock = false;
	p->x_fork_status = dirty;
	p->to_left->x_fork_status = dirty;
	// pthread_mutex_unlock(p->mutex);
}
