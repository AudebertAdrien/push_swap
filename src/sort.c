/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:02:42 by aaudeber          #+#    #+#             */
/*   Updated: 2023/05/28 20:48:39 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int	is_sorted(t_list **lst_a, t_list **lst_b)
{
	int		sorted;
	t_list	*s1;
	t_list 	*s2;

	sorted = 0;
	while (*lst_a)
		return (1);
	if (!(*lst_a))
	{
		while (*lst_b)
		{
			s1 = *lst_b;
			s2 = s1->next;
			if (s2 && !(s1->nb > s2->nb))
				sorted = 1;
			ft_lstpush("pa", lst_b, lst_a);
		}
	}
	return (sorted);
}

int	ft_sort(t_list **lst_a, t_list **lst_b)
{
	t_list	*s1;
	t_list 	*s2;

	while (is_sorted(lst_a, lst_b))
	{
		s1 = *lst_a;
		s2 = s1->next;
		if (s2 && s1->nb < s2->nb)
			ft_lstpush("pb", lst_a, lst_b);
		else if (ft_lstsize(*lst_a) == 1)
			ft_lstpush("pb", lst_a, lst_b);
		else
			ft_lstrotate("ra", lst_a, s1, s2);
	}
	return (0);
}
*/

void	ft_sort(t_list **lst_a, t_list **lst_b)
{
	int	i;
	int	mask;
	t_list	*s1;
	t_list	*s2;
	t_list	*tmp;

	i = 0;
	mask = 128;
	tmp = *lst_a;
	while (*lst_a)
	{
		printf("%p\n", *lst_a);
		printf(">> %d\n", mask >> i & s1->nb);
		//sleep(1);

		s1 = *lst_a;
		s2 = s1->next;
		if (mask >> i & s1->nb)
		{
			ft_putstr_fd("1 :", 1);
			ft_lstpush("pb", lst_a, lst_b);
		}
		else if (ft_lstsize(*lst_a) == 1)
		{
			ft_putstr_fd("1 bis :", 1);
			ft_lstpush("pb", lst_a, lst_b);
		}
		else
		{
			printf("0");
			ft_lstrotate("ra", lst_a, s1, s2);
			i++;
		}
	}
	printf("\n");
	i++;
}
