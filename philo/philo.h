/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:55:22 by znichola          #+#    #+#             */
/*   Updated: 2022/12/16 00:12:06 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_philo
{
	
}	t_philo;

typedef struct s_app
{
	int	philo_num;
	int	ttdie;
	int	tteat;
	int	ttsleep;
	int	num_meals;
}	t_app;

#endif /* philo */
