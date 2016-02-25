/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcavadas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/20 19:07:19 by rcavadas          #+#    #+#             */
/*   Updated: 2016/02/19 16:06:59 by rcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int const fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	int			ret;
	static char	**splittedbuf;

	line = NULL;
	if (BUFF_SIZE < 1)
		return (-1);
	if ((ret = read(fd, buf, BUFF_SIZE)) == 0)
		return (0);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
//		on place dans un tableau de chaine de caracteres le contenu du buffer
		splittedbuf = (ft_strsplit(buf, '\n'));
	}
	ft_putendl(splittedbuf[0]); ft_putendl(splittedbuf[1]); ft_putendl(splittedbuf[2]); 
	return (0);
}	