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

static char		parse_link_names(char *name1, char *name2, char **line)
{
	int		i;

	i = 0;
	while (**line && **line != '-')
	{
		if (**line == ' ' || **line == '\t')
			return (0);
		*(name1 + i++) = *(*line)++;
	}
	*(name1 + i) = '\0';
	if (**line == '-')
		(*line)++;
	if (**line == '\0' || **line == ' ' || **line == '\t')
		return (0);
	i = 0;
	while (**line)
	{
		if (**line == ' ' || **line == '\t')
			return (0);
		*(name2 + i++) = *(*line)++;
	}
	*(name2 + i) = '\0';
	return (1);
}

static char		is_not_link(t_adjlst *adjlst, t_lst *lst,
		unsigned long int name_hash2)
{
	while (adjlst)
	{
		if (adjlst->node.name_hash == name_hash2)
		{
			while (lst)
			{
				if (lst->name_hash == name_hash2)
					return (1);
				lst = lst->next;
			}
			return (0);
		}
		adjlst = adjlst->next;
	}
	return (1);
}

static char		add_link_to_adjlst(t_lemin *lemin,
		unsigned long int name_hash1, unsigned long int name_hash2)
{
	t_lst		*lst;
	t_adjlst	*adjlst;

	if (name_hash1 == name_hash2)
		return (0);
	else if (lemin->adjlst)
	{
		adjlst = lemin->adjlst;
		while (adjlst)
		{
			if (adjlst->node.name_hash == name_hash1)
			{
				if (is_not_link(lemin->adjlst, adjlst->lst, name_hash2))
					return (0);
				else
				{
					adjlst->lst = ft_lst_push_back(adjlst, name_hash2);
					return (1);
				}
			}
			adjlst = adjlst->next;
		}
	}
	return (0);
}

char			parse_link(t_lemin *lemin, char *line)
{
	char		name1[4096];
	char		name2[4096];

	if (*line == 'L' || *line == '\0')
		return (0);
	else
	{
		while (*line == ' ' || *line == '\t')
			line++;
		if (!parse_link_names(name1, name2, &line))
			return (0);
		if (ft_strlen(line))
			return (0);
		if (!add_link_to_adjlst(lemin, ft_hash(name1), ft_hash(name2)))
			return (0);
		return (1);
	}
}
