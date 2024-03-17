/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-ward <mel-ward@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 09:48:01 by mel-ward          #+#    #+#             */
/*   Updated: 2024/03/13 19:59:55 by mel-ward         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <libc.h>
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"
# include "get_next_line_bonus.h"

typedef struct t_nums
{
	long			num;
	struct t_nums	*next;
}	t_nums;

t_nums	*get_last(t_nums *nums);
void	swap_it(t_nums **nums);
void	swap_both(t_nums **stack_a, t_nums **stack_b);
void	rotate_it(t_nums **nums);
void	rotate_both(t_nums **stack_a, t_nums **stack_b);
void	reverse_rotate(t_nums **nums);
void	push_to(t_nums **src, t_nums **des);
void	rotate_reverse_both(t_nums **stack_a, t_nums **stack_b);
void	clear_nums(t_nums *nums);
int		check_storted(t_nums *nums);
void	apply_and_check_sort(t_nums **stack_a);
int		check_empty(char *str);
char	*join_it(int ac, char **av);
t_nums	*ft_new_nums(long num);
void	ft_add_num(t_nums **nums, t_nums *new);
int		check_it(char *str);
#endif