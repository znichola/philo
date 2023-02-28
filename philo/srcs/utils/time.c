/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 22:13:45 by znichola          #+#    #+#             */
/*   Updated: 2023/02/27 22:59:21 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time_in_ms(void)
{
	struct timeval		now;
	long long			ret;

	gettimeofday(&now, NULL);
	ret = ((long long)now.tv_sec) * 1000;
	ret += ((long long)now.tv_usec) / 1000;
	return (ret);
}

int	get_time_since_start(void)
{
	struct timeval		now;
	static long long	start;
	long long			ret;

	gettimeofday(&now, NULL);
	if (start == 0)
	{
		start = ((long long)now.tv_sec) * 1000;
		start += ((long long)now.tv_usec) / 1000;
		return (0);
	}
	ret = ((long long)now.tv_sec) * 1000;
	ret += ((long long)now.tv_usec) / 1000;
	ret -= start;
	return (ret);
}
