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
	t_adjlst	*buffer1;
	t_lst		*buffer2;

	initialize(&lemin, &line);
	while (get_next_line(0, &line))
	{
		if (!parse_room(&lemin, line))
		{
			if (lemin.adjlst)
			{
				if (!parse_link(&lemin, line))
				{
					free_graph(&lemin);
					free(line);
					write(2, "ERROR\n", 6);
					return (0);
				}
			}
			else
			{
				write(2, "ERROR\n", 6);
				free(line);
				return (0);
			}
		}
		free(line);
	}
	// print graph
	buffer1 = lemin.adjlst;
	while (buffer1)
	{
		printf("name = %lu, x = %d, y = %d\n", buffer1->node.name_hash, buffer1->node.x, buffer1->node.y);
		buffer2 = buffer1->lst;
		while (buffer2)
		{
			printf("name = %lu\n", buffer2->name_hash);
			buffer2 = buffer2->next;
		}
		buffer1 = buffer1->next;
	}
	free_graph(&lemin);
	return (0);
}
