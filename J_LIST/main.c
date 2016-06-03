#include "j_list.h"
#include <stdio.h>
#include <string.h>

int compare_func(void *e1, void *e2)
{
    return (*((double*)e1) - *((double*)e2));
}

int main(void)
{
    j_list *list;
    j_list *tmp;
    char *str;
    int i;
    double tab[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    
    i = 0;
    str = (char*)malloc((sizeof(char)) * 10);
    
    list = jlst_create();
    tmp = list;
    while (tmp)
    {
        tmp = tmp->next;
        i++;
    }
    printf("La liste a un longueur de %d et une longueur effective de %d\n", i, jlst_get_size(list));
    
    strcpy(str, "Bonjour");
    jlst_add(&list, 3, (void*)str, (size_t)strlen(str));
    i = 0;
    tmp = list;
    while (i < 3)
    {
        tmp = tmp->next;
        i++;
    }
    printf("L'indice trois contient : %s, de taille %zd, la liste a une longueur effective de %d\n", (char*)tmp->data, tmp->data_len, jlst_get_size(list));
    
    jlst_push_front(&list, (void*)&i, sizeof(i));
    printf("Le premier element de la liste est maintenant : %d, d'une taille de %zd, la liste a une longueur effective de %d\n", *((int*)list->data), list->data_len, jlst_get_size(list));
    
    list = jlst_from_tab((void*)tab, sizeof(double), 5);
    tmp = list;
    while (tmp)
    {
        printf("tmp contient : %f, de taille %zd\n", *((double*)tmp->data), tmp->data_len);
        tmp = tmp->next;
    }
   
    printf("L'information contenue à l'index 2 est : %f, la liste a une longueur effective de %d\n", *((double*)jlst_get_data(list, 2)), jlst_get_size(list));
    
    printf("L'index auquel est contenue 4.00 se trouve à l'index : %d\n", jlst_get_index(list, (void*)&(tab[3]), &compare_func));
    
    printf("Il y a %d instances de 2.00 dans list\n", jlst_instances(list, (void*)&(tab[1]), &compare_func));
    jlst_add(&list, 3, (void*)&(tab[1]), sizeof(double));
    printf("Il y a %d instances de 2.00 dans list\n", jlst_instances(list, (void*)&(tab[1]), &compare_func));
    
    jlst_sort(&list, &compare_func, 0);
    tmp = list;
    while (tmp)
    {
        printf("tmp contient : %f, de taille %zd\n", *((double*)tmp->data), tmp->data_len);
        tmp = tmp->next;
    }
    return (0);
}