/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:51:47 by rymuller          #+#    #+#             */
/*   Updated: 2019/07/13 16:44:26 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

char			parse_link(t_lemin *lemin, char *line)
{
	int			i;
	char		name1[4096];
	char		name2[4096];

	if (*line == 'L' || *line == '\0')
		return (0);
	else
	{
		while (*line == ' ' || *line == '\t')
			line++;
		i = 0;
		while (*line && *line != '-' && *line != ' ' && *line == '\t')
			*(name1 + i++) = *line++;
		if (*line == '\0')
			return (0);
		line++;
		if (*line == '\0')
			return (0);
		i = 0;
		while (*line && *line != ' ' && *line != '\t')
			*(name2 + i++) = *line++;
		if (ft_strlen(line))
			return (0);
		printf("%s-%s\n", name1, name2);
		return (1);
	}
}
