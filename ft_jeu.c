#include "code_name.h"

int        ft_open_liste_mot(t_data *data)
{
    int     i;
	FILE	*fd;
	int		ret;
    char    mot[16];

    i = 0;
    if ((fd = fopen("./liste_mots.txt", "r")) == NULL)
		printf("Erreur dans la lecture du fichier des mots.\n");
	bzero(mot, 16);
    while ((ret = fscanf(fd, "%s\n", mot)) > 0)
    {
		for(int j = 0; j < 16; j++)
			data->liste[i][j] = mot[j];
        bzero(mot, 16);
		i++;
    }
    return (i);
}

void		ft_random(int nb_mot, t_data *data, GtkWidget *pButton[25])
{
	int			i;
	int			j;
	int			tab[nb_mot];

	i = 0;
	j = 0;
	srand(time(NULL));
	ft_melanger(tab, nb_mot);
	for(int i = 0; i < 25; i++)
		pButton[i] = gtk_button_new_with_label(data->liste[tab[i]]);
}

void        ft_jeu(t_data *data, GtkWidget *pButton[25])
{
	int		nb_mot;

	nb_mot = ft_open_liste_mot(data);
	ft_random(nb_mot, data, pButton);
}
