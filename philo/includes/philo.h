/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:55:22 by znichola          #+#    #+#             */
/*   Updated: 2023/02/24 15:39:27 by znichola         ###   ########.fr       */
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

/* philo */

int		can_i_eat(t_philo *p);
void	eating(t_philo *p);

/* init_philo */

/* input */

// int		input_check_assign(int ac, char **av, t_app *a);
int		validate_inputs(int ac, char **av, int args[5]);

/* safe atoi */

int		safe_add(int *a, int b);
int		safe_multi(int *a, int b);
int		ft_safe_atoi(int *n, char *str);

/* print */

void	print_log(int id, int msg);

/* debug */

// void	print_app(t_app *a);



#endif /* philo */
