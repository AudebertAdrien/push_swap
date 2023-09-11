/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:02:42 by aaudeber          #+#    #+#             */
/*   Updated: 2023/09/11 15:18:45 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_bit_max(t_list *lst)
{
	int	bit_len;
	int	i;
	int	mask;

	bit_len = 0;
	mask = 1;
	while (lst)
	{
		i = 0;
		while (i < 32)
		{
			if (mask << i & lst->index)
			{
				if (bit_len < i)
					bit_len = i;
			}
			i++;
		}
		lst = lst->next;
	}
	return (bit_len);
}

void	ft_sort(t_list **lst_a, t_list **lst_b)
{
	int	i;
	int	j;
	int	len;
	int	bit_len;
	unsigned int	mask;
	t_list	*s1;
	t_list	*s2;

	i = 0;
	mask = 1;
	len = ft_lstsize(*lst_a);

	ft_sort_and_index(*lst_a);

	bit_len = ft_find_bit_max(*lst_a);
	while (i <= bit_len)
	{
		j = 0;
		while (j < len)
		{
			s1 = *lst_a;
			s2 = s1->next;
			if (!(mask << i & s1->index))
				ft_lstpush("pb", lst_a, lst_b, 1);
			else
				ft_lstrotate("ra", lst_a, s1, s2, 1);
			j++;
		}
		while (*lst_b)
			ft_lstpush("pa", lst_b, lst_a, 1);
		i++;
	}
}
