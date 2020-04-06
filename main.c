#include "code_name.h"

void 	OnDestroy(GtkWidget *pWidget, gpointer pData)
{
    /* Arret de la boucle evenementielle */
    gtk_main_quit();
}

void	ft_click_blue(GtkWidget *widget, gpointer data)
{
	GdkColor 	color;
	char		*str;

	gdk_color_parse("blue", &color);
    gtk_widget_modify_bg(GTK_WIDGET(widget), GTK_STATE_NORMAL, &color);
	gtk_widget_modify_bg(GTK_WIDGET(widget), GTK_STATE_PRELIGHT, &color);
	str = gtk_label_get_label(GTK_LABEL(data));
	str[0] = str[0] + 1;
	gtk_label_set_text(GTK_LABEL(data), str);
}

void	ft_click_red(GtkWidget *widget, gpointer data)
{
	GdkColor 	color;
	char		*str;

	gdk_color_parse("red", &color);
    gtk_widget_modify_bg(GTK_WIDGET(widget), GTK_STATE_NORMAL, &color);
	gtk_widget_modify_bg(GTK_WIDGET(widget), GTK_STATE_PRELIGHT, &color);
	str = gtk_label_get_label(GTK_LABEL(data));
	str[0] = str[0] + 1;
	gtk_label_set_text(GTK_LABEL(data), str);
}

void	ft_click_black(GtkWidget *widget, gpointer data)
{
	GdkColor color;
    
	gdk_color_parse("black", &color);
    gtk_widget_modify_bg(GTK_WIDGET(widget), GTK_STATE_NORMAL, &color);
	gtk_widget_modify_bg(GTK_WIDGET(widget), GTK_STATE_PRELIGHT, &color);
}

void	ft_click_grey(GtkWidget *widget, gpointer *data)
{
	GdkColor color;
    
	gdk_color_parse("grey", &color);
    gtk_widget_modify_bg(GTK_WIDGET(widget), GTK_STATE_NORMAL, &color);
	gtk_widget_modify_bg(GTK_WIDGET(widget), GTK_STATE_PRELIGHT, &color);
}

int		main(int argc, char **argv, char **env)
{
	int			nombre_joueur;
	t_data		*data;
	int			score_bleu = 0;
	int			score_rouge = 0;
	int			carte[4][25] = {{2, 2, 1, 1, 0, 2, 0, 2, 0, 1, 1, 2, 2, 2, 2, 1, 0, 3, 1, 2, 0, 1, 0, 0, 1},{0, 1, 2, 2, 1, 1, 0, 2, 1, 0, 1, 2, 2, 3, 0, 2, 0, 2, 0, 1, 2, 2, 1, 1, 0},{1, 0, 0, 1, 0, 2, 1, 3, 0, 1, 2, 2, 2, 2, 1, 1, 0, 2, 0, 2, 0, 1, 1, 2, 2},{0, 1, 1, 2, 2, 1, 0, 2, 0, 2, 0, 3, 2, 2, 1, 0, 1, 2, 0, 1, 1, 2, 2, 1, 0}};
    /* Declaration des widget */
    GtkWidget		*pWindow;
	GtkWidget		*pVBox;
	GtkWidget 		*pVBox1;
	GtkWidget 		*pVBox2;
	GtkWidget 		*pVBox3;
	GtkWidget 		*pVBox4;
	GtkWidget 		*pVBox5;
	GtkWidget 		*pVBox6;
    GtkWidget 		*pHBox1;
	GtkWidget 		*pHBox2;
	GtkWidget 		*pHBox3;
	GtkWidget 		*pHBox4;
	GtkWidget 		*pHBox5;
	GtkWidget 		*pHBox6;
	GtkWidget 		*pHBox7;
	GtkWidget 		*pHBox8;
    GtkWidget 		*pButton[25];
	GtkWidget 		*pLabel1;
	GtkWidget 		*pLabel2;
	GtkWidget 		*pLabel3;
	GtkWidget 		*pLabel4;
	GtkWidget 		*pLabel5;
	GtkWidget 		*pLabel6;

	if (!(data = calloc(1, sizeof(t_data))))
	{
		printf("Probleme d'allocation mémoire, ton ordi est pourri.\n");
		return (1);
	}
	nombre_joueur = ft_joueur(data);
	printf("\nNombre de joueurs : %i\n", nombre_joueur);
	ft_carte(data);
	ft_equipe(data, nombre_joueur);
	//(void)env;
	ft_mail(data, env);
	sleep(3);
	printf("\nOuverture du jeu ...\n");
	sleep(5);


	//initialisation de gtk et création fenetre
    gtk_init(&argc,&argv);
    pWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    //Changer le titre de la fenetre et sa taille
	gtk_window_set_title(GTK_WINDOW(pWindow), "Code Names V1.0");
	gtk_window_set_default_size(GTK_WINDOW(pWindow), 700, 500);
	
	//Inserer des mot
	pLabel1 = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(pLabel1), "<span face=\"Comic Sans MS\"><b> <u>SCORE</u></b></span>");
	pLabel2 = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(pLabel2), "0");
	pLabel5 = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(pLabel5), "|");
	pLabel6 = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(pLabel6), "0");
	pLabel3 = ft_label_equipe(data, "Bleu", "#579E97");
	pLabel4 = ft_label_equipe(data, "Rouge", "#C13449");

	/* Création des GtkBox verticale */
    pVBox = gtk_vbox_new(TRUE, 0);
	pVBox1 = gtk_vbox_new(TRUE, 0);
	pVBox2 = gtk_vbox_new(TRUE, 0);
	pVBox3 = gtk_vbox_new(TRUE, 0);
	pVBox4 = gtk_vbox_new(TRUE, 0);
	pVBox5 = gtk_vbox_new(TRUE, 0);
	pVBox6 = gtk_vbox_new(TRUE, 0);
    /* Ajout de la GtkVBox dans la fenetre */
    gtk_container_add(GTK_CONTAINER(pWindow), pVBox);
 
    /* Creation des boutons aleatoires*/
    ft_jeu(data, pButton);
 
    /* Création des boxs horizontale */
    pHBox1 = gtk_hbox_new(TRUE, 0);
	pHBox2 = gtk_hbox_new(TRUE, 0);
	pHBox3 = gtk_hbox_new(TRUE, 0);
	pHBox4 = gtk_hbox_new(TRUE, 0);
	pHBox5 = gtk_hbox_new(TRUE, 0);
	pHBox6 = gtk_hbox_new(TRUE, 0);
	pHBox7 = gtk_hbox_new(TRUE, 0);
	pHBox8 = gtk_hbox_new(TRUE, 0);
	//pHBox7 = gtk_hbox_new(TRUE, 0);
 
    /* Ajout de la GtkHBox dans la GtkVBox */
    gtk_box_pack_start(GTK_BOX(pVBox), pHBox1, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(pVBox), pHBox2, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(pVBox), pHBox3, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(pVBox), pHBox4, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(pVBox), pHBox5, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(pVBox), pHBox6, TRUE, TRUE, 0);
	//gtk_box_pack_start(GTK_BOX(pVBox), pHBox7, TRUE, TRUE, 0);
 
    /* Ajout des boutons 1 2 3 4 5 dans la GtkHBox */
    for(int i = 0; i < 5; i++)
		gtk_box_pack_start(GTK_BOX(pHBox1), pButton[i], TRUE, TRUE, 0);
	for(int i = 5; i < 10; i++)
		gtk_box_pack_start(GTK_BOX(pHBox2), pButton[i], TRUE, TRUE, 0);
	for(int i = 10; i < 15; i++)
		gtk_box_pack_start(GTK_BOX(pHBox3), pButton[i], TRUE, TRUE, 0);
    for(int i = 15; i < 20; i++)
		gtk_box_pack_start(GTK_BOX(pHBox4), pButton[i], TRUE, TRUE, 0);
	for(int i = 20; i < 25; i++)
		gtk_box_pack_start(GTK_BOX(pHBox5), pButton[i], TRUE, TRUE, 0);
	//Ajout des deux labels dans la GtkHBox
	gtk_box_pack_start(GTK_BOX(pHBox6), pVBox1, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(pHBox6), pVBox2, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(pHBox6), pVBox3, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(pVBox1), pLabel3, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(pVBox3), pLabel4, TRUE, TRUE, 0);
	
	gtk_box_pack_start(GTK_BOX(pVBox2), pHBox7, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(pVBox2), pHBox8, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(pHBox7), pLabel1, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(pHBox8), pVBox4, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(pHBox8), pVBox5, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(pHBox8), pVBox6, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(pVBox4), pLabel2, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(pVBox5), pLabel5, TRUE, TRUE, 0);
	gtk_box_pack_start(GTK_BOX(pVBox6), pLabel6, TRUE, TRUE, 0);


	/* Connexion du signal "clique" */
	for (int i = 0; i < 25; i++)
	{
		if (carte[data->numero_cart][i] == 1)
		{
			gtk_signal_connect(GTK_OBJECT(pButton[i]), "clicked", GTK_SIGNAL_FUNC(ft_click_blue), pLabel2);
		}
		else if (carte[data->numero_cart][i] == 2)
			gtk_signal_connect(GTK_OBJECT(pButton[i]), "clicked", GTK_SIGNAL_FUNC(ft_click_red), pLabel6);
		else if (carte[data->numero_cart][i] == 3)
			gtk_signal_connect(GTK_OBJECT(pButton[i]), "clicked", GTK_SIGNAL_FUNC(ft_click_black), NULL);
		else
			gtk_signal_connect(GTK_OBJECT(pButton[i]), "clicked", GTK_SIGNAL_FUNC(ft_click_grey), NULL);
	}
	/* Connexion du signal "destroy" */
    g_signal_connect(G_OBJECT(pWindow), "destroy", G_CALLBACK(OnDestroy), NULL);
	/* Affichage de la fenêtre */
    gtk_widget_show_all(pWindow);
    /* Demarrage de la boucle evenementielle */
    gtk_main();
    
    return EXIT_SUCCESS;
}
