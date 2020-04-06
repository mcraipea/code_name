#include "code_name.h"

void        ft_carte(t_data *data)
{
    int     tab[4];

    srand(time(NULL));
    ft_melanger(tab, 4);
    printf("tab[0] = %i\n", tab[0]);
    data->numero_cart = tab[0];
    if (tab[0] == 0)
        data->numero_carte = strdup("1");
    else if (tab[0] == 1)
        data->numero_carte = strdup("2");
    else if (tab[0] == 2)
        data->numero_carte = strdup("3");
    else if (tab[0] == 3)
        data->numero_carte = strdup("4");
}