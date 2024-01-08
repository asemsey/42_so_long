/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asemsey <asemsey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:31:07 by asemsey           #+#    #+#             */
/*   Updated: 2023/10/30 13:45:07 by asemsey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_cases(int n, char *str)
{
	char	*min;
	int		i;

	i = 0;
	min = "-2147483648";
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	if (n == -2147483648)
	{
		while (min[i] != '\0')
		{
			str[i] = min[i];
			i++;
		}
		str[i] = '\0';
	}
}

// static int	ft_digits(int n)
// {
// 	int	len;

// 	len = 0;
// 	if (n == 0)
// 		return (1);
// 	if (n == -2147483648)
// 		return (11);
// 	if (n < 0)
// 	{
// 		n = -n;
// 		len++;
// 	}
// 	while (n > 0)
// 	{
// 		len++;
// 		n /= 10;
// 	}
// 	return (len);
// }

char	*ft_itoa(int n)
{
	int		i;
	char	*s;

	i = ft_digits(n);
	s = (char *)malloc((i + 1) * sizeof(char));
	if (!s)
		return (0);
	if (n == 0 || n == -2147483648)
	{
		ft_cases(n, s);
		return (s);
	}
	s[i--] = '\0';
	if (n < 0)
	{
		n = -n;
		s[0] = '-';
	}
	while (n > 0)
	{
		s[i--] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}
