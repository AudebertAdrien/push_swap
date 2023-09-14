/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_exec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: motoko <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 10:31:38 by motoko            #+#    #+#             */
/*   Updated: 2023/09/14 16:49:40 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_cmd_2(char *cmd, char **tab, t_list **lst_a, t_list **lst_b)
{
	int	cmd_len;

	cmd_len = ft_strlen(cmd);
	if (!ft_strncmp(cmd, "rb\n", cmd_len))
		ft_lstrotate(cmd, lst_b, *lst_b, (*lst_b)->next, 2);
	else if (!ft_strncmp(cmd, "rr\n", cmd_len))
	{
		ft_lstrotate("ra\n", lst_a, *lst_a, (*lst_a)->next, 2);
		ft_lstrotate("rb\n", lst_b, *lst_b, (*lst_b)->next, 2);
	}
	else if (!ft_strncmp(cmd, "rra\n", cmd_len))
		ft_lstrotate_reversed(cmd, lst_a, ft_lstlast(*lst_a), ft_lstsize(*lst_a), 2);
	else if (!ft_strncmp(cmd, "rrb\n", cmd_len))
		ft_lstrotate_reversed(cmd, lst_b, ft_lstlast(*lst_b), ft_lstsize(*lst_b), 2);
	else if (!ft_strncmp(cmd, "rrr\n", cmd_len))
	{
		ft_lstrotate_reversed(cmd, lst_a, ft_lstlast(*lst_a), ft_lstsize(*lst_a), 2);
		ft_lstrotate_reversed(cmd, lst_b, ft_lstlast(*lst_b), ft_lstsize(*lst_b), 2);
	}
	else
	{
		free(cmd);
		cmd = NULL;
		ft_error((void **)tab, lst_a, lst_b, ERROR_MESSAGE);
	}
}

void	execute_cmd(char *cmd, char **tab, t_list **lst_a, t_list **lst_b)
{
	int	cmd_len;

	cmd_len = ft_strlen(cmd);
	if (!ft_strncmp(cmd, "sa\n", cmd_len))
		ft_lstswap(cmd, lst_a, *lst_a, (*lst_a)->next, 2);
	else if (!ft_strncmp(cmd, "sb\n", cmd_len))
		ft_lstswap(cmd, lst_b, *lst_b, (*lst_b)->next, 2);
	else if (!ft_strncmp(cmd, "ss\n", cmd_len))
	{
		ft_lstswap("sa\n", lst_a, *lst_a, (*lst_a)->next, 2);
		ft_lstswap("sb\n", lst_b, *lst_b, (*lst_b)->next, 2);
	}
	else if (!ft_strncmp(cmd, "pa\n", cmd_len))
		ft_lstpush(cmd, lst_b, lst_a, 2);
	else if (!ft_strncmp(cmd, "pb\n", cmd_len))
		ft_lstpush(cmd, lst_a, lst_b, 2);
	else if (!ft_strncmp(cmd, "ra\n", cmd_len))
		ft_lstrotate(cmd, lst_a, *lst_a, (*lst_a)->next, 2);
	else
		execute_cmd_2(cmd, tab, lst_a, lst_b);
}

void	read_and_process(char **tab, t_list **lst_a, t_list **lst_b)
{
	char	*buf;

	while (1)
	{
		buf = get_next_line(STDIN_FILENO);
		if (!buf)
			break ;
		execute_cmd(buf, tab, lst_a, lst_b);
		free(buf);
		buf = NULL;
	}
	if (is_sorted(*lst_a))
		ft_printf("OK");
	else
		ft_printf("KO");
}
