/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:02:42 by aaudeber          #+#    #+#             */
/*   Updated: 2023/05/30 16:28:54 by aaudeber         ###   ########.fr       */
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
				//if (bit_len < i)
					bit_len = i;
			}
			i++;
		}
		lst = lst->next;
	}
	return (bit_len);
}


void	ft_print_lst_index(t_list *lst)
{
	ft_printf("\n////// INDEX \\\\\\\\\\\\ \n");
	while (lst)
	{
		ft_printf("p_lst : %p => ", lst);
		ft_printf("index : %d\n", lst->index);
		lst = lst->next;
	}
}

void	ft_sort_and_index(t_list *lst)
{
	t_list *l1;
	t_list *l2;

	l1 = lst;
	while (l1)
	{
		l2 = lst;
		l1->index = 1;	
		while (l2)
		{
			if (l1->nb > l2->nb)
				l1->index += 1;
			l2 = l2->next;
		}
		l1 = l1->next;
	}
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
	j = 0;
	mask = 1;
	len = ft_lstsize(*lst_a);

	ft_sort_and_index(*lst_a);
	ft_print_lst_index(*lst_a);

	bit_len = ft_find_bit_max(*lst_a);
	printf("\n?==%d==?\n", bit_len);
	while (j <= bit_len)
	{
		while (i < len)
		{
			s1 = *lst_a;
			s2 = s1->next;
			if (mask << j & s1->index)
				ft_lstpush("pb", lst_a, lst_b);
			else
				ft_lstrotate("ra", lst_a, s1, s2);
			i++;
		}
		while (*lst_b)
			ft_lstpush("pa", lst_b, lst_a);
		printf("\n");
		i = 0;
		j++;
	}
}
