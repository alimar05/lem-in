/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rymuller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 12:35:01 by rymuller          #+#    #+#             */
/*   Updated: 2019/07/13 16:28:44 by rymuller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include <libft.h>

# include <stdio.h>

typedef struct			s_node
{
	unsigned long int	name_hash;
	int					x;
	int					y;
}						t_node;

typedef struct			s_lst
{
	unsigned long int	name_hash;
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
	t_adjlst			*adjlst;
}						t_lemin;


t_lst					*ft_lst_push_back(t_adjlst *adjlst, unsigned long int name_hash);
t_adjlst				*ft_adjlst_push_back(t_lemin *lemin, t_node *node);
void					free_lst(t_adjlst *adjlst);
void					free_adjlst(t_lemin *lemin);
char					parse_room(t_lemin *lemin, char *line);
char					parse_link(t_lemin *lemin, char *line);
unsigned long int		ft_hash(const char *str);

#endif
