/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlai <tlai@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:24:52 by tlai              #+#    #+#             */
/*   Updated: 2024/01/19 12:33:03 by tlai             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_putchar(const char c, int *error)
{
	*error = write(1, &c, 1);
	if (*error != -1)
		return (1);
	return (-1);
}

static int	print_s_string(const char *str, int *error)
{
	int	counter;

	counter = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (*str != '\0' && *error != -1)
	{
		ft_putchar(*str, error);
		str++;
		counter++;
	}
	return (counter);
}

static int	print_int(int n, int *error)
{
	int		counter;
	int		counter2;
	long	digit;

	digit = (long)n;
	counter = 0;
	counter2 = 0;
	if (digit < 0 && *error != -1)
	{
		*error = write(1, "-", 1);
		digit = digit * -1;
		counter = 1;
	}
	if (digit == 0)
		counter = 1;
	if (digit >= 10 && *error != -1)
		print_int(digit / 10, error);
	while (n != '\0')
	{
		n = n / 10;
		counter2++;
	}
	if (*error != -1)
		ft_putchar('0' + digit % 10, error);
	return (counter + counter2);
}

static int	ft_conversion(va_list args, char specifier, int *error)
{
	int	counter;

	counter = 0;
	if (specifier == '\0')
		return (-1);
	else if (specifier == 'c')
		return (ft_putchar(va_arg(args, int), error));
	else if (specifier == 's')
		return (print_s_string(va_arg(args, const char *), error));
	else if (specifier == '%')
		return (ft_putchar('%', error));
	else if (specifier == 'd' || specifier == 'i')
		return (print_int(va_arg(args, int), error));
	return (counter);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		counter;
	int		error;

	error = 0;
	va_start(args, str);
	counter = 0;
	if (str == NULL)
		return (-1);
	while (*str != '\0' && error != -1)
	{
		if (*str == '%')
			counter += ft_conversion(args, *(++str), &error);
		else
		{
			counter++;
			error = write(1, str, 1);
		}
		str++;
	}
	va_end(args);
	if (error == -1)
		return (-1);
	return (counter);
}
