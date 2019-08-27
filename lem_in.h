/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:35:01 by rymuller          #+#    #+#             */
/*   Updated: 2019/08/10 16:39:52 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <libft.h>

typedef struct			s_node
{
	char				*name;
	int					x;
	int					y;
}						t_node;

typedef struct			s_lst
{
	void				*adjlst;
	struct s_lst		*next;
}						t_lst;

typedef struct			s_adjlst
{
	t_node				node;
	t_lst				*lst;
	int					level;
	unsigned int		visited:2;
	struct s_adjlst		*next;
}						t_adjlst;

typedef struct			s_path
{
	t_adjlst		*start;
	t_lst			*lst;
	int			path_len;
	struct s_path		*next;
}				t_path;

typedef struct			s_lemin
{
	int					number_of_ants;
	unsigned int		is_ants:1;
	unsigned int		is_start:1;
	unsigned int		is_end:1;
	t_adjlst			*adjlst;
	t_adjlst			*start;
	t_adjlst			*end;
	t_adjlst			*buffer;
	t_lst				*queue;
	t_lst				*stack;
	t_path				*last_path;
	t_path				*paths;
}						t_lemin;

int						ft_printf(const char *format, ...);
t_adjlst				*ft_adjlst_push_back(t_lemin *lemin, t_node *node);
t_lst					*ft_new_lst(t_adjlst *adjlst);
t_lst					*ft_lst_push_back(t_lemin *lemin,
		t_adjlst *adjlst1, t_adjlst *adjlst2);
void					free_adjlst(t_lemin *lemin);
char					parse_room(t_lemin *lemin, char *line);
char					parse_link(t_lemin *lemin, char *line);
void					free_graph(t_lemin *lemin);
void					ft_push_queue(t_lemin *lemin, t_adjlst *adjlst);
void					ft_pop_queue(t_lemin *lemin);
char					not_in_queue(t_lemin *lemin, t_adjlst *adjlst);
void					ft_push_stack(t_lemin *lemin, t_adjlst *adjlst);
void					ft_pop_stack(t_lemin *lemin);
char					not_in_stack(t_lemin *lemin, t_adjlst *adjlst);
void					breadth_first_search_to_start(t_lemin *lemin);
void					depth_first_search_to_end(t_lemin *lemin);
void					del_lst(t_lst **lst, t_adjlst *adjlst);
void					add_shortest_path_to_paths(t_lemin *lemin);
# define ERROR(lemin) free_graph(lemin); write(2, "ERROR\n", 6); return (0)
#endif
