/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:07:15 by aaudeber          #+#    #+#             */
/*   Updated: 2023/09/15 16:44:23 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**create_tab(int argc, char **argv)
{
	int		i;
	char	**tab;

	i = 0;
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');
		if (!tab[1])
			ft_error((void **)tab, NULL, NULL, NULL);
	}
	else
	{
		tab = ft_calloc(argc, sizeof(char *));
		while (i < argc - 1)
		{
			tab[i] = ft_strdup(argv[i + 1]);
			i++;
		}
		tab[i] = NULL;
	}
	return (tab);
}

void	create_lst(char **tab, t_list **lst_a, t_list **lst_b)
{
	int		i;
	long	nb;
	t_list	*new;

	i = 0;
	nb = 0;
	while (tab[i])
	{
		if (is_valid_number(tab[i]))
			ft_error((void **)tab, lst_a, lst_b, ERROR_MESSAGE);
		nb = ft_atoi(tab[i]);
		if (is_overflow(nb))
			ft_error((void **)tab, lst_a, lst_b, ERROR_MESSAGE);
		new = ft_lstnew(nb);
		ft_lstadd_back(lst_a, new);
		i++;
	}
	if (is_duplicate(lst_a))
		ft_error((void **)tab, lst_a, lst_b, ERROR_MESSAGE);
}

int	main(int argc, char **argv)
{
	t_list	*lst_a;
	t_list	*lst_b;
	char	**tab;

	lst_a = NULL;
	lst_b = NULL;
	tab = NULL;
	if (read(STDIN_FILENO, 0, 0) < 0)
		ft_error((void **)tab, &lst_a, &lst_b, ERROR_MESSAGE);
	if (argc < 3)
		ft_error((void **)tab, &lst_a, &lst_b, NULL);
	tab = create_tab(argc, argv);
	create_lst(tab, &lst_a, &lst_b);
	read_and_process(tab, &lst_a, &lst_b);
	ft_lstclear(&lst_a);
	ft_lstclear(&lst_b);
	free_tab((void **)tab);
	return (0);
}
