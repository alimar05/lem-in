/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_link.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 15:51:47 by rymuller          #+#    #+#             */
/*   Updated: 2019/08/01 16:34:21 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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

static char		add_lst_name2(t_lemin *lemin, t_adjlst *adjlst1,
		unsigned long int name_hash2)
{
	t_lst		*lst;
	t_adjlst	*adjlst2;

	adjlst2 = lemin->adjlst;
	while (adjlst2)
	{
		if (adjlst2->node.name_hash == name_hash2)
		{
			lst = adjlst1->lst;
			while (lst)
			{
				if (((t_adjlst *)lst->adjlst)->node.name_hash == name_hash2)
					return (0);
				lst = lst->next;
			}
			adjlst1->lst = ft_lst_push_back(lemin, adjlst1, adjlst2);
			return (1);
		}
		adjlst2 = adjlst2->next;
	}
	return (0);
}

static char		add_link_name1_name2(t_lemin *lemin,
		unsigned long int name_hash1, unsigned long int name_hash2)
{
	t_adjlst	*adjlst1;

	if (name_hash1 == name_hash2)
		return (0);
	else if (lemin->adjlst)
	{
		adjlst1 = lemin->adjlst;
		while (adjlst1)
		{
			if (adjlst1->node.name_hash == name_hash1)
			{
				if (add_lst_name2(lemin, adjlst1, name_hash2))
					return (1);
				else
					return (0);
			}
			adjlst1 = adjlst1->next;
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
		if (!add_link_name1_name2(lemin, ft_hash(name1), ft_hash(name2)))
			return (0);
		return (1);
	}
}
