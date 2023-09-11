/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   low_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 14:17:31 by motoko            #+#    #+#             */
/*   Updated: 2023/09/11 17:42:00 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_three(t_list **lst_a, t_list **lst_b)
{
	t_list	*n1;
	t_list	*n2;
	t_list	*n3;

	n1 = *lst_a;
	n2 = (*lst_a)->next;
	n3 = (*lst_a)->next->next;

	(void)lst_b;
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

int	find_pos(t_list **lst_a);			
{
	t_list	*tmp;

	while (*tmp)
	{
		tmp = (*tmp)->next;
	}
	return (0);
}

int	ft_five(t_list **lst_a, t_list **lst_b)
{
	t_list	*n1;
	t_list	*n2;

	n1 = *lst_a;
	n2 = (*lst_a)->next;
	
	ft_lstpush("pb", lst_a, lst_b, 1);	
	ft_lstpush("pb", lst_a, lst_b, 1);	
	ft_three(lst_a, lst_b);
	ft_lstpush("pa", lst_a, lst_b, 1);	
	find_pos(lst_a);			
	return (0);
}

int	ft_low_stack(t_list **lst_a, t_list **lst_b)
{
	if (ft_lstsize(*lst_a) == 3)
		ft_three(lst_a, lst_b);
	if (ft_lstsize(*lst_a) == 5)
		ft_five(lst_a, lst_b);
	return (0);
}
