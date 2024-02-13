/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_sort_cheapest.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 09:56:22 by gvardaki          #+#    #+#             */
/*   Updated: 2023/06/21 10:10:11 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_cheapest(t_stack *b)
{
	int		best;
	t_stack	*best_node;

	if (!b)
		return ;
	best = INT_MAX;
	while (b)
	{
		if (b->push_cost < best)
		{
			best = b->push_cost;
			best_node = b;
		}
		if (best < 3)
			break ;
		b = b->next;
	}
	best_node->cheapest = true;
}

void	ft_set_cheapest(t_stack *a, t_stack *b)
{
	ft_set_position(a);
	ft_set_position(b);
	ft_target(a, b);
	ft_cost(a, b);
	ft_cheapest(b);
}

t_stack	*ft_get_cheapest(t_stack *stack)
{
	t_stack	*cheapest_node;

	cheapest_node = NULL;
	while (stack)
	{
		if (stack->cheapest == true)
		{
			cheapest_node = stack;
			break ;
		}
		stack = stack->next;
	}
	return (cheapest_node);
}

void	ft_push_cheapest(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = ft_get_cheapest(*b);
	if (cheapest_node->above_mid && cheapest_node->target->above_mid)
		ft_double_rot(a, b, cheapest_node, false);
	if (!(cheapest_node->above_mid) && !(cheapest_node->target->above_mid))
		ft_double_rot(a, b, cheapest_node, true);
	ft_topping_node(b, cheapest_node, 'b');
	ft_topping_node(a, cheapest_node->target, 'a');
	ft_push_p(b, a, 'a');
}
