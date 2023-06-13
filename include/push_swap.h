/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaudeber <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 16:43:40 by aaudeber          #+#    #+#             */
/*   Updated: 2023/06/13 10:47:16 by aaudeber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP
# define NOT_ENOUGH_ARGS "Error : Need at least a string '2 1 0...' or multiple argument!" 
# define IS_ALPHA "Error : is alpha!"
# define IS_DUPLICATE "Error : Duplicate value!"
# define IS_ALREADY_SORTED "Error : Already sorted!"
# define IS_OVERFLOW "Error : INT_MAX or INT_MIN!"

# include <unistd.h>
# include <limits.h>

# include "../libft/libft.h"
# include "../printf/ft_printf.h"

typedef struct s_list
{
	int				nb;
	unsigned int	index;
	struct s_list	*next;
}			t_list;

int		ft_lstswap(char *cmd, t_list **lst, t_list *s1, t_list *s2);
int		ft_lstpush(char *cmd, t_list **t1, t_list **t2);
int		ft_lstrotate(char *cmd, t_list **lst, t_list *s1, t_list *s2);
int		ft_lstrotate_reversed(char *cmd, t_list **lst, t_list *last, int size);

void	ft_sort(t_list **lst_a, t_list **lst_b);

void	ft_error(char *s);
void	ft_print_lst(t_list **lst);
void	ft_print_lst_index(t_list *lst);

int	is_alpha(char *s);
int	is_overflow(t_list **lst);
int	is_duplicate(t_list **lst);
int	is_already_sorted(t_list **lst);

t_list	*ft_lstnew(int nb);	
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);	
void	ft_lstclear(t_list **lst);

#endif
