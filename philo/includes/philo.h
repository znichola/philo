/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:55:22 by znichola          #+#    #+#             */
/*   Updated: 2023/02/25 15:39:54 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>

# include "structs.h"
# include "defines.h"

void     cleanup_philos(t_app *d);
int      ft_safe_atoi(int *n, char *str);
int      launch_all_philos(t_app *d);
int		philo_factory(t_philo *p, t_philo *blueprint);
void     print_log(int id, int msg);
void     print_philo(t_philo *p);
void     *routine(void *philo);
int      safe_add(int *a, int b);
int      safe_multi(int *a, int b);
int      validate_inputs(int ac, char **av, int args[5]);
int      wait_all_philos(t_app *d);
int	prep_all_philos(t_app *d);
int	thinking_and_eating(t_philo *p);
int		do_activity(t_philo *p, int sleep_in_ms);
int		launch_deathtimer(pthread_t *death_timer, t_philo *p);
void	give_back(pthread_mutex_t *m, int *thing);
int		try_reserve(pthread_mutex_t *m, int *thing);
int		try_return(pthread_mutex_t *m, int *thing);
long long ret_time_in_ms(void);
int	get_mutex_state(pthread_mutex_t *m, int *thing);

#endif /* philo */
