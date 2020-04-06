#ifndef CODE_NAME_H
# define CODE_NAME_H


# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
//includes pour random
# include <time.h>
//partie graphique
# include <gtk/gtk.h>

typedef struct		s_perso
{
    char		*name;
	char		*mail;
}					t_perso;

typedef struct 		s_data
{
	t_perso		tab[20];
	t_perso		eq1[10];
	t_perso		eq2[10];
	char		liste[1024][16];
	char		*numero_carte;
	int			numero_cart;
}					t_data;



int		    ft_joueur(t_data *data);
void	    ft_equipe(t_data *data, int nb_joueur);
void        ft_mail(t_data *data, char **env);
void        ft_jeu(t_data *data, GtkWidget *pButton[25]);
void	 	ft_melanger(int* tab,int nb);
void        ft_carte(t_data *data);
GtkWidget	*ft_label_equipe(t_data *data, char *str_couleur, char *fg);
void        putstr(char *s);
char		*ft_strjoin(char const *s1, char const *s2);

#endif