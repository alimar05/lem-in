/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:32:49 by rymuller          #+#    #+#             */
/*   Updated: 2019/07/13 16:27:18 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem-in.h"

static void		initialize(t_lemin *lemin, char **line)
{
	*line = NULL;
	lemin->is_ants = 1;
	lemin->number_of_ants = 0;
	lemin->adjlst = NULL;
}

static void		print_graph(t_lemin *lemin)
{
	t_adjlst	*buffer1;
	t_lst		*buffer2;

	buffer1 = lemin->adjlst;
	while (buffer1)
	{
		printf("hash = %lu, x = %d, y = %d\n", buffer1->node.name_hash, buffer1->node.x, buffer1->node.y);
		buffer2 = buffer1->lst;
		while (buffer2)
		{
			printf("hash = %lu\n", buffer2->name_hash);
			buffer2 = buffer2->next;
		}
		buffer1 = buffer1->next;
	}
}

char			parse_line(t_lemin *lemin, char *line)
{
	if (lemin->is_ants && ft_isnumber(line))
	{
		lemin->number_of_ants = ft_atoi(line);
		lemin->is_ants = 0;
	}
	else if (!parse_room(lemin, line))
	{
		if (lemin->adjlst)
		{
			if (!parse_link(lemin, line))
			{
				free_graph(lemin);
				ERROR(line);
			}
		}
		else
		{
			ERROR(line);
		}
	}
	free(line);
	return (1);
}

int 			main(void)
{
	char		*line;
	t_lemin		lemin;

	initialize(&lemin, &line);
	while (get_next_line(0, &line))
	{
		if (*line == '#')
			continue ;
		else if (!parse_line(&lemin, line))
			return (0);
	}
	print_graph(&lemin);
	free_graph(&lemin);
	return (0);
}
