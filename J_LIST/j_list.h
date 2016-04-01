//HEADER

typedef struct	j_like_lst
{
	void				*data;
	int					list_len;
	int					data_len;
	struct j_like_lst	*previous;
	struct j_like_lst	*next;
	int					state;
}				j_list;

j_list			*jlst_node(void); /*creates a fresh null node, OK*/
j_list			*jlst_create(void); /*creates a fresh list, initial size of 9, OK*/
j_list			*jlst_new(int size); /*creates a fresh list, initial size of size, OK*/
void			jlst_add(j_list **first_node, int index, void *data); /*add 'data' to the index'th node of the list, OK*/
void			jlst_push_front(j_list **first_node, void *data); /*add data (in a new node) as the first element of the list, makes a reversed rotation, OK*/
void			jlst_push_back(j_list **first_node, void *data); /*same as push_front but at the last index of the list, OK*/
j_list			*jlst_from_tab(void *tab, int size, int length); /*creates a list out of an array, size is the size of the basic block, OK*/
void			*jlst_get_data(j_list *first_node, int index); /*returns the data at the index 'index'*/
int				jlst_get_index(j_list *first_node, void *data, int (*compare_func)(void*, void*)); /*gets the index of 'data' in the list*/
int				jlst_get_size(j_list *first_node); /*returns the number of elements in the list*/
int				jlst_instances(j_list *first_node, void *data, int (*compare_func)(void*, void*)); /*returns the number of instances of 'data' in LIST*/
void			jlst_sort(j_list **first_node, int (*compare_func)(void*, void*)); /*sorts the list according to 'compare_func', that's not advised because it takes many operations*/
void			jlst_compact(j_list *first); /*compacts the list so it's continuous*/
void			jlst_merge(j_list *first_list, j_list *second_list); /*add 'second_list' to the end of 'first_list'*/
void			jlst_del_node(j_list **first_node, int index); /*deletes the node at 'index' in the list*/
void			jlst_del_data(j_list **first_node, void *data, int (*compare_func)(void*, void*));
void			jlst_del_list(j_list *first_node); /*deletes the whole list*/
int				jlst_in_jlst(j_list *great_list, j_list *to_search); /*search a list in a greater list, and returns the index of its first element, or -1 if it was not found, not taking blanks in account for the list to search for*/
int				jlst_length(j_list *first_node); /*returns the length of the list, that is to say the maximum size it can hold*/
void			jlst_resize(j_list **first_node); /*increase list by two third*/
int				jlst_is_sorted(j_list *first_node, int (*compare_func)(void* void*));
void			jlst_nforward(int n, j_list **first_node);
void			jlst_nbackward(int n, j_list **first_node);
void			jlst_sed(j_list *first_node);
j_list			*jlst_nodecpy(j_list *to_copy);
void			*jlst_datacpy(j_list *node);