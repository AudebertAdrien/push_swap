/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:40:47 by aaudeber          #+#    #+#             */
/*   Updated: 2023/07/01 15:38:08 by aaudeber         ###   ########.fr       */
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
		exit(EXIT_SUCCESS);
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		if (!tab[1])
			exit(EXIT_SUCCESS);
		//if (!tab[!0])
		//	ft_error(ERROR_MESSAGE);
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
			ft_error(ERROR_MESSAGE);
		nb = ft_atoi(tab[i]);
		if (is_overflow(nb))
			ft_error(ERROR_MESSAGE);
		new = ft_lstnew(nb);
		ft_lstadd_back(&lst_a, new);
		i++;
	}

	if (is_duplicate(&lst_a))
		ft_error(ERROR_MESSAGE);
	if (is_already_sorted(&lst_a))
		exit(EXIT_SUCCESS);
	//	ft_error(ERROR_MESSAGE);


	ft_sort(&lst_a, &lst_b);
	ft_lstclear(&lst_a);
	free(tab);
	return (0);
}
