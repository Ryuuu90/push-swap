/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabou-rk <rabou-rk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 01:26:48 by rabou-rk          #+#    #+#             */
/*   Updated: 2022/11/12 01:50:34 by rabou-rk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr(long n);
int	ft_putnbr_un(unsigned int n);
int	ft_lowerhexa(unsigned int n);
int	ft_upperhexa(unsigned int n);
int	ft_printads(unsigned long nbr);
int	ft_lowerhexa_p(unsigned long n);

#endif