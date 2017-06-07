/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 20:09:43 by eramirez          #+#    #+#             */
/*   Updated: 2017/01/31 13:37:46 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int i;
	int total;
	int sign;

	sign = 1;
	i = 0;
	while (str[i] == 32 || (9 <= str[i] && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	if ('0' > str[i] && str[i] > '9')
		return (0);
	total = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		total = (total * 10) + (str[i] - 48);
		i++;
	}
	return (total * sign);
}