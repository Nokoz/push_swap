/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvardaki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 10:21:59 by gvardaki          #+#    #+#             */
/*   Updated: 2023/06/27 10:39:52 by gvardaki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	av = ft_check_arg(ac, av);
	ft_init_stack(&a, ac, av);
	if (ac == 2)
		ft_free(av);
	if (ft_is_sorted(a) == false)
		ft_sort(&a, &b);
	ft_free_stack(a);
	ft_free_stack(b);
	return (0);
}

char	**ft_check_arg(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		ft_error();
	if (ac == 2)
		av = ft_split(av[1], 32);
	while (av[i])
	{
		if (ft_is_valid(av[i]))
		{
			if (ft_not_duplicate(av, av[i], i))
			{
				i++;
				continue ;
			}
			else
				ft_error();
		}
		else
			ft_error();
		i++;
	}
	return (av);
}

void	ft_init_stack(t_stack **a, int ac, char **av)
{
	if (ac > 2)
		av++;
	while (*av)
	{
		ft_lstadd_new(a, ft_atoi(*av));
		++av;
	}
}

void	ft_sort(t_stack **a, t_stack **b)
{
	int	size_a;

	size_a = ft_stack_size(*a);
	if (size_a <= 3)
		ft_sort_3(a);
	else if (size_a <= 5)
		ft_sort_5(a, b);
	else
		ft_big_sort(a, b);
}

void	ft_big_sort(t_stack **a, t_stack **b)
{
	long	mid;

	mid = ft_mid(*a);
	while ((*a)->next->next->next->next->next != NULL)
	{
		if ((*a)->value >= (mid))
		{
			ft_push_p(a, b, 'b');
			mid = ft_mid(*a);
		}
		else
			ft_rotate_p(a, 'a');
	}
	ft_sort_5(a, b);
	while (*b)
	{
		ft_set_cheapest(*a, *b);
		ft_push_cheapest(a, b);
	}
	ft_first_top(a);
}
