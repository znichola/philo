/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:55:26 by znichola          #+#    #+#             */
/*   Updated: 2023/02/25 17:48:34 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	cleanup_philos(t_app *d)
{
	int		i;

	i = d->args[e_num_philos];
	pthread_mutex_destroy(&d->death_lock);
	while (--i >= 0)
	{
		pthread_mutex_destroy(&d->philo_table[i].fork_lock);
		// pthread_mutex_destroy(&d->philo_table[i].death_lock);
		// pthread_mutex_destroy(&d->philo_table[i].death_log_lock);
	}
	free(d->philo_table);
}
