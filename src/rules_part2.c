/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_part2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 18:40:41 by aaudeber          #+#    #+#             */
/*   Updated: 2023/09/14 18:43:05 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstrotate_a(t_list **lst, t_list *s1, t_list *s2, int id)
{
	if (!s2)
		return (0);
	*lst = s2;
	s1->next = NULL;
	ft_lstadd_back(lst, s1);
	if (id == 1)
		ft_printf("ra\n");
	return (1);
}

int	ft_lstrotate_b(t_list **lst, t_list *s1, t_list *s2, int id)
{
	if (!s2)
		return (0);
	*lst = s2;
	s1->next = NULL;
	ft_lstadd_back(lst, s1);
	if (id == 1)
		ft_printf("rb\n");
	return (1);
}

int	ft_lstrotate_ra(t_list **lst, t_list *last, int size, int id)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *lst;
	while (i < size - 2)
	{
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
	ft_lstadd_front(lst, last);
	if (id == 1)
		ft_printf("rra\n");
	return (1);
}

int	ft_lstrotate_rb(t_list **lst, t_list *last, int size, int id)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = *lst;
	while (i < size - 2)
	{
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
	ft_lstadd_front(lst, last);
	if (id == 1)
		ft_printf("rrb\n");
	return (1);
}
