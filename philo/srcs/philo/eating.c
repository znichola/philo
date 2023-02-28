/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:34:03 by znichola          #+#    #+#             */
/*   Updated: 2023/02/28 00:59:59 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eating(t_philo *p)
{
	print_log(p->id_number, e_msg_is_eating);
	p->last_meal_time = get_time_in_ms();
	if (p->meals_left != -1)
		p->meals_left -= 1;
	return (do_activity(p, p->eat_time));
}

	// if (check_death(p))
	// 	return (1);
