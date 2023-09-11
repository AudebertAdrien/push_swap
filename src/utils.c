/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:28:01 by aaudeber          #+#    #+#             */
/*   Updated: 2023/09/11 15:17:40 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_and_index(t_list *lst)
{
	t_list *l1;
	t_list *l2;

	l1 = lst;
	while (l1)
	{
		l1->index = 1;	
		l2 = lst;
		while (l2)
		{
			if (l1->nb > l2->nb)
				l1->index += 1;
			l2 = l2->next;
		}
		l1 = l1->next;
	}
}

int		is_sorted(t_list *lst)
{
	while (lst->next)
	{
		if ((lst)->nb > (lst)->next->nb)
			return (0);
		lst = (lst)->next;
	}
	return (1);
}

void	ft_print_lst(t_list *lst)
{
	ft_printf("////// print_lst \\\\\\\\\\\\ \n");
	while (lst)
	{
		ft_printf("p_lst : %p => ", lst);
		ft_printf("nb : %d\n", (lst)->nb);
		lst = (lst)->next;
	}
}

void	ft_print_lst_index(t_list *lst)
{
	ft_printf("\n////// print_index \\\\\\\\\\\\ \n");
	while (lst)
	{
		ft_printf("p_lst : %p => ", lst);
		ft_printf("index : %d\n", lst->index);
		lst = lst->next;
	}
}
