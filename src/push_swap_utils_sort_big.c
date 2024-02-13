/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_sort_big.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:27:52 by gvardaki          #+#    #+#             */
/*   Updated: 2023/06/21 14:55:29 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_sort_5(t_stack **a, t_stack **b)
{
	int	push;

	push = 0;
	while (ft_stack_size(*a) > 3 && ft_is_sorted(*a) == false)
	{
		if (ft_lst_tail(*a) == ft_smallest(*a))
			ft_reverse_rotate_p(a, 'a');
		else if (*a == ft_smallest(*a))
		{
			ft_push_p(a, b, 'b');
			push++;
		}
		else
			ft_rotate_p(a, 'a');
	}
	ft_sort_3(a);
	while (push > 0)
	{
		ft_push_p(b, a, 'a');
		push--;
	}
}

int	ft_full_value(t_stack *stack)
{
	int	total;

	total = 0;
	while (stack)
	{
		total = total + stack->value;
		stack = stack->next;
	}
	return (total);
}

void	ft_set_position(t_stack *stack)
{
	int	position;
	int	mid;

	position = 0;
	mid = (ft_stack_size(stack) / 2);
	while (stack)
	{
		stack->position = position;
		stack->cheapest = false;
		if (position <= mid)
			stack->above_mid = true;
		else
			stack->above_mid = false;
		position++;
		stack = stack->next;
	}
}

void	ft_target(t_stack *a, t_stack *b)
{
	t_stack	*target;
	t_stack	*tmp;
	long	best;

	while (b)
	{
		tmp = a;
		best = LONG_MAX;
		while (tmp)
		{
			if (tmp->value > b->value && tmp->value < best)
			{
				target = tmp;
				best = tmp->value;
			}
		tmp = tmp->next;
		}
		if (best == LONG_MAX)
			b->target = ft_smallest(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	ft_cost(t_stack *a, t_stack *b)
{
	int	size_a;
	int	size_b;

	size_a = ft_stack_size(a);
	size_b = ft_stack_size(b);
	while (b)
	{
		b->push_cost = b->position;
		if (!(b->above_mid))
			b->push_cost = size_b - (b->position);
		if (!(b->target->above_mid))
			b->push_cost += size_a - (b->target->position);
		else
			b->push_cost += b->target->position;
		b = b->next;
	}
}
