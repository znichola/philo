/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 22:35:51 by znichola          #+#    #+#             */
/*   Updated: 2023/02/28 08:43:15 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	get_left_fork(t_philo *p);
static int	get_right_fork(t_philo *p);

int	thinking_and_eating(t_philo *p)
{
	int	ret;

	ret = 0;
	if (check_death(p))
		return (1);
	print_log(p->id_number, e_msg_is_thinking);
	if (get_right_fork(p))
		return (1);
	print_log(p->id_number, e_msg_taken_fork);
	if (get_left_fork(p))
		return (1);
	print_log(p->id_number, e_msg_taken_fork);
	ret = eating(p);
	give_back(&p->to_left->fork_lock, &p->to_left->fork_state);
	give_back(&p->fork_lock, &p->fork_state);
	return (ret);
}

static int	get_right_fork(t_philo *p)
{
	while (1)
	{
		if (check_death(p))
			return (1);
		if (try_reserve(&p->fork_lock, &p->fork_state))
			break ;
		usleep(100);
	}
	return (0);
}

static int	get_left_fork(t_philo *p)
{
	while (1)
	{
		if (check_death(p))
			return (1);
		if (try_reserve(&p->to_left->fork_lock, &p->to_left->fork_state))
			break ;
		usleep(100);
	}
	return (0);
}

// int	thinking_and_eating(t_philo *p)
// {
// 	int	ret;

// 	ret = 0;
// 	// if (check_death(p))
// 	// 	return (1);
// 	print_log(p->id_number, e_msg_is_thinking);
// 	while (1)
// 	{
// 		if (check_death(p))
// 			return (1);
// 		if (try_reserve(&p->fork_lock, &p->fork_state))
// 		{
// 			if (try_reserve(&p->to_left->fork_lock, &p->to_left->fork_state))
// 			{
// 				ret = eating(p);
// 				give_back(&p->to_left->fork_lock, &p->to_left->fork_state);
// 				give_back(&p->fork_lock, &p->fork_state);
// 				break ;
// 			}
// 			give_back(&p->fork_lock, &p->fork_state);
// 		}
// 	}
// 	return (ret);
// }
