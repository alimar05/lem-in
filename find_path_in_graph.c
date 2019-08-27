#include "lem_in.h"

static t_path		*ft_new_path_lst(t_adjlst *adjlst)
{
	t_path			*path;

	if (!(path = (t_path *)malloc(sizeof(path))))
		return (NULL);
	path->start = adjlst;
	path->lst = NULL;
	path->path_len = 0;
	path->next = NULL;
	return (path);
}

static void		ft_path_lst_push_back(t_lemin *lemin, t_adjlst *adjlst)
{
	t_lst			*buffer;

	if (lemin->last_path)
	{
		if (lemin->last_path->lst)
		{
			buffer = lemin->last_path->lst;
			while (buffer->next)
				buffer = buffer->next;
			if (!(buffer->next = ft_new_lst(adjlst)))
			{
				free_graph(lemin);
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			if (!(buffer = ft_new_lst(adjlst)))
				exit(EXIT_FAILURE);
			lemin->last_path->lst = buffer;
		}
	}
}

static void		ft_paths_push_back(t_lemin *lemin, t_adjlst *adjlst)
{
	t_path			*buffer;

	if (lemin->paths)
	{
		buffer = lemin->paths;
		while (buffer->next)
			buffer = buffer->next;
		if (!(buffer->next = ft_new_path_lst(adjlst)))
		{
			free_graph(lemin);
			exit(EXIT_FAILURE);
		}
		lemin->last_path = buffer->next;
	}
	else
	{
		if (!(buffer = ft_new_path_lst(adjlst)))
			exit(EXIT_FAILURE);
		lemin->last_path = buffer;
		lemin->paths = buffer;
	}
}

static t_adjlst		*adjlst_with_min_level(t_lst *lst)
{
	t_adjlst	*adjlst;

	adjlst = (t_adjlst *)lst->adjlst;
	while (lst)
	{
		if (((t_adjlst *)lst->adjlst)->level < adjlst->level)
			adjlst = lst->adjlst;
		lst = lst->next;
	}
	return (adjlst);
}

void			add_shortest_path_to_paths(t_lemin *lemin)
{
	t_lst		*lst;
	t_adjlst	*adjlst;

	adjlst = lemin->start;
	ft_paths_push_back(lemin, adjlst);
	lemin->last_path->path_len++;
	while (adjlst != lemin->end)
	{
		lemin->last_path->path_len++;
		lst = adjlst->lst;
		adjlst = adjlst_with_min_level(lst);
		ft_path_lst_push_back(lemin, adjlst);
		if (adjlst != lemin->end)
			del_lst(&lst, adjlst);
	}
}
