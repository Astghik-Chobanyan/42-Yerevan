/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achobany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:28:57 by achobany          #+#    #+#             */
/*   Updated: 2021/02/03 15:40:52 by achobany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != c)
		i++;
	if (str[i] == (char)c)
		return (char*)&str[i];
	return (NULL);
}
