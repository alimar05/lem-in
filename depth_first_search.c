#include "lem_in.h"

static void		add_neighbors_adjlst_to_stack(t_lemin *lemin,
		t_adjlst *adjlst)
{
	t_lst		*buffer;

	buffer = adjlst->lst;
	while (buffer)
	{
		if (((t_adjlst *)buffer->adjlst)->visited == 1)
			ft_push_stack(lemin, buffer->adjlst);
		buffer = buffer->next;
	}
}

void			depth_first_search_to_end(t_lemin *lemin)
{
	t_adjlst	*top_stack;

	lemin->start->visited = 2;
	add_neighbors_adjlst_to_stack(lemin, lemin->start);
	while (lemin->stack)
	{
		top_stack = lemin->stack->adjlst;
		ft_pop_stack(lemin);
		top_stack->visited = 2;
		add_neighbors_adjlst_to_stack(lemin, top_stack);
	}
}
