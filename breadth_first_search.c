#include "lem_in.h"

static void		add_neighbors_adjlst_to_queue(t_lemin *lemin)
{
	t_lst		*buffer;

	buffer = ((t_adjlst *)lemin->queue->adjlst)->lst;
	while (buffer)
	{
		if (not_in_queue(lemin, buffer->adjlst))
		{
			ft_push_queue(lemin, buffer->adjlst);
			if (!(((t_adjlst *)buffer->adjlst)->visited))
			{
				((t_adjlst *)buffer->adjlst)->level = \
					((t_adjlst *)lemin->queue->adjlst)->level + 1;
			}
		}
		buffer = buffer->next;
	}
}

void			breadth_first_search_to_start(t_lemin *lemin)
{
	ft_push_queue(lemin, lemin->end);
	while (lemin->queue)
	{
		if (!(((t_adjlst *)lemin->queue->adjlst)->visited))
		{
			add_neighbors_adjlst_to_queue(lemin);
			((t_adjlst *)lemin->queue->adjlst)->visited = 1;
		}
		ft_pop_queue(lemin);
	}
}
