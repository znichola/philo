/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znichola <znichola@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 00:41:01 by znichola          #+#    #+#             */
/*   Updated: 2022/12/16 01:15:21 by znichola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_biga(int *a, int b)
{
	if (b == 0 || *a == 0)
	{
		*a = 0;
		return (SUCCESS);
	}
	if (*a > 0)
	{
		if (b > 0)
		{
			if (*a > (FT_INT_MAX / b))
				return (FAILURE);
		}
		else
			if ((b < 0) && b < (FT_INT_MIN / *a))
				return (FAILURE);
	}
	return (SUCCESS);
}

static int	check_bigb(int *a, int b)
{
	if (!(*a > 0))
	{
		if (b > 0)
		{
			if (*a < (FT_INT_MIN / b))
				return (FAILURE);
		}
		else
			if (b < (FT_INT_MAX / *a))
				return (FAILURE);
	}
	return (SUCCESS);
}

int	safe_multi(int *a, int b)
{
	if (b == 0 || *a == 0)
	{
		*a = 0;
		return (SUCCESS);
	}
	if (check_biga(a, b) == FAILURE)
		return (FAILURE);
	if (check_bigb(a, b) == FAILURE)
		return (FAILURE);
	*a = *a * b;
	return (SUCCESS);
}

int	safe_add(int *a, int b)
{
	if (a > 0 && b > FT_INT_MAX - *a)
		return (FAILURE);
	else if (a < 0 && b < FT_INT_MIN - *a)
		return (FAILURE);
	*a = *a + b;
	return (SUCCESS);
}

int	ft_safe_atoi(int *n, char *str)
{
	int	s;

	*n = 0;
	s = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n'
		|| *str == '\r' || *str == '\t' || *str == '\v')
		(*str)++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			s = -1;
		str++;
	}
	if (!(*str >= '0' && *str <= '9'))
		return (FAILURE);
	while (*str >= '0' && *str <= '9')
	{
		if (!(safe_multi(n, 10) + safe_add(n, *str - '0') == SUCCESS))
			return (FAILURE);
		str++;
	}
	if (!(*str == ' ' || *str == '\0'))
		return (FAILURE);
	safe_multi(n, s);
	return (SUCCESS);
}