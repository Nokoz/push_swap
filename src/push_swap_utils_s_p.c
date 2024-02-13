/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_move.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 13:08:48 by gvardaki          #+#    #+#             */
/*   Updated: 2023/06/19 10:14:40 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_swap(t_stack **a)
{
	t_stack	*previous;
	t_stack	*current;
	t_stack	*next;

	previous = NULL;
	current = *a;
	next = (*a)->next;
	current->prev = next;
	current->next = next->next;
	next->prev = NULL;
	next->next = current;
	*a = next;
}

void	ft_swap_p(t_stack **a, char stack)
{
	ft_swap(a);
	ft_printf("s%c\n", stack);
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_swap(a);
	ft_swap(b);
	ft_printf("ss\n");
}

void	ft_push_p(t_stack **from, t_stack **to, char dest)
{
	ft_push(from, to);
	ft_printf("p%c\n", dest);
}

void	ft_push(t_stack **from, t_stack **to)
{
	t_stack	*top_from;

	top_from = *from;
	*from = (*from)->next;
	if (*to != NULL)
	{
		(*to)->prev = top_from;
	}
	top_from->next = *to;
	top_from->prev = NULL;
	*to = top_from;
}
