/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:02:42 by aaudeber          #+#    #+#             */
/*   Updated: 2023/05/29 14:10:47 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_list **lst_a, t_list **lst_b)
{
	int	i;
	int	j;
	int	len;
	unsigned int	mask;
	t_list	*s1;
	t_list	*s2;
	t_list	*tmp;

	i = 0;
	j = 0;
	mask = 1;
	tmp = *lst_a;
	len = ft_lstsize(*lst_a);
	ft_putnbr_fd(len, 1);
	printf("\n");
	while (j < 8)
	{
		while (i < len)
		{
			//printf("%p\n", *lst_a);
			s1 = *lst_a;
			s2 = s1->next;
			if (mask << j & s1->nb)
			{
				/*
				ft_putstr_fd("1 : ", 1);
				ft_putnbr_fd((*lst_a)->nb, 1);
				ft_putchar_fd('\n', 1);
				*/
				ft_lstpush("pb", lst_a, lst_b);
			}
			else
			{
				/*
				ft_putstr_fd("0 : ", 1);
				ft_putnbr_fd((*lst_a)->nb, 1);
				ft_putchar_fd('\n', 1);
				*/
				ft_lstrotate("ra", lst_a, s1, s2);
			}
			i++;
		}
		while (*lst_b)
		{
			ft_lstpush("pa", lst_b, lst_a);
		}
		printf("\n");
		i = 0;
		j++;
	}
}
