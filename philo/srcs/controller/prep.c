/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prep.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:57:23 by znichola          #+#    #+#             */
/*   Updated: 2023/02/24 21:11:25 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	prep_philo(int id, t_app *d, t_philo *left);
static void	set_left(t_app *d);

int	prep_all_philos(t_app *d)
{
	int		i;
	t_philo	*to_left;

	i = d->args[e_num_philos];
	d->philo_table = malloc(sizeof(t_philo *) * d->args[e_num_philos]);
	if (d->philo_table == NULL)
		return (FATAL_ERROR);
	to_left = NULL;
	while (--i >= 0)
	{
		if (prep_philo(i, d, to_left))
			return (FATAL_ERROR);
	}
	set_left(d);
	return (0);
}

static int	prep_philo(int id, t_app *d, t_philo *left)
{
	t_philo	*ret;

	ret = philo_factory(&(t_philo){.id_number=id,
					.eat_time=d->args[e_time_to_eat],
					.sleep_time=d->args[e_time_to_sleep],
					.time_to_die=d->args[e_time_to_die],
					.meals_left=d->args[e_n_of_meals],
					.to_left=left});
	if (ret == NULL)
		return (FATAL_ERROR);
	d->philo_table[id] = *ret;
	return (0);
}

static void	set_left(t_app *d)
{
	t_philo	*last;
	int	i;

	i = d->args[e_num_philos];
	last = &d->philo_table[0];
	while (--i >= 0)
	{
		d->philo_table[i].to_left = last;
		last = &d->philo_table[i];
	}
}
