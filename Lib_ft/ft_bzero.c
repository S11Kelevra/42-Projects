/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/12 16:19:08 by eramirez          #+#    #+#             */
/*   Updated: 2017/06/21 18:57:38 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void ft_bzero(void *s, size_t n)
{
	char *ptr;

	ptr = (char *)s;
	while (n-- > 0)
		*ptr++  = 0;
}