/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkhaluffy <elkhaluffy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 16:09:37 by aelkhalo          #+#    #+#             */
/*   Updated: 2020/03/13 20:01:23 by elkhaluffy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

typedef struct pf
{
    char *buff;
    int lenght;
    char *flags;

}           pf;

typedef struct t_flag
{
    int v;
    int s;
}           t_flag;

typedef struct t_flags
{
    t_flag wth;
    t_flag zero;
    t_flag prec;
    t_flag check;
    t_flag min;
}           t_flags;

void	ft_putchar(char c);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *str , int val, pf *a);
void	ft_putnstr(char *s, int n);
int     ft_printf(const char *str, ...);
void	ft_putnbr(int nb);
void    ft_handler(va_list *ap, pf *st);
int     ft_isdigit(int c);
int     ft_atoi(const char *str);
int	    ft_isalpha(int c);
void    get_in(pf *a, t_flags *b);
int		count_int(unsigned int n);
void    get_wth_dig(pf *a, t_flags *b);
void    get_wth_min(pf *a, t_flags *b, va_list *ap);
void    print_zeros(pf *a, t_flags *b, int val);
void    print_spaces(pf *a, t_flags *b, int val);
void    print_s_spaces(pf *a, t_flags *b);
void    get_wth(pf *a, t_flags *b, va_list *ap);
void    get_zero(pf *a, t_flags *b, va_list *ap);
void    get_prec(pf *a, t_flags *b, va_list *ap);
void    c_handler(pf *a, t_flags *b, va_list *ap);
void    s_handler(pf *a, t_flags *b, va_list *ap);
void    f_handler(pf *a, t_flags *b, va_list *ap);
void    check_s_hand(pf *a, t_flags *b, int val);
void    check_s_hand1(pf *a, t_flags *b, int val);
void    check_s_hand2(pf *a, t_flags *b, int val, char *s);
void    check_d_hand(pf *a, t_flags *b, int val, int i);
void    check_d_hand1(pf *a, t_flags *b, int val, int i);
void    check_d_hand2(pf *a, t_flags *b, int val, int ex, int i);
void    check_d_hand0(t_flags *b, int i);
void    check_d_norme(pf *a, t_flags *b, int val ,int i);
void    cal_lenght(pf *a, int val);
void    perc_handler(pf *a, t_flags *b);
void    check_perc_hand(pf *a, t_flags *b, int val, char s);
void	ft_putperc(char s, pf *a);
void    u_handler(pf *a, t_flags *b, va_list *ap);
void    check_u_hand2(pf *a, t_flags *b, int val, int ex, unsigned int i);
void    check_u_hand0(t_flags *b, int i);
void	ft_u_putnbr(unsigned int nb);
int		count_hex(unsigned long n, int b);
void	ft_puthex(unsigned long n, int maj);
void    check_x_hand2(pf *a, t_flags *b, int val, unsigned int i);
void    check_x_hand3(pf *a, t_flags *b, int val);
void    d_x_handler(pf *a, t_flags *b, unsigned int i);
void    check_x_hand0(t_flags *b, int i);
void    x_handler(pf *a, t_flags *b, va_list *ap);
void    p_handler(pf *a, t_flags *b, va_list *ap);
void    check_p_hand2(pf *a, t_flags *b, int val, unsigned long long i);

#endif