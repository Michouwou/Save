#include "j_list.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    j_list *list;
    j_list *tmp;
    char *str;
    int i;
    
    i = 0;
    str = (char*)malloc((sizeof(char)) * 10);
    
    list = jlst_create();
    tmp = list;
    while (tmp)
    {
        tmp = tmp->next;
        i++;
    }
    printf("La liste a un longueur de %d\n", i);
    
    strcpy(str, "Bonjour");
    jlst_add(&list, 3, (void*)str);
    i = 0;
    tmp = list;
    while (i < 3)
    {
        tmp = tmp->next;
        i++;
    }
    printf("L'indice trois contient : %s, de taille %d\n", (char*)tmp->data, tmp->data_len);
    return (0);
}