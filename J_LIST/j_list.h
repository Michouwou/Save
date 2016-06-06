/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_list.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/20 15:21:41 by mlevieux          #+#    #+#             */
/*   Updated: 2016/04/20 16:04:15 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct	j_like_lst
{
	void				*data;
	int					list_len;
	size_t				data_len;
	struct j_like_lst	*previous;
	struct j_like_lst	*next;
	char				state;
	char				alloc_;
	char				is_tree;
}				j_list;

// Those are the functions that can be applied on any j_list :

int				jlst_get_size(j_list *first_node); /*returns the number of elements in the listOK*/
int				jlst_instances(j_list *first_node, void *data, int (*compare_func)(void*, void*)); /*returns the number of instances of 'data' in LIST OK*/
void			jlst_del_data(j_list **first_node, void *data, int (*compare_func)(void*, void*)); /*deletes all the nodes containing 'data' OK*/
void			jlst_del_list(j_list *first_node); /*deletes the whole list OK ?*/
int				jlst_in_jlst(j_list *great_list, j_list *to_search, int (compare_func)(void*, void*)); /*search a list in a greater list, and returns the index of its first element, or -1 if it was not found, not taking blanks in account for the list to search for OK*/
void			jlst_sed(j_list *first_node); // Ok ?
void			*jlst_median(j_list *list, int (*compare_func)(void*, void*), char code); // Looks for the median in a list or a tree, code will tell the function to return either the data or the index, or the node etc... OK
void			*jlst_appears(j_list *first_node, void *data, int (*compare_func)(void*, void*)); // OK ?
void			jlst_map(j_list *first_node, void (*function)(j_list *node)); // OK ?
void			jlst_spec_map(j_list *first_node, void *data_ref, void (*function)(j_list *node), int (*compare_func)(void*, void*)); // OK ?
int				jlst_compare(j_list *node1, j_list *node2); // OK ?
j_list			*jlst_split(j_list *first_node, void *data_ref, int (*compare_func)(void*, void*), char is_conservative);
j_list			*jlst_duplicate(j_list *first_node); // OK ?
size_t			jlst_get_total_size(j_list *first_node); // OK ?
void			jlst_del_multiples(j_list *list, int (*compare_func)(void*, void*));

// Those are the functions that can be applied only on lists only :

j_list			*jlst_node(void); /*creates a fresh null node, OK*/
j_list			*jlst_create(void); /*creates a fresh list, initial size of 9, OK*/
j_list			*jlst_new(int size); /*creates a fresh list, initial size of size, OK*/
j_list			*jlst_full_node(void *data, size_t data_len, char a lloc_); // OK ?
void			jlst_add(j_list **first_node, int index, j_list *full_node, char alloc_); /*add 'data' to the index'th node of the list OK*/
void			jlst_add_data(j_list **first_node, int index, void *data, size_t data_len); // memory freeing will not be insured after a call to this function (alloc_ set to 0) OK ? 
void			jlst_push_front(j_list **first_node, void *data, size_t data_size, char alloc_); /*add data (in a new node) as the first element of the list, makes a reversed rotation, OK*/
void			jlst_push_back(j_list **first_node, void *data, size_t data_size, char alloc_); /*same as push_front but at the last index of the list*/
j_list			*jlst_from_tab(void *tab, size_t size, int length); /*creates a list out of an array, size is the size of the basic block, OK*/
void			*jlst_get_data(j_list *first_node, int index); /*returns the data at the index 'index' OK*/
int				jlst_get_index(j_list *first_node, void *data, int (*compare_func)(void*, void*)); /*gets the index of 'data' in the list OK*/
void			jlst_sort(j_list **first_node, int (*compare_func)(void*, void*)); /*sorts the list according to 'compare_func', that's not advised because it takes many operations OK*/
void			jlst_compact(j_list **first); /*compacts the list so it's continuous OK*/
void			jlst_merge(j_list *first_list, j_list *second_list); /*add 'second_list' to the end of 'first_list' OK*/
void			jlst_del_node(j_list **first_node, int index); /*deletes the node at 'index' in the list OK*/
int				jlst_length(j_list *first_node); /*returns the length of the list, that is to say the maximum size it can hold OK*/
void			jlst_resize(j_list **first_node); /*increase list by two third OK*/
int				jlst_is_sorted(j_list *first_node, int (*compare_func)(void*, void*)); // OK ?
void			jlst_nforward(int n, j_list **first_node); // OK
void			jlst_nbackward(int n, j_list **first_node); // OK
j_list			*jlst_nodecpy(j_list *to_copy); // Ok
void			*jlst_datacpy(j_list *node); // Ok
void			*ft_memcpy(void *dst, const void *src, size_t n);
void    		jlst_reverse(j_list **first_node); // OK ?
int				*jlst_dicho_appears(j_list *list, void *data_ref, int (*compare_func)(void*, void*), char code); // OK ?
void			jlst_push(j_list *list, void *data, size_t data_len, char alloc_); // OK ?
void			jlst_to_tree(j_list **first_node, int (*compare_func)(void*, void*), char is_avl);
void			jlst_quick_sort(j_list **first_node, int (*compare_func)(void*, void*));
void			jlst_fusion_sort(j_list **first_node, int (*compare_func)(void*, void*));
void			jlst_shell_sort(j_list **first_node, int (*compare_func)(void*, void*));
void			jlst_comb_sort(j_list **first_node, int (*compare_func)(void*, void*));
void			jlst_select_sort(j_list **first_node, int (*compare_func)(void*, void*));
void			jlst_insert_sort(j_list **first_node, int (*compare_func)(void*, void*));
void			jlst_counter_sort(j_list **first_node, int (*compare_func)(void*, void*));

// Those are the functions that can be applied on trees only :

j_list			*jlst_to_lst(j_list *tree);
void			jlst_balance_tree(j_list **first_node, int (*compare_func)(void*, void*));
j_list			*jlst_build_tree(int depth, char is_avl);
int				jlst_get_depth(j_list *tree);
int				jlst_get_max_depth(j_list *tree);
int				jlst_get_min_depth(j_list *tree);
void			jlst_push_tree(j_list **tree, j_list *node, int (*compare_func)(void*, void*));
j_list			*jlst_tree_from_tab(void *tab, size_t size, int length, int (*compare_func)(void*, void*));
void			jlst_to_redandblack(j_list **tree, int (*compare_func)(void*, void*));
void			jlst_set_avl(j_list *tree);
void			jlst_del_subtrees(j_list **first_node, void *data_ref, int (*compare_func)(void*, void*));
void			jlst_preffix_map(j_list *tree, void (*function)(j_list *node));
void			jlst_suffix_map(j_list *tree, void (*function)(j_list *node));
void			jlst_infix_map(j_list *tree, void (*function)(j_list *node));



