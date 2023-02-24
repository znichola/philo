/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:03:49 by znichola          #+#    #+#             */
/*   Updated: 2023/02/24 15:40:25 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* functions a philo thread can do */

#include "philo.h"

int	can_i_eat(t_philo *p)
{
	int	ret;

	ret = SUCCESS;
	(void)p;
	return (ret);
}

void	eating(t_philo *p)
{
	(void)p;
}
