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
    j_list *list;
    j_list *tmp;
    char *str;
    int i;
    double tab[] = {1.0, 4.0, 3.0, 9.0, 5.0};
    
	list = jlst_from_tab((void*)tab, 8, 5);

	printf("La liste list %s triee\n", jlst_is_sorted(list, &compare_func) ? "est" : "n'est pas");
	jlst_sort(&list, &compare_func);
	printf("DONE\n");
	fflush(stdout);
	printf("La liste list %s triee\n", jlst_is_sorted(list, &compare_func) ? "est" : "n'est");

	tmp = list;
	while (tmp)
	{
		printf("Tmp : %f\n",  *(double*)tmp->data);
		tmp = tmp->next;
	}

	printf("Yop\n");
	fflush(stdout);
	jlst_resize(&list);
	printf("Yop\n");
	fflush(stdout);
	jlst_compact(&list);
	printf("La liste list a une longueur de %d\n", jlst_length(list));
	fflush(stdout);
	jlst_sed(list);
	printf("La liste list a une longueur de %d\n", jlst_length(list));
	fflush(stdout);

	jlst_push_back(&list, &(tab[2]), 8, 0);
	tmp = list;
	while (tmp)
	{
		printf("Tmp : %f\n",  *(double*)tmp->data);
		tmp = tmp->next;
	}
	
	jlst_reverse(&list);
	printf("\nApres reverse :\n");
	tmp = list;
	while (tmp)
	{
		printf("Tmp : %f\n",  *(double*)tmp->data);
		tmp = tmp->next;
	}
    return (0);
}
