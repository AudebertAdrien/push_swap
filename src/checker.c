/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:07:15 by aaudeber          #+#    #+#             */
/*   Updated: 2023/06/30 14:12:25 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	execute_cmd(char *cmd, t_list **lst_a, t_list **lst_b)
{
	(void)lst_b;
	int	cmd_len;

	cmd_len = ft_strlen(cmd);

	if (!ft_strncmp(cmd,"sa\n", cmd_len))
		ft_lstswap(cmd, lst_a, *lst_a, (*lst_a)->next);
	if (!ft_strncmp(cmd,"sb\n", cmd_len))
		ft_lstswap(cmd, lst_b, *lst_b, (*lst_b)->next);
	if (!ft_strncmp(cmd,"ss\n", cmd_len))
	{
		ft_lstswap("sa\n", lst_a, *lst_a, (*lst_a)->next);
		ft_lstswap("sb\n", lst_b, *lst_b, (*lst_b)->next);
	}

	if (!ft_strncmp(cmd,"pa\n", cmd_len))
		ft_lstpush(cmd, lst_b, lst_a);
	if (!ft_strncmp(cmd,"pb\n", cmd_len))
		ft_lstpush(cmd, lst_a, lst_b);
	
	if (!ft_strncmp(cmd,"ra\n", cmd_len))
		ft_lstrotate(cmd, lst_a, *lst_a, (*lst_a)->next);
	if (!ft_strncmp(cmd,"rb\n", cmd_len))
		ft_lstrotate(cmd, lst_b, *lst_b, (*lst_b)->next);
	if (!ft_strncmp(cmd,"rr\n", cmd_len))
	{
		ft_lstrotate("ra\n", lst_a, *lst_a, (*lst_a)->next);
		ft_lstrotate("rb\n", lst_b, *lst_b, (*lst_b)->next);
	}
	if (!ft_strncmp(cmd,"rra\n", cmd_len))
		ft_lstrotate_reversed(cmd, lst_a, ft_lstlast(*lst_a), ft_lstsize(*lst_a));
	if (!ft_strncmp(cmd,"rrb\n", cmd_len))
		ft_lstrotate_reversed(cmd, lst_b, ft_lstlast(*lst_b), ft_lstsize(*lst_b));
	if (!ft_strncmp(cmd,"rrr\n", cmd_len))
	{
		ft_lstrotate_reversed(cmd, lst_a, ft_lstlast(*lst_a), ft_lstsize(*lst_a));
		ft_lstrotate_reversed(cmd, lst_b, ft_lstlast(*lst_b), ft_lstsize(*lst_b));
	}
	return (1);
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
		ft_error(ERROR_MESSAGE);
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		tab = ft_split(argv[1], ' ');	
		if (!tab[0])
			ft_error(ERROR_MESSAGE);
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

	while (1)
	{
		buf = get_next_line(STDIN_FILENO);	
		if (!buf)
			break ;
		execute_cmd(buf, &lst_a, &lst_b);
		free(buf);
	}

	ft_print_lst(lst_a);

	if(is_sorted(lst_a))
		ft_printf("OK");
	else
		ft_printf("KO");

	ft_lstclear(&lst_a);
	free(tab);

	return (0);
}
