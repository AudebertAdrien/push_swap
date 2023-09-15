/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 13:54:48 by aaudeber          #+#    #+#             */
/*   Updated: 2023/09/15 15:22:07 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstswap_a(t_list **lst, t_list *s1, t_list *s2, int id)
{
	*lst = s2;
	s1->next = s2->next;
	s2->next = s1;
	if (id == 1)
		ft_printf("sa\n");
	return (1);
}

int	ft_lstswap_b(t_list **lst, t_list *s1, t_list *s2, int id)
{
	*lst = s2;
	s1->next = s2->next;
	s2->next = s1;
	if (id == 1)
		ft_printf("sb\n");
	return (1);
}

int	ft_lstpush_a(t_list **t1, t_list **t2, int id)
{
	t_list	*tmp;

	tmp = *t2;
	*t2 = *t1;
	*t1 = (*t1)->next;
	(*t2)->next = tmp;
	if (id == 1)
		ft_printf("pa\n");
	return (1);
}

int	ft_lstpush_b(t_list **t1, t_list **t2, int id)
{
	t_list	*tmp;

	tmp = *t2;
	*t2 = *t1;
	*t1 = (*t1)->next;
	(*t2)->next = tmp;
	if (id == 1)
		ft_printf("pb\n");
	return (1);
}
