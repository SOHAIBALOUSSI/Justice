
#include <stdlib.h>
#define ALLOC 'A'
#define FREE 'F'

typedef struct	s_gc
{
	void		*ptr;
	struct s_gc	*next;
}				t_gc;

t_gc	*m_new_node(void *ptr)
{
	t_gc	*to_collect;

	to_collect = malloc(sizeof(t_gc));
	if (!to_collect)
		return (NULL);
	to_collect->ptr = ptr;
	to_collect->next = NULL;
	return (to_collect);
}

void	m_add_back(t_gc **lst, t_gc *new)
{
	static	t_gc	*last;
	
	if (!lst)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		last = new;
		return ;
	}
	last->next = new;
	last = new;
}

/// @brief Allocate SIZE bytes of memory and save its address
/// @param __size Size of memory to be allocated
/// @param todo If set to 'FREE', all the Memory allocated during program execution will be freed
/// @return The allocated memory block
void	*m_alloc(size_t __size, char todo)
{
	void		*ptr;
	t_gc		*del;
	static	t_gc *arena;

	if (todo == FREE)
	{
		while (arena)
		{
			del = arena;
			arena = arena->next;
			free(del->ptr);
			free(del);
		}
		arena = NULL;
		return (NULL);
	}
	ptr = malloc(__size);
	if (!ptr)
		return (NULL);
	return(m_add_back(&arena, m_new_node(ptr)), ptr);
}
