/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:19:15 by znichola          #+#    #+#             */
/*   Updated: 2023/02/24 16:33:50 by znichola         ###   ########.fr       */
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
		else
			printf("joined thread #%d\n", i);

	}
	return (0);
}
