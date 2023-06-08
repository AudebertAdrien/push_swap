/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 16:40:57 by aaudeber          #+#    #+#             */
/*   Updated: 2023/06/07 13:55:57 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_insertion_sort(t_list **lst_a, t_list **lst_b)
{
	int		len_a;
	int		len_b;

	len_a = ft_lstsize(*lst_a);
	while (*lst_a)
	{
		if (!(*lst_b))
			ft_lstpush("pb", lst_a, lst_b);

		len_b = ft_lstsize(*lst_b);
		printf("len_b : %d\n", len_a);
		while (len_b > 0)
		{
			ft_printf("a vs b : %d | %d =>", (*lst_a)->nb, (*lst_b)->nb);
			ft_printf("bool : %d\n", (*lst_a)->nb > (*lst_b)->nb);

			if ((*lst_a)->nb > (*lst_b)->nb)
			{
				ft_printf("push : %d\n", (*lst_a)->nb);
				ft_lstpush("pb", lst_a, lst_b);
			}
			else
			{
				ft_printf("rotate : %d\n", (*lst_a)->nb);
				ft_lstrotate("rb", lst_b, *lst_b, (*lst_b)->next);
			}
			len_b--;
		}
		
		//if (*lst_a && (*lst_a)->next)
		ft_lstrotate("ra", lst_a, *lst_a, (*lst_a)->next);
		len_a--;
	}
	return (0);
}
