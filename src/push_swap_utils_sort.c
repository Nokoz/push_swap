/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_sort.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 10:05:28 by gvardaki          #+#    #+#             */
/*   Updated: 2023/06/21 14:26:17 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	ft_is_sorted(t_stack *a)
{
	while (a->next)
	{
		if (a->value > a->next->value)
			return (false);
		a = a->next;
	}
	return (true);
}

int	ft_stack_size(t_stack *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

void	ft_sort_3(t_stack **a)
{
	while (ft_is_sorted(*a) == false)
	{
		if (*a == ft_highest(*a))
			ft_rotate_p(a, 'a');
		else if ((*a)->value > (*a)->next->value)
			ft_swap_p(a, 'a');
		else if ((*a)->next == ft_highest(*a))
			ft_reverse_rotate_p(a, 'a');
	}
}

t_stack	*ft_highest(t_stack *stack)
{
	t_stack	*highest;
	int		max;

	highest = stack;
	max = highest->value;
	while (stack)
	{
		if (stack->value > max)
		{
			highest = stack;
			max = stack->value;
		}
		stack = stack->next;
	}
	return (highest);
}

t_stack	*ft_smallest(t_stack *stack)
{
	t_stack	*smallest;
	int		min;

	smallest = stack;
	min = smallest->value;
	while (stack)
	{
		if (stack->value < min)
		{
			smallest = stack;
			min = stack->value;
		}
		stack = stack->next;
	}
	return (smallest);
}
