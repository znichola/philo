/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:06:57 by znichola          #+#    #+#             */
/*   Updated: 2023/02/24 11:19:19 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	primes[10] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};

void	*routine(void *arg)
{
	int	index;

	index = *(int*)arg;
	printf("%d ", primes[index]);
}

int	main(int argc, char **argv)
{
	pthread_t	th[10];
	int			i;

	i = -1;
	while (i++ < 10)
	{
		if (pthread_create(&th[i], NULL, &routine, &i) != 0)
			perror("Failed to creat thread");
	}
	i = -1;
	while (i++ < 10)
	{
		if (pthread_join(th[i], NULL) != 0)
			perror("Failed to join thread");
	}
}
