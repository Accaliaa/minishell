#include"minishell.h"

int	ft_cmp(char *s, char c)
{
	int count;
	int	i;

	i = 0;
	count = 0;
	while(s[i])
	{
		if(s[i] == c)
			count++;
		i++; 
	}
	return(count);
}

int	ft_opp_cmp(char *s, int i, char c)
{
	int count;
	char c1;
	char c2;

	count = 0;
	c1 = '"';
	c2 = 39;
	while(s[i])
	{
		if(c == c1 && s[i] == c2)
			return(1);
		else if(c == c2 && s[i] == c1)
			return(1);
		i++; 
	}
	return(0);
}
int	handle_quotes(char *s)
{	
	int count;
	int check;
	int i;

	i = 0;
	while(s[i])
	{
		if(s[i] == '"' || s[i] == 39)
		{
			if(ft_cmp(s, s[i]) == 2)
			{	if(!ft_opp_cmp(s, ft_cmp(s, s[i]), s[i]))
					break;
			}
			else
				return(0);
		}
		i++;
	}
	return(1);
}

int handle_characters(char *s)
{
	int	i;

	i = 0;
	while(s[i])
	{
		if(s[i] == ';' || s[i] == 92)
			return(0);
		i++;
	}
	return(1);
}




int check_error(char *argv, int i, char c)
{
	int	count;

	count = 0;
	while(argv[i])
	{
		
	}
	return(i);
}

void handle_error(int *i, int *j, char *argv, char c)
{
	while(argv[*i] == c)
	{
		*i += 1;
		*j += 1;
	}
}

int handle_redirections(char *argv)
{
	int	i;
	int count;

	count = 0;
	i = 0;
	while(argv[i])
	{
		if(argv[i] == '>')
			handle_error(&i, &count, argv, '>');
		if(count > 2)
			return(0);
		count = 0;
		if(argv[i] == '<')
			handle_error(&i, &count, argv, '<');
		if(count > 2)
			return(0);
		else
			i++;
	}
	return(1);
}

int	handle_errors(char *argv)
{
	
	if(!handle_quotes(argv) || !handle_characters(argv) || !handle_redirections(argv))
	{
		write(1, "Error\n", 24);
		return(0);
	}
	return(1);
}
