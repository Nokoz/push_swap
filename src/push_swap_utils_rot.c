/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_move_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 14:26:06 by gvardaki          #+#    #+#             */
/*   Updated: 2023/06/21 11:47:45 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_rotate_p(t_stack **stack, char c)
{
	ft_rotate(stack);
	ft_printf("r%c\n", c);
}

void	ft_rotate(t_stack **stack)
{
	t_stack	*tail;
	t_stack	*head;

	head = *stack;
	*stack = (*stack)->next;
	tail = ft_lst_tail(*stack);
	tail->next = head;
	head->prev = tail;
	head->next = NULL;
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_rotate(a);
	ft_rotate(b);
	ft_printf("rr\n");
}
