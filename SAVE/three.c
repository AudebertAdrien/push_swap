/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 15:17:05 by aaudeber          #+#    #+#             */
/*   Updated: 2023/06/08 15:17:45 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list *lst_a)
{
	while (lst_a->next)
	{
		printf("p : %p\n", lst_a);
		if (lst_a->nb > lst_a->next->nb)
		{
			printf("%d > %d\n", lst_a->nb, lst_a->next->nb);
			return (1);
		}
		lst_a = lst_a->next;
	}
	return (0);
}

int	ft_turc_sort(t_list **lst_a, t_list **lst_b)
{
	int		len_a;
	int		count;
	int		last_nb;

	count = 0;
	len_a = ft_lstsize(*lst_a);
	(void)lst_b;
	if (len_a <= 4)
	{
		while (is_sorted(*lst_a))	
		{
			last_nb = ft_lstlast(*lst_a)->nb;
			if ((*lst_a)->nb < last_nb && (*lst_a)->nb < (*lst_a)->next->nb)
			{
				count += ft_lstswap("sa", lst_a, *lst_a, (*lst_a)->next);
				count += ft_lstrotate("ra", lst_a, *lst_a, (*lst_a)->next);	
			}

			if ((*lst_a)->nb < last_nb && (*lst_a)->nb > (*lst_a)->next->nb)
				count += ft_lstswap("sa", lst_a, *lst_a, (*lst_a)->next);

			if ((*lst_a)->nb > last_nb && (*lst_a)->nb < (*lst_a)->next->nb)
				count += ft_lstswap("sa", lst_a, *lst_a, (*lst_a)->next);

			if((*lst_a)->nb > (*lst_a)->next->nb && (*lst_a)->nb > (*lst_a)->next)
				count += ft_lstrotate_reversed("rra", lst_a, ft_lstlast(*lst_a);	

		}
		printf("count : %d\n", count);
	}
	return (0);
}
