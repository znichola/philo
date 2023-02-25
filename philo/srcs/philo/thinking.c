/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:35:51 by znichola          #+#    #+#             */
/*   Updated: 2023/02/25 18:50:54 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

static int	eating(t_philo *p);

int	thinking_and_eating(t_philo *p)
{
	int	ret;

	ret = 0;
	if (check_death(p))
		return (1);
	print_log(p->id_number, e_msg_is_thinking);
	while (1)
	{
		if (try_reserve(&p->fork_lock, &p->fork_state))
		{
			if (try_reserve(&p->to_left->fork_lock, &p->to_left->fork_state))
			{
				if (check_death(p))
					return (1);
				print_log(p->id_number, e_msg_taken_fork);
				print_log(p->id_number, e_msg_taken_fork);
				ret = eating(p);
				give_back(&p->to_left->fork_lock, &p->to_left->fork_state);
				give_back(&p->fork_lock, &p->fork_state);
				break ;
			}
			give_back(&p->fork_lock, &p->fork_state);
		}
	}
	return (ret);
}

static int	eating(t_philo *p)
{
	if (check_death(p))
		return (1);
	print_log(p->id_number, e_msg_is_eating);
	// pthread_mutex_lock(&p->last_meal_lock);
	p->last_meal_time = ret_time_in_ms();
	// pthread_mutex_unlock(&p->last_meal_lock);
	if (p->meals_left != -1)
		p->meals_left -= 1;
	return (do_activity(p, p->eat_time));
}
