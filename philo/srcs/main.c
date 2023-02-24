/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:55:41 by znichola          #+#    #+#             */
/*   Updated: 2023/02/24 16:31:28 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{

	t_app	data;

	if (validate_inputs(argc, argv, data.args))
		return (1);
	launch_all_philos(&data);
	wait_all_philos(&data);
	cleanup_philos(&data);
	return (0);
}
