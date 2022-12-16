/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 20:55:22 by znichola          #+#    #+#             */
/*   Updated: 2022/12/16 03:04:42 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

# define SUCCESS 0
# define FAILURE -1

# define FT_INT_MAX 2147483647
# define FT_INT_MIN -2147483648

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

typedef struct s_philo
{
	int		number;
	int		diet;
	int		eatt;
	int		sleept;
	int		meals;
	int		is_eating;
	int		my_fork; // should be a mutex
	t_bool	dead;
	struct s_philo *to_left;
}	t_philo;

typedef struct s_app
{
	int	philo_count;
	int	ttdie;
	int	tteat;
	int	ttsleep;
	int	meals;
}	t_app;


/* safe atoi */

int		safe_add(int *a, int b);
int		safe_multi(int *a, int b);
int		ft_safe_atoi(int *n, char *str);

/* debug */

void	print_philo(t_philo *p);
void	print_app(t_app *a);
void	print_log(t_app *a);



#endif /* philo */
