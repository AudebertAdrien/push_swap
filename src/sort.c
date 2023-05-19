/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:02:42 by aaudeber          #+#    #+#             */
/*   Updated: 2023/05/19 19:28:09 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_list **lst_a, t_list **lst_b)
{
	//t_list	*begin;
	t_list	*tmp;
	t_list	*s1;
	t_list 	*s2;
	int	i = 0;
	
	//begin = *lst_a;
	(void)lst_b;
	//while (*lst_a && (*lst_a)->next)
	while (i < ft_lstsize(*lst_a) - 1)
	{
		s1 = *lst_a;
		s2 = s1->next;
		if (s2 && s1->nb > s2->nb)
		{
			ft_printf("%d : %d\n", s1->nb, s2->nb);
			//ft_lstswap("sa", lst_a);
			ft_lstswap("sa", lst_a, *lst_a, (*lst_a)->next);
			//ft_lstpush("pb", lst_a, lst_b);
		}
		ft_lstrotate("ra", lst_a, *lst_a, (*lst_a)->next);
		i++;
		//*lst_a = (*lst_a)->next;
	}
	ft_lstrotate("ra", lst_a, *lst_a, (*lst_a)->next);
	//*lst_a = begin;
}
