/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/19 16:19:27 by eramirez          #+#    #+#             */
/*   Updated: 2017/06/19 16:21:35 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void ft_strdel(char **as)
{
	if (as == NULL)
		return;
	free(*as);
	*as = NULL;
	return;
}