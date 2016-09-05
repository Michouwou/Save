#include "j_list.h"
#include <stdio.h>
#include <string.h>

int compare_func(void *e1, void *e2)
{
    double tmp;
	
	tmp = *((double*)e1) - *((double*)e2);
	if (tmp > 0.0)
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
    return (0);
}
