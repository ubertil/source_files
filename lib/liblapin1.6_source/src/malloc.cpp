// Jason Brillante "Damdoshi"
// Epitech 1999-2042
//
// Lapin library

#include		<dlfcn.h>
#include		<string.h>
#include		"lapin_private.h"

typedef void		*(*t_sysmalloc)(size_t);
typedef void		(*t_sysfree)(void*);

static int		heap_size = 20;
int			memory_check = 0;
size_t			border0;
size_t			border1;

void			check_memory_state(void);

struct memhead		*memory_head(void)
{
  static struct memhead	*head = NULL;

  if (head == NULL)
    {
      t_sysmalloc	sysmalloc = malloc; //(t_sysmalloc)dlsym(RTLD_NEXT, "malloc");
      size_t		s = 1024 * 1024 * heap_size + sizeof(*head);

      if (sysmalloc == NULL)
	{
	  fprintf(stderr, "Cannot found the system allocator.");
	  exit(EXIT_FAILURE);
	}
      memset(&border0, 0x42, sizeof(border0));	// Because size_t size is quite volatile...
      memset(&border1, 0x84, sizeof(border1));
      head = (struct memhead*)sysmalloc(s);
      head->alloc_count = 0;
      head->total_count = 0;
      head->alloc = 0;
      head->total = 0;
      head->first = NULL;
      head->limit = &(((char*)head)[s]);
      head->last_position = &(((char*)head)[sizeof(*head)]);
      atexit(check_memory_state);
    }
  return (head);
}

extern "C" void		set_max_heap_size(size_t	data)
{
  static int		edited;

  if (!edited)
    heap_size = data;
  edited = 1;
}

extern "C" size_t	get_max_heap_size(void)
{
  return (heap_size);
}

extern "C" size_t	get_nb_alloc(void)
{
  struct memhead	*head;

  head = memory_head();
  return (head->alloc);
}

static int		check_list(struct memchunk	*chunk)
{
  if (chunk == NULL)
    return (0);
  struct memchunk	*ch;
  int			i;

  i = 0;
  ch = chunk;
  do
    {
      if (ch->border0 != border0 || ch->border1 != border1)
	i += 1;
      ch = ch->next;
    }
  while (ch != chunk);
  return (i);
}

static int		check_tree(struct memtree	*tree)
{
  if (tree == NULL)
    return (0);
  int			i;

  i = check_list(tree->allocated);
  i += check_list(tree->freed);
  i += check_tree(tree->lesser);
  i += check_tree(tree->greater);
  return (i);
}

void			check_memory_state(void)
{
  t_sysfree		sysfree = free; /* (t_sysfree)dlsym(RTLD_NEXT, "free"); */

  if (memory_check == 0)
    {
      sysfree(memory_head());
      return ;
    }
  struct memhead	*head;
  int			i;

  head = memory_head();
  fprintf(stderr, "Call to malloc: %lu\n", head->alloc_count);
  fprintf(stderr, "Sum of all byte requests: %lu\n", head->total_count);
  fprintf(stderr, "Currently allocated chunks: %lu\n", head->alloc);
  fprintf(stderr, "Currently allocated bytes: %lu\n", head->total);
  i = check_tree(head->first);
  fprintf(stderr, "Altered chunks: %d\n", i);
  sysfree(memory_head());
}

void			*bunny_malloc(size_t		data)
{
  struct memhead	*head;
  struct memchunk	*node;

  if (data % 32)
    data += 32 - (data % 32);
  head = memory_head();
  if ((node = get_node(head, data)) == NULL)
    return (NULL);
  head->alloc_count += 1;
  head->total_count += data;
  head->alloc += 1;
  head->total += data;
  node->border0 = border0;
  node->border1 = border1;
  return (&((char*)node)[sizeof(struct memchunk)]);
}

