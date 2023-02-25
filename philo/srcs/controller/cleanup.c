/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 15:55:26 by znichola          #+#    #+#             */
/*   Updated: 2023/02/25 23:36:18 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	wait_all_philos(t_app *d)
{
	int		i;
	t_philo	*tmp;

	i = d->args[e_num_philos];
	while (--i >= 0)
	{
		tmp = &d->philo_table[i];
		if (pthread_join(tmp->my_thread, NULL))
			printf("failed to join thread #%d\n", i);
	}
	return (0);
}

void	cleanup_philos(t_app *d)
{
	int		i;

	i = d->args[e_num_philos];
	pthread_mutex_destroy(&d->death_lock);
	while (--i >= 0)
	{
		pthread_mutex_destroy(&d->philo_table[i].fork_lock);
	}
	free(d->philo_table);
}
