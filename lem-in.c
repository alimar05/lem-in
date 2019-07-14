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

void			initialize(t_lemin *lemin, char **line)
{
	*line = NULL;
	lemin->number_of_ants = 0;
	lemin->adjlst = NULL;
}

int 			main(void)
{
	char		*line;
	t_lemin		lemin;
	t_lst		*buffer;

	initialize(&lemin, &line);
	while (get_next_line(0, &line))
	{
		if (!parse_room(&lemin, line))
		{
			if (!parse_link(lemin.adjlst, line))
			{
				free_lst(lemin.adjlst);
				write(2, "ERROR\n", 6);
			}
			else
				continue ;
			free_adjlst(&lemin);
			write(2, "ERROR\n", 6);
		}
		free(line);
	}
	buffer = lemin.adjlst->lst;
	while (buffer)
	{
		printf("name = %lu", buffer->name_hash);
		buffer = buffer->next;
	}
/*

	if (get_next_line(0, &line))
	{		
		if (ft_isnumber(line))
		{
			lemin.number_of_ants = ft_atoi(line);
			while (get_next_line(0, &line))
			{
				if (!ft_strcmp(line, "##start"))
					write(1, "##start\n", 8);
				else if (!ft_strcmp(line, "##end"))
					write(1, "##end\n", 6);
				else if (*line == '#')
					write(1, "comment\n", 8);
				else if (is_room(line))
					write(1, "the_room\n", 9);
				else if (is_link(line))
					write(1, "the_link\n", 9);
				else
				{
					write(2, "ERROR\n", 6);
					return (0);
				}
			}
		}
		else
		{
			write(2, "ERROR\n", 6);
			return (0);
		}
	}
	free(line);
	return (0);
*/
/*
{
	t_lst		*lst;
	t_lst		*buf;
	t_node		node;

	lst = NULL;
	node.name = "abc";
	node.x = 0;
	node.y = 2;
	lst = ft_lst_push_back(lst, &node);

	node.name = "xyz";
	node.x = 5;
	node.y = 6;
	lst = ft_lst_push_back(lst, &node);

	node.name = "mnk";
	node.x = 7;
	node.y = 8;
	lst = ft_lst_push_back(lst, &node);
	buf = lst;
	while (buf)
	{
		printf("%s\n", buf->node.name);
		printf("%d\n", buf->node.x);
		printf("%d\n", buf->node.y);
		printf("------------\n");
		buf = buf->next;
	}
	free_lst(&lst);
	return (0);*/
}
