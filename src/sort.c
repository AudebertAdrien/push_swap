/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:02:42 by aaudeber          #+#    #+#             */
/*   Updated: 2023/09/13 18:17:08 by motoko           ###   ########.fr       */
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

void	radix(t_list **lst_a, t_list **lst_b, int len, int bit_len)
{
	int	i;
	int	j;
	t_list	*s1;
	t_list	*s2;

	i = 0;
	while (i <= bit_len)
	{
		j = 0;
		while (j < len)
		{
			s1 = *lst_a;
			s2 = (*lst_a)->next;
			if (!(1 << i & s1->index))
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

void	ft_sort(t_list **lst_a, t_list **lst_b)
{
	int	len;
	int	bit_len;

	len = ft_lstsize(*lst_a);
	bit_len = ft_find_bit_max(*lst_a);
	radix(lst_a, lst_b, len, bit_len);
}
