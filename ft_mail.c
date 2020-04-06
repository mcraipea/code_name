#include "code_name.h"

void    ft_mail(t_data *data, char **env)
{
    int			rep1;
	int			rep2;
	char		*str;
	char		*arg[5];
	pid_t		child_pid;
	pid_t 		tpid;
	int			child_status;

    str = strdup("./carte/carte_codenames_");
	str = ft_strjoin(str, data->numero_carte);
	str = ft_strjoin(str, ".jpeg");
	printf("Qui veut faire deviner dans l'equipe Bleu? (Donner le chiffre a coté du nom) : ");
    scanf("%i", &rep1);
	printf("Qui veut faire deviner dans l'equipe Rouge? (Donner le chiffre a coté du nom) : ");
	scanf("%i", &rep2);
	arg[0] = strdup("./script_mail.sh");
	arg[1] = strdup(data->eq1[rep1 - 1].mail);
	arg[2] = strdup(data->eq2[rep2 - 1].mail);
	arg[3] = strdup(str);
	arg[4] = NULL;
	child_pid = fork();
	if(child_pid == 0)
	{
    	execve("./script_mail.sh", arg, env);
    	printf("Unknown command\n");
   		exit(0);
	}
  	else
	{
		tpid = wait(&child_status);
    	while(tpid != child_pid)
		{
       		tpid = wait(&child_status);
       		if(tpid != child_pid)
			   break ;
     	}
  	}
	printf("\nPour les deux qui font deviner, vous avez reçu un mail avec la carte.\n");
}
