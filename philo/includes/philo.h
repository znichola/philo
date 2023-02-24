/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:55:22 by znichola          #+#    #+#             */
/*   Updated: 2023/02/24 16:39:38 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>

# include "structs.h"
# include "defines.h"

int      can_i_eat(t_philo *p);
void     cleanup_philos(t_app *d);
void     eating(t_philo *p);
int      ft_safe_atoi(int *n, char *str);
int      launch_all_philos(t_app *d);
t_philo  *philo_factory(t_philo *blueprint);
void     print_log(int id, int msg);
void     *roll_dice();
void     *routine(void *arg);
void     *routine();
int      safe_add(int *a, int b);
int      safe_multi(int *a, int b);
int      validate_inputs(int ac, char **av, int args[5]);
int      wait_all_philos(t_app *d);

#endif /* philo */
