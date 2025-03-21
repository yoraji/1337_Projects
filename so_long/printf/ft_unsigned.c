/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoraji <yoraji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:24:31 by yoraji            #+#    #+#             */
/*   Updated: 2025/03/14 03:18:15 by yoraji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_it(unsigned int num)
{
	int	counter;

	counter = 1;
	while (num)
	{
		num /= 10;
		counter++;
	}
	return (counter);
}

int	ft_strlen_0(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	ft_unsigned(unsigned int num)
{
	int		count;
	char	*ptr;
	int		len;

	count = 0;
	if (num == 0)
		return (ft_putstr("0"));
	len = ft_count_it(num);
	ptr = malloc(len + 1);
	if (!ptr)
		return (0);
	ptr[len] = '\0';
	while (len)
	{
		ptr[--len] = (num % 10) + '0';
		num /= 10;
	}
	count = write(1, ptr, ft_strlen_0(ptr));
	return (free(ptr), count);
}
