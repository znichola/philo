/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:34:03 by znichola          #+#    #+#             */
/*   Updated: 2023/02/27 15:34:44 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_philo *p)
{
	// if (check_death(p))
	// 	return (1);
	print_log(p->id_number, e_msg_taken_fork);
	print_log(p->id_number, e_msg_taken_fork);
	print_log(p->id_number, e_msg_is_eating);
	p->last_meal_time = ret_time_in_ms();
	if (p->meals_left != -1)
		p->meals_left -= 1;
	return (do_activity(p, p->eat_time));
}
