/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:47:19 by rymuller          #+#    #+#             */
/*   Updated: 2019/07/13 16:28:20 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

/*
 * djb2 http://www.cse.yorku.ca/~oz/hash.html
*/

unsigned long int	ft_hash(const char *str)
{
	int				c;
	unsigned long	hash;
	
	hash = 5381;
	while ((c = *str++))
		hash = ((hash << 5) + hash) + c;
	return hash;
}

static char					parse_coord(char **line, t_node *node)
{
	if (**line == '\0')
		return (0);
	while (**line == ' ' || **line == '\t')
		(*line)++;
	if (ft_isnumber(*line))
		node->x = ft_atoi_shift(line);
	else
		return (0);
	if (**line == '\0')
		return (0);
	while (**line == ' ' || **line == '\t')
		(*line)++;
	if (ft_isnumber(*line))
		node->y = ft_atoi_shift(line);
	else
		return (0);
	return (1);
}

char						parse_room(t_lemin *lemin, char *line)
{
	int			i;
	t_node		node;
	char		name[4096];

	if (*line == 'L' || *line == '\0')
		return (0);
	else
	{
		while (*line == ' ' || *line == '\t')
			line++;
		i = 0;
		while (*line && *line != ' ' && *line != '\t')
			*(name + i++) = *line++;
		if (!parse_coord(&line, &node))
			return (0);
		if (ft_strlen(line))
			return (0);
		node.name_hash = ft_hash(name);
		lemin->adjlst = ft_adjlst_push_back(lemin, &node);
		return (1);
	}
}
