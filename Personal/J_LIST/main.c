/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 18:40:04 by mlevieux          #+#    #+#             */
/*   Updated: 2016/09/06 23:03:57 by mlevieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "j_list.h"
#include <stdio.h>
#include <string.h>

int compare_func(void *e1, void *e2)
{
    int tmp;

	tmp = *((int*)e1) - *((int*)e2);
	if (tmp > 0)
		return (1);
	else if (tmp < 0)
		return (-1);
	else
		return (0);
}

int main(void)
{
	j_list *tmp;

	j_list *first = jlst_create();
	printf("On vien de creer une chaine de 9\n");
	fflush(stdout);

	j_list *second = jlst_new(15);
	printf("On vien de creer une chaine de 15\n\n");
	fflush(stdout);

	tmp = first;
	while (tmp)
	{
		printf("On est dans la chaine de 9\n");
		tmp = tmp->next;
	}

	printf("\n");
	
	tmp = second;
	while (tmp)
	{
		printf("On est dans la chaine de 15\n");
		tmp = tmp->next;
	}
	
	printf("\n");

	j_list *full = jlst_full_node(strdup("LOL"), 3, 1);
	printf("On vient de creer un noeud complet\n");
	fflush(stdout);
	
	printf("\n");

	jlst_add(&first, 6, full);
	printf("On vient d'ajouter le noeud plein a l'index 6 de la premiere liste\n");

	tmp = first;
	while (tmp)
	{
		printf("On est dans la chaine de 9, le noeud contient : %s\n", tmp->data);
		tmp = tmp->next;
	}

	printf("\n");

	jlst_add_data(&first, 4, "mdr", 3);
	printf("on vient d'ajouter de la data dans la premiere liste\n");
	fflush(stdout);

	tmp = first;
	while (tmp)
	{
		printf("On est dans la chaine de 9, le noeud contient : %s\n", tmp->data);
		tmp = tmp->next;
	}

	jlst_push_front(&first, strdup("xpldr"), 5, 1);
	printf("\nOn vient d'ajouter un noeud frais en tout debut de liste chainee\n");

	tmp = first;
	while (tmp)
	{
		printf("On est dans la chaine de 10 maintenant, le noeud contient : %s\n", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");fflush(stdout);


	jlst_push_back(&first, strdup("xpldr2"), 6, 1);
	printf("On vient de faire la meme en fin de liste et on va verifier\n");

	tmp = first;
	while (tmp)
	{
		printf("On est dans la chaine de 11 maintenant, le noeud contient : %s\n", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");fflush(stdout);

	int tab[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	printf("On va creer une liste a partir d'un tableau d'entiers\n");fflush(stdout);
	j_list *list = jlst_from_tab(tab, 4, 10);
	printf("C'est fait, on va parcourir\n");

	tmp = list;
	while (tmp)
	{
		printf("On est dans la chaine list maintenant, le noeud contient : %d\n", *((int*)tmp->data));
		tmp = tmp->next;
	}
	printf("\n");fflush(stdout);

	printf("On va recuperer de la data, de first, et puis de liste...\n");
	void *data1 = jlst_get_data(first, 5);
	void *data2 = jlst_get_data(first, 0);
	int *data3 = jlst_get_data(list, 0);
	int *data4 = jlst_get_data(list, 6);
	printf("Datas de first : %s, %s\nDatas de list : %d, %d\n\n", data1, data2, *data3, *data4);
	
	printf("On va tenter de recuperer l'index des valeurs entieres 2 et 11 dans list\n");
	int *data5 = (int*)malloc(sizeof(int) * 1);
	*data5 = 2;
	int uno = jlst_get_index(list, (void*)data5, &compare_func);
	printf("LOL\n");fflush(stdout);
	*data5 = 11;
	int dos = jlst_get_index(list, (void*)data5, &compare_func);
	printf("On a uno = %d, et dos = %d\n\n", uno, dos);

	int *tab2 = (int*)malloc(sizeof(int) * 10);
	tab2[0] = 3;
	tab2[1] = 2;
   	tab2[2] = 8;
   	tab2[3] = 1;
	tab2[4] = -5;
	tab2[5] = -3;
	tab2[6] = 7;
	tab2[7] = 5;
	tab2[8] = 90;
	tab2[9] = 11;
	j_list *list2 = jlst_from_tab(tab2, 4, 10);
	jlst_sort(&list2, &compare_func);

	tmp = list2;
	while (tmp)
	{
		printf("Notre liste ressemble a : %d\n", *((int*)tmp->data));
		tmp = tmp->next;
	}
	printf("\n");fflush(stdout);

	printf("On va compacter first et l'afficher pour voir ce que ca donne\n");
	jlst_compact(&first);
	tmp = first;
	while (tmp)
	{
		printf("On est de nouveau dans first, le noeud contient : %s\n", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");fflush(stdout);

	printf("On va tenter de merger first2 et first et d'afficher la liste resultante\n");
	j_list *first2 = jlst_new(5);
	jlst_add(&first2, 2, jlst_full_node(strdup("autreliste"), 10, 1));
	jlst_add(&first2, 0, jlst_full_node(strdup("prems"), 5, 1));
	tmp = first2;
	while (tmp)
	{
		printf("On est dans la chaine first2 maintenant, le noeud contient : %s\n", tmp->data);
		tmp = tmp->next;
	}
	jlst_merge(first, first2);
	printf("\n");fflush(stdout);
	tmp = first;
	while (tmp)
	{
		printf("On est dans la chaine mergee, le noeud contient : %s\n", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");fflush(stdout);

	printf("On va supprimer un noeud de la liste mergee, c'est le noeud a l'indice 2\n");fflush(stdout);
	jlst_del_node(&first, 2);

	tmp = first;
	printf("Taille de la liste : %d\n", first->list_len);
	while (tmp)
	{
		printf("On est dans la chaine mergee qvec un noeud supprime, le noeud contient : %s\n", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");fflush(stdout);

	printf("On va calculer la taille totale de first, second, first2 et list\n");
	printf("Dans l'ordre : %d, %d, %d, %d\n\n", jlst_length(first), jlst_length(second), jlst_length(first2), jlst_length(list));

	printf("On va forcer le resize de first\n");
	jlst_resize(first);

	tmp = first;
	while (tmp)
	{
		printf("On est dans first, le noeud contient : %s\n", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");fflush(stdout);

	printf("On va verifier que notre liste first n'est pas triee mais que list2 l'est bel et bien\n");
	printf("La liste first %s triee\n", jlst_is_sorted(first, &compare_func) ? "est" : "n'est pas");
	printf("La liste list2 %s triee\n\n", jlst_is_sorted(list2, &compare_func) ? "est" : "n'est pas");

	printf("On va avancer list2 de 3 et voir sa taille\n");
	jlst_nforward(3, &list2);
	tmp = list2;
	while (tmp)
	{
		printf("On est dans list2 : %d\n", *((int*)(tmp->data)));
		tmp = tmp->next;
	}
	printf("\n");

	printf("Nickel, de deux dans l'autre sens maintenant\n");
	jlst_nbackward(2, &list2);
	tmp = list2;
	while (tmp)
	{
		printf("On est dans list2 : %d\n", *((int*)(tmp->data)));
		tmp = tmp->next;
	}
	printf("\n");

	j_list *node = jlst_nodecpy(list2);
	printf("Data : %d\n", *((int*)(node->data)));
	printf("Data_len : %zd\n", node->data_len);
	printf("List_len : %d\n", node->list_len);
	printf("Next : %p\n", node->next);
	printf("Prev : %p\n", node->previous);
	printf("State : %d\n", node->state);
	printf("Alloc_ : %d\n", node->alloc_);
	printf("Tree : %d\n", node->is_tree);

	printf("\n");

	printf("On va push une data fraiche respectivement dans first et dans list2\n");
	int a = 300;

	first->data = NULL;
	first->state = 0;
	first->alloc_ = 0;
	jlst_push(first, strdup("plus"), 4, 1);
	jlst_push(list2, &a, 4, 0);
	tmp = first;
	while (tmp)
	{
		printf("On est dans first : %s\n", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
	tmp = list2;
	while (tmp)
	{
		printf("On est dans list2 : %d\n", *((int*)(tmp->data)));
		tmp = tmp->next;
	}
	printf("\n");

	printf("Allez on va tenter de transformer notre liste chainee en arbre...\n");
	jlst_to_tree(&list2, &compare_func, 0);

    return (0);
}
