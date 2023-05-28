/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 14:02:42 by aaudeber          #+#    #+#             */
/*   Updated: 2023/05/28 16:32:46 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_list **lst_a, t_list **lst_b)
{
	int		sorted;
	t_list	*s1;
	t_list 	*s2;
	t_list	*tmp_b;

	sorted = 0;
	while (*lst_a)
		return (1);
	if (!(*lst_a))
	{
		ft_putstr_fd("\n|||||||\n", 1);
		tmp_b = *lst_b;
		ft_print_lst(lst_b);
		*lst_b = tmp_b;
		ft_putstr_fd("|||||||\n", 1);
		while (*lst_b)
		{
			s1 = *lst_b;
			s2 = s1->next;
			if (s2 && !(s1->nb > s2->nb))
			{
				ft_putnbr_fd((*lst_b)->nb, 1);
				sorted = 1;
			}
			ft_lstpush("pa", lst_b, lst_a);
		}
	}
	ft_putstr_fd("\n---", 1);
	ft_putnbr_fd(sorted, 1);
	ft_putstr_fd("---\n", 1);
	return (sorted);
}

int	ft_sort(t_list **lst_a, t_list **lst_b)
{
	int		count;
	int		len;
	t_list	*s1;
	t_list 	*s2;
	t_list 	*tmp;

	count = 0;
	len = 4;
	tmp = *lst_a;
	//while (len > 0)
	while (is_sorted(lst_a, lst_b))
	{
		s1 = *lst_a;
		s2 = s1->next;
		printf("\nP1 : %p \n", s1);
		ft_putstr_fd("===================\n", 1);
		if (s2 && s1->nb < s2->nb)
			ft_lstpush("pb", lst_a, lst_b);
		else if (ft_lstsize(*lst_a) == 1)
			ft_lstpush("pb", lst_a, lst_b);
		else
			ft_lstrotate("ra", lst_a, s1, s2);
		len--;
	}
	return (0);
}

/*
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
			//printf("\nP1 : %p \n", tmp);
			if (mask << i & tmp->nb)
			{
				printf("1");
				//ft_lstpush("pb", tmp, lst_b);
				tmp = tmp->next;
			}
			else
			{
				printf("0");
				printf("\nP2 : %p \n", tmp);
				ft_lstrotate("ra", tmp, tmp, tmp->next);
			}
			//ft_lstpush("pb", lst_a, lst_b);
			//printf("\n====");
		}
		//printf("\n///////////\n");
		tmp = *lst_a;
		printf("\n");
		i++;
	}
}
*/

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
