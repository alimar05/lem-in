/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:47:19 by rymuller          #+#    #+#             */
/*   Updated: 2019/07/25 13:31:58 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static char			parse_coord(char **line, t_node *node)
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

static char			is_duple_room(t_lemin *lemin, t_node *node)
{
	t_adjlst	*adjlst;

	if (lemin->adjlst)
	{
		adjlst = lemin->adjlst;
		while (adjlst)
		{
			if (!ft_strcmp(adjlst->node.name, node->name))
				return (1);
			if ((adjlst->node.x == node->x) && (adjlst->node.y == node->y))
				return (1);
			adjlst = adjlst->next;
		}
	}
	return (0);
}

char				parse_room(t_lemin *lemin, char *line)
{
	int			i;
	t_node		node;
	char		name[4096];

	if (*line == 'L' || *line == '\0')
		return (0);
	else
	{
		i = 0;
		while (*line && *line != ' ' && *line != '\t')
			*(name + i++) = *line++;
		*(name + i) = '\0';
		if (!parse_coord(&line, &node))
			return (0);
		if (ft_strlen(line))
			return (0);
		node.name = ft_strdup(name);
		if (is_duple_room(lemin, &node))
			return (0);
		lemin->adjlst = ft_adjlst_push_back(lemin, &node);
		return (1);
	}
}
