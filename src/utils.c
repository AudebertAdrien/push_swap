/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:28:01 by aaudeber          #+#    #+#             */
/*   Updated: 2023/06/29 11:41:06 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
