/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_sort_moves.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 10:12:41 by gvardaki          #+#    #+#             */
/*   Updated: 2023/06/21 16:17:53 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_double_rot(t_stack **a, t_stack **b, t_stack *cheapest_node,
	bool rev)
{
	while ((*b != cheapest_node) && (*a != cheapest_node->target))
	{
		if (rev == false)
			ft_rr(a, b);
		else if (rev == true)
			ft_rrr(a, b);
	}
	ft_set_position(*a);
	ft_set_position(*b);
}

void	ft_topping_node(t_stack **stack, t_stack *to_top, char c)
{
	while (*stack != to_top)
	{
		if (to_top->above_mid)
			ft_rotate_p(stack, c);
		else
			ft_reverse_rotate_p(stack, c);
	}
	ft_set_position(*stack);
}

void	ft_first_top(t_stack **a)
{
	t_stack	*first;

	ft_set_position(*a);
	first = ft_smallest(*a);
	if (first->above_mid)
		while (*a != first)
			ft_rotate_p(a, 'a');
	else
		while (*a != first)
			ft_reverse_rotate_p(a, 'a');
}

long	ft_mid(t_stack *a)
{
	long	mid;
	int		size;
	int		i;

	mid = 0;
	i = 0;
	size = ft_stack_size(a);
	while (a)
	{
		mid *= i;
		mid += a->value;
		i++;
		mid /= i;
		a = a->next;
	}
	return (mid);
}
