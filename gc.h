/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gc.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sait-alo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:30:16 by sait-alo          #+#    #+#             */
/*   Updated: 2024/05/11 16:30:23 by sait-alo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GC_H
# define GC_H

# include <stdlib.h>

# define ALLOC 'A'
# define FREE 'F'

typedef struct s_gc
{
	void		*ptr;
	struct s_gc	*next;
}				t_gc;

void	*m_alloc(size_t __size, char todo);

#endif 
