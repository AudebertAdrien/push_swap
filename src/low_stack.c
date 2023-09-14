/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:17:31 by motoko            #+#    #+#             */
/*   Updated: 2023/09/14 16:46:08 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_three(t_list **lst_a)
{
	t_list	*n1;
	t_list	*n2;
	t_list	*n3;

	n1 = *lst_a;
	n2 = (*lst_a)->next;
	n3 = (*lst_a)->next->next;
	if (n1->index > n2->index && n2->index < n3->index && n1->index < n3->index)
		ft_lstswap("sa", lst_a, n1, n2, 1);
	if (n1->index > n2->index && n1->index > n3->index && n2->index > n3->index)
	{
		ft_lstswap("sa", lst_a, n1, n2, 1);
		ft_lstrotate_reversed("rra", lst_a, ft_lstlast(*lst_a), ft_lstsize(*lst_a), 1);
	}
	if (n1->index > n2->index && n1->index > n3->index && n2->index < n3->index)
		ft_lstrotate("ra", lst_a, n1, n2, 1);
	if (n1->index < n2->index && n1->index < n3->index && n2->index > n3->index)
	{
		ft_lstswap("sa", lst_a, n1, n2, 1);
		ft_lstrotate("ra", lst_a, *lst_a, (*lst_a)->next, 1);
	}
	if (n1->index < n2->index && n1->index > n3->index && n2->index > n3->index)
		ft_lstrotate_reversed("rra", lst_a, ft_lstlast(*lst_a), ft_lstsize(*lst_a), 1);
	return (0);
}

int	sort_b(t_list **lst_b)
{
	t_list	*n1;
	t_list	*n2;

	n1 = *lst_b;
	n2 = (*lst_b)->next;
	if (!n2)
		return (0);
	if (n1->index > n2->index)
		ft_lstrotate("rb", lst_b, n1, n2, 1);
	return (0);
}

int	is_max(t_list *lst_a)
{
	int	max;

	max = 0;
	while (lst_a)
	{
		if (lst_a->nb > max)
			max = lst_a->nb;
		lst_a = lst_a->next;
	}
	return (max);
}

int	sort_4_and_5(t_list **lst_a, t_list **lst_b)
{
	while (*lst_a && *lst_b)
	{
		if ((*lst_b)->index < (*lst_a)->index)
			ft_lstpush("pa", lst_b, lst_a, 1);
		else if ((*lst_a)->nb == is_max(*lst_a))
		{
			ft_lstrotate("ra", lst_a, *lst_a, (*lst_a)->next, 1);
			ft_lstpush("pa", lst_b, lst_a, 1);
		}
		else
			ft_lstrotate("ra", lst_a, *lst_a, (*lst_a)->next, 1);
	}
	return (0);
}

int	ft_low_stack(t_list **lst_a, t_list **lst_b)
{
	if (ft_lstsize(*lst_a) == 3)
		ft_three(lst_a);
	if (ft_lstsize(*lst_a) == 4 || ft_lstsize(*lst_a) == 5)
	{
		if (ft_lstsize(*lst_a) == 5)
			ft_lstpush("pb", lst_a, lst_b, 1);
		ft_lstpush("pb", lst_a, lst_b, 1);
		ft_three(lst_a);
		sort_b(lst_b);
		sort_4_and_5(lst_a, lst_b);
		while (!is_sorted(*lst_a))
			ft_lstrotate("ra", lst_a, *lst_a, (*lst_a)->next, 1);
	}
	return (0);
}
