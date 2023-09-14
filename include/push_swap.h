/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:43:40 by aaudeber          #+#    #+#             */
/*   Updated: 2023/09/14 16:17:17 by motoko           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# define BUFFER_SIZE 1024
# define ERROR_MESSAGE "Error"

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

# include "../libft/libft.h"
# include "../printf/ft_printf.h"

char	*get_next_line(int fd);

typedef struct s_list
{
	int				nb;
	unsigned int	index;
	struct s_list	*next;
}			t_list;

int		ft_lstswap(char *cmd, t_list **lst, t_list *s1, t_list *s2, int id);
int		ft_lstpush(char *cmd, t_list **t1, t_list **t2, int id);
int		ft_lstrotate(char *cmd, t_list **lst, t_list *s1, t_list *s2, int id);
int		ft_lstrotate_reversed(char *cmd, t_list **lst, t_list *last, int size, int id);

int	ft_low_stack(t_list **lst_a, t_list **lst_b);
void	ft_sort(t_list **lst_a, t_list **lst_b);
void	ft_sort_and_index(t_list *lst);

void	free_tab(void **tab);
void	ft_error(void **tab, t_list **lst_a,  t_list **lst_b, char *s);

int		is_sorted(t_list *lst);
int		is_valid_number(char *s);
int		is_overflow(long nb);
int		is_duplicate(t_list **lst);
int		is_already_sorted(t_list **lst);

int		ft_lstsize(t_list *lst);	
t_list	*ft_lstnew(int nb);	
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst);

void	read_and_process(char **tab, t_list **lst_a, t_list **lst_b);
void	execute_cmd(char *cmd, char **tab, t_list **lst_a, t_list **lst_b);
#endif
