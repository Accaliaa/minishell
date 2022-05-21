#include"minishell.h"



int	main(int argc, char **argv, char **env)
{
	if (!argv || !env)
		return(0);
	char *line;
	char *prompt = "\033[0;35mminishell:& \033[0;37m";
	while(1)
	{
		line = readline(prompt);
		if(!line)
			exit(0);
		if (line && *line)
    		add_history (line);
		handle_errors(line);
		//parse(line);
	}
}