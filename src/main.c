/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:40:47 by aaudeber          #+#    #+#             */
/*   Updated: 2023/06/08 12:15:48 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_lst(t_list **lst)
{
	//ft_printf("////// \\\\\\\\\\\\ \n");
	while (*lst)
	{
		//ft_printf("p_lst : %p => ", *lst);
		//ft_printf("nb : %d\n", (*lst)->nb);
		*lst = (*lst)->next;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		nb;
	t_list	*lst_a;
	t_list	*lst_b;
	t_list	*new;

	//ft_printf("Hello World\n");
	nb = 0;
	i = 1;
	lst_a = NULL;
	lst_b = NULL;
	if (argc > 2)
	{
		//ft_printf("\n");
		while (argv[i])
		{
			nb = ft_atoi(argv[i]);
			new = ft_lstnew(nb);
			//ft_printf("new p : %p => ", new);
			//ft_printf("nb : %d\n", new->nb);
			ft_lstadd_back(&lst_a, new);
			i++;
		}
		//ft_printf("\n");

		ft_sort(&lst_a, &lst_b);
		
		//ft_lstswap("sa", &lst_a);
		//ft_lstpush("pb", &lst_a, &lst_b);
		//ft_lstrotate("ra", &lst_a, lst_a, lst_a->next);
		//ft_lstrotate_reversed(&lst_a, ft_lstlast(lst_a), ft_lstsize(lst_a));

		/*
		ft_printf("\n");
		ft_printf("AAAA: %p\n", &lst_a);
		ft_print_lst(&lst_a);
		ft_printf("\n");
		ft_printf("===========");
		ft_printf("\n\n");
		ft_printf("BBBB: %p\n", &lst_b);
		ft_print_lst(&lst_b);
		*/
	}
	//ft_printf("\n");
	return (0);
}
