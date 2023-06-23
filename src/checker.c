/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:07:15 by aaudeber          #+#    #+#             */
/*   Updated: 2023/06/23 16:22:51 by aaudeber         ###   ########.fr       */
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
	char	*buf;

	nb = 0;
	i = 0;
	lst_a = NULL;
	lst_b = NULL;
	tab = NULL;
	if (read(STDIN_FILENO, 0, 0) < 0)
		ft_error(EMPTY_STDIN);
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
		ft_lstadd_back(&lst_a, new);
		i++;
	}

	if (is_duplicate(&lst_a))
		ft_error(IS_DUPLICATE);
	if (is_already_sorted(&lst_a))
		ft_error(IS_ALREADY_SORTED);

	printf("start\n");
	while (1)
	{
		buf = get_next_line(STDIN_FILENO);	
		if (!buf)
			break ;
		ft_putstr_fd(buf, 1);
		free(buf);
	}
	printf("end\n");

	if (


	ft_lstclear(&lst_a);
	free(tab);

	return (0);
}
