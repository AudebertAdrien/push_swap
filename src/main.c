/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:40:47 by aaudeber          #+#    #+#             */
/*   Updated: 2023/06/23 14:07:57 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		i;
	long	nb;
	t_list	*lst_a;
	t_list	*lst_b;
	t_list	*new;
	char	**tab;

	nb = 0;
	i = 0;
	lst_a = NULL;
	lst_b = NULL;
	tab = NULL;
	if (argc < 2)
		ft_error(NOT_ENOUGH_ARGS);
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');	
		if (!tab[0])
			ft_error(ERROR);
	}
	else
	{
		tab = ft_calloc(argc, sizeof(char *));
		while (i < argc - 1)
		{
			tab[i] = argv[i + 1];
			i++;
		}
		tab[i] = NULL;
	}
	i = 0;
	while (tab[i])
	{
		if (is_valid_number(tab[i]))
			ft_error(IS_NUMBER);
		nb = ft_atoi(tab[i]);
		if (is_overflow(nb))
			ft_error(IS_OVERFLOW);
		new = ft_lstnew(nb);
		//ft_printf("new p : %p => ", new);
		//ft_printf("nb : %d\n", new->nb);
		ft_lstadd_back(&lst_a, new);
		i++;
	}

	if (is_duplicate(&lst_a))
		ft_error(IS_DUPLICATE);
	if (is_already_sorted(&lst_a))
		ft_error(IS_ALREADY_SORTED);

	ft_sort(&lst_a, &lst_b);

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

	//clean_program(&lst_a, tab);
	ft_lstclear(&lst_a);
	free(tab);

	//ft_printf("\n");
	return (0);
}
