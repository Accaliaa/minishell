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
	int i;

	i = 0;
	while(s[i])
	{
		if(s[i] == '"' || s[i] == 39)
		{
			if(ft_cmp(s, s[i]) == 2)
					break;
			else
				return(0);
		}
		i++;
	}
	return(1);
}

int handle_characters(char *s, int i)
{
	while(s[i])
	{
		if(s[i] == ';' || s[i] == 92)
			return(0);
		i++;
	}
	return(1);
}


int handle_error(int *i, int *j, char *argv)
{
	int error;

	error = 0;
	char c1 = '>';
	char c2 = '<';
	while(argv[*i] == c1 || argv[*i] == c2)
	{
		*i += 1;
		*j += 1;
		if(argv[*i] == c1 && argv[*i + 1 == c2])
			error = 1;
	}
	if(argv[*i] == '\0')
		error = 1;
	return(error);
}

int handle_redirections(char *argv, int i)
{
	int count;

	count = 0;
	while(argv[i])
	{
		if(argv[i] == '>')
		{
			if( handle_error(&i, &count, argv) || count > 2)
				return(0);
		}
		count = 0;
		if(argv[i] == '<')
		{
			if( handle_error(&i, &count, argv) || count > 2)
				return(0);
		}
		else
			i++;
	}
	return(1);
}

char	quotes_exit(char *argv)
{
	int	i;

	i = 0;
	while(argv[i] == '"' || argv[i] == 39)
		return(argv[i]);
	return(0);
}

int	handle_errors(char *argv)
{
	int i;

	i = 0;
	if(quotes_exit(argv) != 0)
	{	if(!handle_quotes(argv))
		{
			write(1, "Error\n", 24);
			return(0);
		}
		i++;
		while(argv[i] != quotes_exit(argv))
			i++;
	}
	
	if(i == ft_strlen(argv)|| !handle_characters(argv, i) || \
	!handle_redirections(argv, i))
	{
		write(1, "Error\n", 24);
		return(0);
	}
	return(1);
}
