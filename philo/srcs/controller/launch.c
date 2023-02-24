/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:48:02 by znichola          #+#    #+#             */
/*   Updated: 2023/02/24 16:39:58 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	launch_all_philos(t_app *d)
{
	d->philo_table = malloc(sizeof(t_philo) * d->args[e_num_philos]);
	return (0);
}

// static	void setup_philos()
// {
// 	;
// }
