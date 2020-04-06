#include "code_name.h"

GtkWidget       *ft_label_equipe(t_data *data, char *str_couleur, char *fg)
{
	char	    *str;
    GtkWidget	*pLabel;
	
    str = strdup("<span font_desc=\"Comic Sans MS normal 10\" foreground=\"");
    str = ft_strjoin(str, fg);
    str = ft_strjoin(str, "\">Equipe ");
    str = ft_strjoin(str, str_couleur);
    str = ft_strjoin(str, "\n");
    pLabel = gtk_label_new(NULL);
    if ((strcmp(str_couleur, "Bleu")) == 0)
    {
        for (int i = 0; data->eq1[i].name; i++)
	    {
		    str = ft_strjoin(str, data->eq1[i].name);
		    str = ft_strjoin(str, "\n");
	    }
    }
    else
    {
        for (int i = 0; data->eq2[i].name; i++)
	    {
		    str = ft_strjoin(str, data->eq2[i].name);
		    str = ft_strjoin(str, "\n");
	    }
    }
	str = ft_strjoin(str, "</span>");
	gtk_label_set_markup(GTK_LABEL(pLabel), str);
    return (pLabel);
}