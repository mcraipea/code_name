#include "code_name.h"

int		ft_joueur(t_data *data)
{
    int     i;
	FILE	*fd;
	int		ret;
	char	name[64];
	char	mail[64];
	
	i = 0;
	if ((fd = fopen("./fichier_source.txt", "r")) == NULL)
		printf("Erreur dans la lecture du fichier des noms.\n");
	while ((ret = fscanf(fd, "%s\n", name)) > 0)
	{
		data->tab[i].name = strdup(name);
		if ((ret = fscanf(fd, "%s\n", mail)) < 0)
			printf("Il manque une adresse mail dans le fichier.\n");
		data->tab[i].mail = strdup(mail);
		i++;
	}
	return (i);
}

void	ft_afficher(t_data *data, int x)
{
	int			i;
	int			j;

	i = 0;
	j = 1;
	printf("\nLes equipes sont : \n\n");
	printf("        BLEU         |      ROUGE      \n");
	while (i < x)
	{
		printf("%i - %-15s  |     %i - %-15s\n", j, data->eq1[i].name, j, data->eq2[i].name);
		i++;
		j++;
	}
	printf("\n");
}

void 	ft_melanger(int* tab,int nb)
{
    int 	i;
	int		nb2;
    
	nb2 = nb;
	for(i = 0; i < nb; i++)
        tab[i] = i;
    for(i = 0; i < nb; i++)
    {
        int tmp;
        int index = rand()%nb2;
        tmp = tab[index];
        tab[index] = tab[nb2-1];
        tab[nb-i-1] = tmp;
        nb2--;
    }
}

void	ft_equipe(t_data *data, int nb_joueur)
{
	int		i;
	int		j;
	int		x;
	int		tab[nb_joueur];
	
	i = 0;
	j = 0;
	srand(time(NULL));
	ft_melanger(tab, nb_joueur);
	if (nb_joueur % 2 == 1)
		x = nb_joueur / 2 + 1;
	else
		x = nb_joueur / 2;
	while (i < x)
	{
		data->eq1[i].name = strdup(data->tab[tab[i]].name);
		data->eq1[i].mail = strdup(data->tab[tab[i]].mail);
		i++;
	}
	while (i < nb_joueur)
	{
		data->eq2[j].name = strdup(data->tab[tab[i]].name);
		data->eq2[j].mail = strdup(data->tab[tab[i]].mail);
		i++;
		j++;
	}
	ft_afficher(data, x);
}