/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_rev.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 09:32:12 by gvardaki          #+#    #+#             */
/*   Updated: 2023/06/21 16:12:11 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_reverse_rotate_p(t_stack **a, char c)
{
	ft_reverse_rotate(a);
	ft_printf("rr%c\n", c);
}

void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	if (!*stack || !(*stack)->next)
		return ;
	i = 0;
	tmp = *stack;
	while ((*stack)->next)
	{
		*stack = (*stack)->next;
		i++;
	}
	(*stack)->next = tmp;
	while (i > 1)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->next = NULL;
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_reverse_rotate(a);
	ft_reverse_rotate(b);
	ft_printf("rrr\n");
}
