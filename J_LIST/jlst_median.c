// HEADER

#include "j_list.h"

/**
 * Code :
 * 1 - Index
 * 2 - State
 * 3 - Data
 * 4 - Node
 * 5 - Memory allocation
**/

void    *jlst_median(j_list *list, int (*compare_func)(void*, void*), char code)
{
    j_list  *tmp;
    void    *ret;
    int     index;
    
    tmp = jlst_duplicate(list); // On cree une liste temporaire identique
    jlst_sort(&tmp, compare_func); // On la trie
    if (code == 1) // Si on veut renvoyer l'index
    {
        index = jlst_get_index(list, jlst_get_data(tmp, tmp->list_len / 2), compare_func); // On recup' l'index du noeud median dans la liste d'origine
        jlst_del_list(tmp);
        return ((void*)&index);
    }
    else if (code == 2) // Si on veut renvoyer l'état
    {
        index = jlst_get_data(tmp, tmp->list_len / 2) == (void*)-1 ? 0 : 1; // Get data doit renvoyer (void*)-1 si l'état du noeud est à 0
        jlst_del_list(tmp);
        return ((void*)&index);
    }
    else if (code == 3) // Si on veut renvoyer la data
    {
        ret = jlst_get_data(tmp, tmp->list_len / 2); // On prend la data du noeud median
        jlst_del_list(tmp);
        return (ret);
    }
    else // Sinon
    {
        jlst_nforward(tmp->list_len / 2, &list); // On avance dans la liste temporaire jusqu'au noeud median
        index = tmp->alloc_; // On set index sur alloc
        ret = (void*)jlst_get_node(list, tmp->data, compare_func); // On recup' le node median dans la liste d'origin
        jlst_set_start(tmp); // On remet tmp au debut
        jlst_del_list(tmp);
        return (code == 4 ? ret : (void*)&index);
    }
} // Dans tous les cas on free la liste temporaire!