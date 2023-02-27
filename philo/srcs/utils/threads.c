/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 00:43:57 by znichola          #+#    #+#             */
/*   Updated: 2023/02/27 22:14:01 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	give_back(pthread_mutex_t *m, int *thing)
{
	int	have_i_given_back_the_reasource;

	have_i_given_back_the_reasource = 1;
	while (have_i_given_back_the_reasource)
	{
		if (try_return(m, thing))
			have_i_given_back_the_reasource = 0;
	}
}

/*
	return 1 if was able reserve the reasource/thing

	reserving a reasrouce is flipping it to 1 if it's not alreay
	this way we tell all the other hungy threads that it's mine!
 */
int	try_reserve(pthread_mutex_t *m, int *thing)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(m);
	if (*thing == 0)
	{
		*thing = 1;
		ret = 1;
	}
	pthread_mutex_unlock(m);
	return (ret);
}

/*
	return 1 if was able return the reasource/thing

	returning a reasource is flipping it to 0 so others can use it
	This should theoretically never fail, but how knows.
 */
int	try_return(pthread_mutex_t *m, int *thing)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(m);
	if (*thing == 1)
	{
		*thing = 0;
		ret = 1;
	}
	pthread_mutex_unlock(m);
	return (ret);
}

/*
	return the state of the mutex
 */
int	get_mutex_state(pthread_mutex_t *m, int *thing)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(m);
	ret = *thing;
	pthread_mutex_unlock(m);
	return (ret);
}
