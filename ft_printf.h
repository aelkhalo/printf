/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elkhaluffy <elkhaluffy@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 16:09:37 by aelkhalo          #+#    #+#             */
/*   Updated: 2020/02/29 11:02:36 by elkhaluffy       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

typedef struct pf
{
    int wth;
    char *buff;
    int lenght;
    char *flags;

}           pf;

typedef struct t_flag
{
    int value;
    int state;
}           t_flag;

typedef struct t_flags
{
    t_flag wth;
    t_flag zero;
    t_flag prec;
}           t_flags;

void	ft_putchar(char c);
size_t	ft_strlen(const char *s);
void	ft_putstr(char *str);
int     ft_printf(const char *str, ...);
void	ft_putnbr(int nb);
void    ft_handler(va_list *ap, pf *st);
int     ft_isdigit(int c);
int     ft_atoi(const char *str);
int	    ft_isalpha(int c);
void    get_in(t_flags *b);
int		count_int(unsigned int n);
void    print_zeros(pf *a, t_flags *b, int val);
void    print_spaces(pf *a, t_flags *b, int val);
void    get_wth(pf *a, t_flags *b, va_list *ap);
void    get_zero(pf *a, t_flags *b, va_list *ap);
void    get_prec(pf *a, t_flags *b, va_list *ap);
void    c_handler(pf *a, t_flags *b, va_list *ap);
void    s_handler(pf *a, t_flags *b, va_list *ap);
void    f_handler(pf *a, t_flags *b, va_list *ap);
#endif