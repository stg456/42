/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:56:31 by stgerard          #+#    #+#             */
/*   Updated: 2022/05/05 13:42:58 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct s_struct
{
	int		*stack_a;
	int		*stack_b;
	int		len_a;
	int		len_b;
	int		max_length;
}				t_struct;

// check argv & initialisation
t_struct	*push_swap_struct(int argc, char **argv); /* argv en struct */
char		**shift_array(int argc, char **argv); /* enleve 1er argument */
void		push_swap_error(t_struct *list); /* free list */
int			ft_islonglong(const char *str); /* verif longlong */
int			check_start(int argc, char **argv);

// op
void		ft_sa(t_struct *list);
void		ft_sb(t_struct *list);
void		ft_ss(t_struct *list);
void		ft_pa(t_struct *list);
void		ft_pb(t_struct *list);
void		ft_ra(t_struct *list);
void		ft_rb(t_struct *list);
void		ft_rr(t_struct *list);
void		ft_rra(t_struct *list);
void		ft_rrb(t_struct *list);
void		ft_rrr(t_struct *list);

// algo
// int			get_minetnext(int *stack, int len);
int			check_sort(t_struct *list);
void		stack_to_index(t_struct *list);
int			ft_dectobin(long long nb);
int			ft_intlen(long n);
int			get_min(int	*stack, int len);
int			get_next_min(int *stack, int len, int tmp);
int			get_max(int *stack, int len);
int			push_swap_algo(t_struct *list);
int			check_sort(t_struct *list);
void		small_algo(t_struct *list);
void		radix_sort(t_struct *list);

// test
void		print_list(t_struct *list);
int			ft_itohex(unsigned int num, const char format);
void		ft_putchar_fd(char c, int fd);
int			ft_putnbr(int nb);
char		*ft_itoa(int n);
int			ft_putstr(char *str);
int			ft_putchar(int c);
int			ft_putint_unsigned(unsigned int n);
int			ft_putptr(unsigned long long ptr);
size_t		ft_strlen(const char *s);
char		**ft_split(char const *s, char c);
void		ft_bzero(void *s, size_t n);
char		*ft_strdup(const char *s1);
int			ft_atoi(const char *str);

#endif
