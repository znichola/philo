/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:35:51 by znichola          #+#    #+#             */
/*   Updated: 2023/02/27 15:35:20 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	thinking_and_eating(t_philo *p)
{
	int	ret;

	ret = 0;
	// if (check_death(p))
	// 	return (1);
	print_log(p->id_number, e_msg_is_thinking);
	while (1)
	{
		if (check_death(p))
			return (1);
		if (try_reserve(&p->fork_lock, &p->fork_state))
		{
			if (try_reserve(&p->to_left->fork_lock, &p->to_left->fork_state))
			{
				print_log(p->id_number, 42);
				ret = eating(p);
				print_log(p->id_number, 42);
				give_back(&p->to_left->fork_lock, &p->to_left->fork_state);
				give_back(&p->fork_lock, &p->fork_state);
				break ;
			}
			give_back(&p->fork_lock, &p->fork_state);
		}
	}
	return (ret);
}
