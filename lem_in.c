/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:32:49 by rymuller          #+#    #+#             */
/*   Updated: 2019/08/01 16:33:51 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		initialize(t_lemin *lemin, char **line)
{
	*line = NULL;
	lemin->is_ants = 0;
	lemin->is_start = 0;
	lemin->is_end = 0;
	lemin->number_of_ants = 0;
	lemin->adjlst = NULL;
	lemin->start = NULL;
	lemin->end = NULL;
}

static void		print_graph(t_lemin *lemin)
{
	t_adjlst	*buffer1;
	t_lst		*buffer2;

	ft_printf(">>> start: name = %s, x = %d, y = %d\n",
			lemin->start->node.name,
			lemin->start->node.x,
			lemin->start->node.y);
	ft_printf("<<< end: name = %s, x = %d, y = %d\n",
			lemin->end->node.name,
			lemin->end->node.x,
			lemin->end->node.y);
	buffer1 = lemin->adjlst;
	while (buffer1)
	{
		ft_printf("name = %s, x = %d, y = %d\n",
				buffer1->node.name,
				buffer1->node.x,
				buffer1->node.y);
		buffer2 = buffer1->lst;
		while (buffer2)
		{
			ft_printf("\tlink: name = %s, x = %d, y = %d\n",
					((t_adjlst *)buffer2->adjlst)->node.name,
					((t_adjlst *)buffer2->adjlst)->node.x,
					((t_adjlst *)buffer2->adjlst)->node.y);
			buffer2 = buffer2->next;
		}
		buffer1 = buffer1->next;
	}
}

static char		parse_line(t_lemin *lemin, char *line)
{
	if (*line == ' ' || *line == '\t' || *line == '\0')
	{
		ERROR(lemin);
	}
	else if (!lemin->is_ants && ft_isnumber(line))
	{
		lemin->number_of_ants = ft_atoi(line);
		lemin->is_ants = 1;
	}
	else if (!parse_room(lemin, line))
	{
		if (lemin->adjlst)
		{
			if (!parse_link(lemin, line))
			{
				ERROR(lemin);
			}
		}
		else
		{
			ERROR(lemin);
		}
	}
	return (1);
}

int				main(void)
{
	char		*line;
	t_lemin		lemin;

	initialize(&lemin, &line);
	while (get_next_line(0, &line))
	{
		if (*line == '#' && *(line + 1) != '#')
		{
			free(line);
			continue ;
		}
		else if (!parse_line(&lemin, line))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	if (lemin.start == NULL || lemin.end == NULL)
	{
		ERROR(&lemin);
	}
	print_graph(&lemin);
	free_graph(&lemin);
	return (0);
}
