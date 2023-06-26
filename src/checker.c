/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:07:15 by aaudeber          #+#    #+#             */
/*   Updated: 2023/06/26 15:36:49 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef t_list (*myFunction)(char, t_list, t_list);

t_list *right_lst(char *cmd, t_list **lst_a, t_list *lst_b)
{
	if (ft_strchr(cmd, 'a'))
		return (lst_a);
	if (ft_strchr(cmd, 'b'))
		return (lst_b);
}

void	execute_cmd(char *cmd, t_list **lst_a, t_list **lst_b, t_list)
{
	myFunction	f = &right_lst;	
	/*
	if (*cmd == "sa\n" || *cmd == "sb\n")
		ft_lstswap(*cmd, f_lst(), *lst_a, (*lst_a)->next);
	if (*cmd == "ss")
	{
		ft_lstswap("sa", lst_a, *lst_a, (*lst_a)->next);
		ft_lstswap("sb", lst_a, *lst_a, (*lst_a)->next);
	}
	if (*cmd == "pa" || *cmd == "pb")
		ft_lstpush(*cmd, lst_a, lst_b);
	if (*cmd == "ra" || *cmd == "rb")
		ft_lstrotate(*cmd, lst_a, *lst_a, (*lst_a)->next);
	if (*cmd == "rr")
	{
		ft_lstrotate("ra", lst_a, *lst_a, (*lst)->next);
		ft_lstrotate("rb", lst_a, *lst_a, (*lst)->next);
	}
	if (*cmd == "rra" || *cmd == "rrb")
		ft_lstrotate_reversed(*cmd, lst_a, ft_lstlast(*lst_a), ft_lstsize(*lst_a));
	if (*cmd == "rrr")
	{
		ft_lstrotate("rra", lst_a, *lst_a, (*lst)->next);
		ft_lstrotate("rrb", lst_a, *lst_a, (*lst)->next);
	}
	*/
}

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
		return (0);
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

	printf("start\n");
	while (1)
	{
		buf = get_next_line(STDIN_FILENO);	
		if (!buf)
			break ;
		//ft_putstr_fd(buf, 1);
		execute_cmd(buf, &lst_a, &lst_b);
		free(buf);
	}
	printf("end\n");

	ft_lstclear(&lst_a);
	free(tab);

	return (0);
}
