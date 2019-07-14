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

char			add_link_to_adjlst(t_adjlst *adjlst,
		unsigned long int name_hash1, unsigned long int name_hash2)
{
	if (adjlst)
	{
		while (adjlst)
		{
			if (adjlst->node.name_hash == name_hash1)
			{
				adjlst->lst = ft_lst_push_back(lemin, name_hash2);
				return (1);
			}
			adjlst = adjlst->next;
		}
	}
	return (0);
}

char			parse_link(t_adjlst *adjlst, char *line)
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
		while (*line && *line != '-')
		{
			if (*line == ' ' || *line == '\t')
				return (0);
			*(name1 + i++) = *line++;
		}
		line++;
		if (*line == '\0' || *line == ' ' || *line == '\t')
			return (0);
		i = 0;
		while (*line)
		{
			if (*line == ' ' || *line == '\t')
				return (0);
			*(name2 + i++) = *line++;
		}
		if (ft_strlen(line))
			return (0);
//		printf("%s-%s\n", name1, name2);
		if (!(add_link_to_adjlst(adjlst, ft_hash(name1), ft_hash(name2))))
		{
			// TO DO free graph
			write(2, "ERROR\n", 6);
		}
		return (1);
	}
}
