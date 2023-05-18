/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:40:47 by aaudeber          #+#    #+#             */
/*   Updated: 2023/05/18 21:29:52 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_lst(t_list **lst)
{
	ft_printf("//////\n");
	while (*lst)
	{
		ft_printf("p_lst : %p\n", *lst);
		ft_printf("c d: %d\n", (*lst)->nb);
		*lst = (*lst)->next;
	}
}

void	ft_lstswap(t_list **lst, t_list *s1, t_list *s2)
{
	*lst = s2;
	s1->next = s2->next;
	s2->next = s1;	
}

void	ft_lstrotate(t_list **lst, t_list *s1, t_list *s2)
{
	*lst = s2;
	s1->next = NULL;
	ft_lstadd_back(lst, s1);
}

void	ft_lstrotate_reversed(t_list **lst, t_list *last, int size)
{
	int	i;
	t_list	*tmp;

	i = 0;
	tmp = *lst;
	while (i < size - 2)
	{
		tmp = tmp->next;
		i++;
	}
	tmp->next = NULL;
	ft_lstadd_front(lst, last);
}

void	ft_push(t_list **t1, t_list **t2)
{
	t_list	*tmp;

	if (!*t1)
		return ;
	tmp = (*t1)->next;
	ft_lstadd_front(t2, *t1);
	*t1 = tmp;
}

int	main(int argc, char **argv)
{
	int		i;
	int		nb;
	t_list	*lst_a;
	t_list	*lst_b;
	t_list	*new;

	ft_printf("Hello World\n");
	nb = 0;
	i = 1;
	lst_a = NULL;
	lst_b = NULL;
	if (argc > 2)
	{
		ft_printf("\n");
		while (argv[i])
		{
			nb = ft_atoi(argv[i]);
			new = ft_lstnew(nb);
			ft_printf("new p : %p\n", new);
			ft_printf("nc : %d\n", new->nb);
			ft_lstadd_back(&lst_a, new);
			i++;
		}
		ft_printf("\n");
		
		//ft_lstswap(&lst_a, lst_a, lst_a->next);
		//ft_lstrotate(&lst_a, lst_a, lst_a->next);
		//ft_lstrotate_reversed(&lst_a, ft_lstlast(lst_a), ft_lstsize(lst_a));
		ft_push(&lst_a, &lst_b);
		ft_push(&lst_a, &lst_b);
		ft_push(&lst_a, &lst_b);

		ft_printf("AAAA: %p\n", &lst_a);
		ft_print_lst(&lst_a);
		ft_printf("\n");
		ft_printf("===========");
		ft_printf("\n\n");
		ft_printf("BBBB: %p\n", &lst_b);
		ft_print_lst(&lst_b);

	}
	ft_printf("\n");
	return (0);
}
