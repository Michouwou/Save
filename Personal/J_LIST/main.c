/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlevieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 18:40:04 by mlevieux          #+#    #+#             */
/*   Updated: 2016/09/06 20:04:16 by mlevieux         ###   ########.fr       */
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

	while (second)
	{
		printf("On est dans la chaine de 15\n");
		second = second->next;
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
    return (0);
}
