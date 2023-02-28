/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:33:01 by znichola          #+#    #+#             */
/*   Updated: 2023/02/28 00:50:27 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	sleeping(t_philo *p)
{
	print_log(p->id_number, e_msg_is_sleeping);
	return (do_activity(p, p->sleep_time));
}

	// print_log(p->id_number, 42);
	// if (check_death(p))
	// 	return (1);
