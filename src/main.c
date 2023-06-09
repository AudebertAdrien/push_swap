/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:40:47 by aaudeber          #+#    #+#             */
/*   Updated: 2023/06/09 17:40:22 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_error(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isalpha(s[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_duplicate(t_list **lst)
{
	t_list *l1;
	t_list *l2;

	l1 = *lst;
	while (l1)
	{
		l2 = l1->next;
		if (l1->nb >= INT_MAX || l1->nb <= INT_MIN)
		{
			ft_error("Error3");
			return (1);
		}
		while (l2)
		{
			if (l1->nb == l2->nb)
				return (1);
			l2 = l2->next;
		}
		l1 = l1->next;
	}
	return (0);
}

int	ft_is_already_sorted(t_list **lst)
{
	t_list	*s1;
	t_list	*tmp;

	while ((*lst)->next)
	{
		if ((*lst)->nb < (*lst)->next->nb && )
			return (1);
		tmp = *lst;
		*lst = (*lst)->next;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		nb;
	t_list	*lst_a;
	t_list	*lst_b;
	t_list	*new;

	nb = 0;
	i = 1;
	lst_a = NULL;
	lst_b = NULL;
	if (argc <= 2)
		ft_error("Error : Need at least two argument !");
	if (argc > 2)
	{
		while (argv[i])
		{
			if (ft_is_error(argv[i]))
				ft_error("Error1");
			nb = ft_atoi(argv[i]);
			new = ft_lstnew(nb);
			//ft_printf("new p : %p => ", new);
			//ft_printf("nb : %d\n", new->nb);
			ft_lstadd_back(&lst_a, new);
			i++;
		}

		if (ft_is_duplicate(&lst_a))
			ft_error("Error : Duplicate value!");
		if (ft_is_already_sorted(&lst_a))
			ft_error("Error : Already sorted!");

		ft_sort(&lst_a, &lst_b);

		ft_printf("\n");
		ft_printf("AAAA: %p\n", &lst_a);
		ft_print_lst(&lst_a);
		ft_printf("\n");
		ft_printf("===========");
		ft_printf("\n\n");
		ft_printf("BBBB: %p\n", &lst_b);
		ft_print_lst(&lst_b);

		ft_lstclear(&lst_a);

	}
	//ft_printf("\n");
	return (0);
}
