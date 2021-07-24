/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 15:54:11 by achobany          #+#    #+#             */
/*   Updated: 2021/03/29 15:55:11 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		percent_write(t_option flags)
{
	int count;

	count = 0;
	if (flags.flag_minus == 1)
	{
		count += fd_putchar('%');
		count += ft_write_flags(flags.width, 1, 0);
	}
	else if (flags.flag_zero == 1)
	{
		count += ft_write_flags(flags.width, 1, 1);
		count += fd_putchar('%');
	}
	else
	{
		count += ft_write_flags(flags.width, 1, 0);
		count += fd_putchar('%');
	}
	return (count);
}
