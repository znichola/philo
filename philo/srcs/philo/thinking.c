/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:35:51 by znichola          #+#    #+#             */
/*   Updated: 2023/02/25 00:48:22 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

static void	eating(t_philo *p);

void	thinking_and_eating(t_philo *p)
{
	print_log(p->id_number, e_msg_is_thinking);
	while (1)
	{
		if (try_reserve(&p->fork_lock, &p->fork_state))
		{
			if (try_reserve(&p->to_left->fork_lock, &p->to_left->fork_state))
			{
				print_log(p->id_number, e_msg_taken_fork);
				print_log(p->id_number, e_msg_taken_fork);
				eating(p);
				give_back(&p->to_left->fork_lock, &p->to_left->fork_state);
				give_back(&p->fork_lock, &p->fork_state);
				return ;
			}
			give_back(&p->fork_lock, &p->fork_state);
		}
	}
}

static void	eating(t_philo *p)
{
	print_log(p->id_number, e_msg_is_eating);
	if (try_reserve(&p->ate_lock, &p->ate_state))
		printf("ERROR : should always be able to turn on ate state\n");
	rest(p, p->eat_time);
	if (p->meals_left != -1)
		p->meals_left -= 1;
}
