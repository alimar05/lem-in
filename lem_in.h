/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:35:01 by rymuller          #+#    #+#             */
/*   Updated: 2019/08/01 16:23:36 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <libft.h>

typedef struct			s_node
{
	char			*name;
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
	struct s_adjlst		*next;
}						t_adjlst;

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
}						t_lemin;

int						ft_printf(const char *format, ...);
t_adjlst				*ft_adjlst_push_back(t_lemin *lemin, t_node *node);
t_lst				*ft_lst_push_back(t_lemin *lemin,
		t_adjlst *adjlst1, t_adjlst *adjlst2);
void					free_adjlst(t_lemin *lemin);
char					parse_room(t_lemin *lemin, char *line);
char					parse_link(t_lemin *lemin, char *line);
void					free_graph(t_lemin *lemin);
# define ERROR(lemin) free_graph(lemin); write(2, "ERROR\n", 6); return (0)
#endif
