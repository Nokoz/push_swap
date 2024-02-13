/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_arg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:02:12 by gvardaki          #+#    #+#             */
/*   Updated: 2023/06/27 10:31:39 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_is_valid(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	if (ft_is_int(str) == 0)
		return (0);
	return (1);
}

int	ft_is_int(char *str)
{
	int		i;
	long	nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = 1;
		i++;
	}
	while (str[i])
	{
		nbr = nbr * 10 + str[i] - 48;
		if (nbr > INT_MAX)
			return (0);
		i++;
	}
	return (ft_check_max(nbr, sign));
}

int	ft_check_max(long nbr, int sign)
{
	if (sign == 0)
	{
		if (nbr > INT_MAX)
			return (0);
	}
	else if (sign == 1)
	{
		if (nbr < INT_MIN)
			return (0);
	}
	return (1);
}

int	ft_not_duplicate(char **list, char *item, int index)
{
	int	i;

	i = 1;
	while (i < index)
	{
		if (ft_atoi(item) == ft_atoi(list[i]))
			return (0);
		i++;
	}
	return (1);
}
