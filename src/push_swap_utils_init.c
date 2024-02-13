/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_init.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/07 13:06:29 by gvardaki          #+#    #+#             */
/*   Updated: 2023/06/27 09:52:25 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ft_lstadd_new(t_stack **a, int value)
{
	t_stack	*new;
	t_stack	*last;

	if (a == NULL)
		return ;
	new = malloc(sizeof(t_stack));
	if (!new)
		ft_free_error(*a);
	new->next = NULL;
	new->value = value;
	if (*a == NULL)
	{
		*a = new;
		new->prev = NULL;
	}
	else
	{
		last = ft_lst_tail(*a);
		last->next = new;
		new->prev = last;
	}
}

t_stack	*ft_lst_tail(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_free_error(t_stack *lst)
{
	t_stack	*tmp;

	tmp = NULL;
	while (lst->next)
	{
		tmp = lst->next;
		free(lst);
		lst->next = tmp;
	}
	ft_error();
}

void	ft_free_stack(t_stack *lst)
{
	t_stack	*tmp;

	tmp = NULL;
	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}

void	ft_free(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		free(av[i]);
		i++;
	}
}
