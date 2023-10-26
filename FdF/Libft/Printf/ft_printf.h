/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manuemar <manuemar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 02:22:45 by manuemar          #+#    #+#             */
/*   Updated: 2023/03/31 19:02:09 by manuemar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

# include <stdio.h>
// __attribute__((format(printf, 1, 2)))
int	ft_printf(char const *str, ...);
int	ft_print_formats(va_list args, char const str);
int	ft_print_char(int c);
int	ft_print_str(char *s);
int	ft_print_pointer(unsigned long long ptr);
int	ft_print_hexal_pointer(unsigned long long n, int cont);
int	ft_print_int(int n, int cont);
int	ft_print_pos(unsigned int n, int cont);
int	dtohl(int n);
int	ft_print_hexal(unsigned int n, int cont);
int	dtohu(int n);
int	ft_print_hexau(unsigned int n, int cont);

#endif
