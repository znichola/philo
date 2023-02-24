/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:48:02 by znichola          #+#    #+#             */
/*   Updated: 2023/02/24 20:05:48 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	launch_philo(t_philo *p);

int	launch_all_philos(t_app *d)
{
	int		i;

	i = d->args[e_num_philos];
	while (--i >= 0)
	{
		if (launch_philo(d->philo_table + i))
			return (FATAL_ERROR);
	}
	return (0);
}

static int	launch_philo(t_philo *p)
{
	if (pthread_create(&p->my_thread, NULL, &routine, p))
		return (FATAL_ERROR);
	return (0);
}
