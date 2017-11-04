/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/15 19:33:45 by eramirez          #+#    #+#             */
/*   Updated: 2017/11/03 20:39:52 by eramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_getnl	*gnl_start(int fd, t_getnl *head)
{
	t_getnl	*temp;

	if (head == NULL)
	{
		temp = (t_getnl *)malloc(sizeof(t_getnl));
		temp->fd = fd;
		ft_bzero(temp->buff, BUFFS);
		temp->next = NULL;
		return(temp);
	}
	while (head->fd != fd && head->next != NULL)
		head = head->next;
	if (head->fd == fd)
		return(head);
	temp = (t_getnl *)malloc(sizeof(t_getnl));
	temp->fd = fd;
	ft_bzero(temp->buff, BUFFS);
	temp->next = NULL;
	head->next = temp;
	return(temp);
}

char	*free_join(char *line, char const *buff)
{
	int		i;
	char	*joined;
	char	*temp;

	if (line == 0 && buff == 0)
		return (ft_strnew(0));
	else if (line == 0)
		return (ft_strdup(buff));
	else if (buff == 0)
		return (ft_strdup(line));
	if (!(joined = ft_strnew(ft_strlen(line) + ft_strlen(buff))))
		return (0);
	i = ft_strlen(line);
	temp = ft_strdup(line);
	free(line);
	ft_memmove(joined, temp, i);
	ft_memmove(&joined[i], buff, ft_strlen(buff));
	free(temp);
	return (joined);
}

void	str_snip(char *str, int snip)
{
	int i;
	char temp[BUFFS];

	i = 0;
	snip++;
	ft_strcpy(temp, str);
	ft_bzero(str, BUFFS);
	while (temp[snip])
	{
		str[i] = temp[snip];
		i++;
		snip++;
	}
}

int	get_the_strap(const int fd, char **line, char *buff)
{
	int i;
	int j;
	char *temp;

	i = 0;
	j = 0;
	while ((i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		*line = free_join(*line, buff);
		if ((j = ft_findchr(buff, '\n')) >= 0)
		{
			temp = ft_strdup(*line);
			free(*line);
			*line = ft_strsub(temp, 0, ft_findchr(*line, '\n'));
			//str_snip(buff, j);
			buff = ft_strncpy(buff, &buff[j + 1], BUFF_SIZE);
			return(1);
		}
		else if (i < BUFF_SIZE)
		{
			ft_bzero(buff, BUFFS);
			return(1);
		}
		ft_bzero(buff, BUFFS);
	}
	if (i == 0 && **line != 0 && buff[0] == '\0')
		return(1);
	return(i);
}

int	get_next_line(const int fd, char **line)
{
	static t_getnl	*head;
	t_getnl			*node;
	int 			i;

	i = 0;
	if (!line || fd < 0)
		return (-1);
	if (head == NULL)
		head = gnl_start(fd, head);
	node = gnl_start(fd, head);
	if ((i = ft_findchr(node->buff, '\n')) >= 0)
	{
		*line = ft_strsub(node->buff, 0, i);
		//node->buff = ft_strncpy(node->buff, &node->buff[i + 1], BUFF_SIZE);
		str_snip(node->buff, i);
		return(1);
	}
	*line = ft_strdup(node->buff);
	ft_bzero(node->buff, BUFFS);
	return (get_the_strap(fd, line, node->buff));
}
