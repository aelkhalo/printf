/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelkhalo <aelkhalo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 16:09:37 by aelkhalo          #+#    #+#             */
/*   Updated: 2020/03/14 00:08:43 by aelkhalo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

typedef	struct	s_pf
{
	char		*buff;
	int			lenght;
	char		*flags;

}				t_pf;

typedef	struct	s_flag
{
	int	v;
	int	s;
}				t_flag;

typedef	struct	s_flags
{
	t_flag		wth;
	t_flag		zero;
	t_flag		prec;
	t_flag		check;
	t_flag		min;
}				t_flags;

void			ft_putchar(char c);
size_t			ft_strlen(const char *s);
void			ft_putstr(char *str, int val, t_pf *a);
void			ft_putnstr(char *s, int n);
int				ft_printf(const char *str, ...);
void			ft_putnbr(int nb);
void			ft_handler(va_list *ap, t_pf *st);
int				ft_isdigit(int c);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
void			get_in(t_pf *a, t_flags *b);
int				count_int(unsigned int n);
int				get_wth_dig(t_pf *a);
void			get_wth_min(t_pf *a, t_flags *b, va_list *ap);
void			print_zeros(t_pf *a, t_flags *b, int val);
void			print_spaces(t_pf *a, t_flags *b, int val);
void			print_s_spaces(t_pf *a, t_flags *b);
void			get_wth(t_pf *a, t_flags *b, va_list *ap);
void			get_zero(t_pf *a, t_flags *b, va_list *ap);
void			get_prec(t_pf *a, t_flags *b, va_list *ap);
void			c_handler(t_pf *a, t_flags *b, va_list *ap);
void			s_handler(t_pf *a, t_flags *b, va_list *ap);
void			f_handler(t_pf *a, t_flags *b, va_list *ap);
void			check_s_hand(t_pf *a, t_flags *b, int val);
void			check_s_hand1(t_pf *a, t_flags *b, int val);
void			check_s_hand2(t_pf *a, t_flags *b, int val, char *s);
void			d_handler(t_pf *a, t_flags *b, va_list *ap);
void			check_d_hand(t_pf *a, t_flags *b, int val, int i);
void			check_d_hand1(t_pf *a, t_flags *b, int val, int i);
void			check_d_hand2(t_pf *a, t_flags *b, int ex, int i);
void			check_d_hand3(t_pf *a, t_flags *b, int val);
void			check_d_hand0(t_flags *b, int i);
void			check_d_norme(t_pf *a, t_flags *b, int val, int i);
void			cal_lenght(t_pf *a, int val);
void			perc_handler(t_pf *a, t_flags *b);
void			perc_handler1(t_pf *a, t_flags *b, int val);
void			check_perc_hand(t_pf *a, t_flags *b, int val, char s);
void			ft_putperc(char s, t_pf *a);
void			u_handler(t_pf *a, t_flags *b, va_list *ap);
void			check_u_hand1(t_pf *a, t_flags *b, int val);
void			check_u_hand2(t_pf *a, t_flags *b, int val, unsigned int i);
void			check_u_hand0(t_flags *b, int i);
void			ft_u_putnbr(unsigned int nb);
int				count_hex(unsigned long n, int b);
void			ft_puthex(unsigned long n, int maj);
void			check_x_hand2(t_pf *a, t_flags *b, int val, unsigned int i);
void			check_x_hand3(t_pf *a, t_flags *b, int val);
void			d_x_handler(t_pf *a, t_flags *b, unsigned int i);
void			check_x_hand0(t_flags *b, int i);
void			x_handler(t_pf *a, t_flags *b, va_list *ap);
void			p_handler(t_pf *a, t_flags *b, va_list *ap);
void			check_p_hand2(t_pf *a, t_flags *b, int val,
		unsigned long long i);

#endif
