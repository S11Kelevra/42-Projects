/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 15:34:01 by eramirez          #+#    #+#             */
/*   Updated: 2017/06/06 15:39:36 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char ft_tolower(char c)
{
	if (65 <= c && c <= 90)
		return (c + 32);
	else
		return c;
}