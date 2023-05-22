/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:02:42 by aaudeber          #+#    #+#             */
/*   Updated: 2023/05/22 17:56:38 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
void	ft_sort(t_list **lst_a, t_list **lst_b)
{
	int	i;
	int	mask;
	t_list	*start;
	t_list	*tmp;

	i = 0;
	mask = 1;
	start = *lst_a;
	while (i < 8)
	{
		while (start)
		{
			printf("\nstart / tmp : %p / %p\n", start, tmp);
			if (mask << i & (*lst_a)->nb)
			{
				printf("1\n");
				//ft_lstpush("pb", lst_a, lst_b);
				//ft_lstswap("sa", lst_a, *lst_a, (*lst_a)->next);
			}
			else
			{
				printf("0");
			}
			printf("\n////\n");
			*lst_a = (*lst_a)->next; 
			printf("\nstart / tmp : %p / %p\n", start, tmp);
		}
		*lst_a = tmp;
		printf("\n");
		i++;
	}
}
*/

void	ft_sort(t_list **lst_a, t_list **lst_b)
{
	int	i;
	int	mask;
	t_list	*tmp;

	i = 0;
	mask = 1;
	tmp = *lst_a;
	while (i < 8)
	{
		while (tmp)
		{
			printf("\nP1 : %p \n", tmp);
			if (mask << i & (*lst_a)->nb)
			{
				printf("1");
			}
			else
			{
				printf("0");
				//ft_lstrotate("ra", lst_a, *lst_a, (*lst_a)->next);
			}
			tmp = tmp->next;
			printf("\nP2 : %p \n", tmp);
			printf("\n////\n");
		}
		tmp = *lst_a;
		printf("\n");
		i++;
	}
}

/*
void	ft_sort(t_list **lst_a, t_list **lst_b)
{
	t_list	*tmp;
	t_list	*s1;
	t_list 	*s2;
	int	i = 0;
	
	(void)lst_b;
	while (i < ft_lstsize(*lst_a) - 1)
	{
		s1 = *lst_a;
		s2 = s1->next;
		if (s2 && s1->nb > s2->nb)
		{
			ft_printf("%d : %d\n", s1->nb, s2->nb);
			ft_lstswap("sa", lst_a, *lst_a, (*lst_a)->next);
		}
		ft_lstrotate("ra", lst_a, *lst_a, (*lst_a)->next);
		i++;
	}
	ft_lstrotate("ra", lst_a, *lst_a, (*lst_a)->next);
}
*/
