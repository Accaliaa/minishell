/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdasser <zdasser@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 16:29:17 by zdasser           #+#    #+#             */
/*   Updated: 2022/06/07 18:22:49 by zdasser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"minishell.h"
#include<unistd.h>

int	*sttc_var(void)
{
	static int i;

	return (&i);
}

void set_sttc(int i)
{
	int *p;

	p = (sttc_var());
	*p = i;
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t i;
	
	i = 0;
	if(ft_strlen(s1) != ft_strlen(s2))
		return(0);
	while (s1[i] != '\0' && s2[i] != '\0' && s2[i] == s1[i])
		i++;
	if (i < ft_strlen(s1))
		return (0);
	return (1);
}

void	get_path(char **env, t_pipe *p)
{
	int	i;

	i = 0;
	while (env[i] != NULL)
	{
		if (!ft_strncmp(env[i], "PATH", 4))
			break ;
		i++;
	}
	if (env[i] == NULL)
		exit (write(2, "error path\n", 6));
	p->splitpaths = ft_split(&env[i][5], ':');
	if (!p->splitpaths)
		exit (write(2, "error\n", 6));
}

// void get_args(int *se, t_pipe *p, char **s)
// {
// 	int	i;
// 	int j;

// 	j = 0;
// 	i = se[0];
// 	p->args_hold = (char **)malloc(sizeof(char *) * (se[1] - se[0] + 1));
// 	while(i <= se[1] && !ft_cmp(s[j], '<'))
// 	{
// 		p->args_hold[j] = s[i];
// 		i++;
// 		j++;
// 	}
// }


// void get_start_end(t_pipe *p, char **s)
// {
// 	int i;
// 	int	j;
// 	int se[2];

// 	j = 0;
// 	i = 0;
// 	while (s[i] && ft_cmp(s[i], '<'))
// 	{
// 		if (ft_cmp(s[i], '<') && ft_strlen(s[i]) == 1)
// 	  		i++;
// 	 	i++;
// 	}
// 	j = i;
// 	while (s[j] && !ft_cmp(s[j], '>') && !ft_cmp(s[j], '<'))
// 	 	j++;
	
// 	se[0] = i;
// 	se[1] = j;
// 	get_args(se, p, s);
// }

void ft_exec (t_list *l, char **env)
{
   int fd [2];
   t_pipe p;
   int i = 0;
   int j = 0;
   char *tmp;
   char *cmd;
   int n = ft_lstsize(l);
   int in = 0;
   int	node = 0;
   int ev = 0;
   get_path(env, &p);
  if(check_dollar(l))
	return;
  else
  {
	  while(l)
	{
		pipe(fd);
		i = 0;
		if(fork() == 0)
		{
			// if(((t_all *)l->content)->hd >= 1 && j == 0)
			// {
			// 	dup2(((t_all *)l->content)->fd, 0);
			// 	close (fd[1]);
			// 	close (fd[0]);
			// }
			if(n == 1)
			{
				dup2(((t_all *)l->content)->inf[0], 0);
				close (fd[1]);
				close (fd[0]);
			}
			else if(j == 0 && n > 1)
			{
				dup2(((t_all *)l->content)->inf[0], 0);
				dup2(fd[1], 1);
				close (fd[1]);
				close (fd[0]);
			}
			if(j < n - 1)
			{
				dup2(in, 0);
				dup2(fd[1], 1);
				close (fd[1]);     
				close (fd[0]);
			}
			else
			{
				dup2(in, 0);
				dup2(((t_all *)l->content)->outf[0], 1);
				close (fd[1]);
				close (fd[0]);
			}
		 	while (p.splitpaths[i])
		 	{
		 		tmp = ft_strjoin(p.splitpaths[i], "/");
				if( j == 0)
					cmd = ft_strjoin(tmp, ((t_all *)l->content)->cmd[node]);
				else
					cmd = ft_strjoin(tmp, ((t_all *)l->content)->cmd[0]);
		 		free(tmp);
		 		//if (access(cmd, F_OK) == 0)
				//{
					fprintf(stdout, "....%i...%s\n", access(cmd, X_OK), cmd );
					if (access(cmd, X_OK) == 0)
		 				execve(cmd,((t_all *)l->content)->cmd, env);
					else
						exit(126);
				//}
				//else
					//exit(127);
		 		i++;
		 	}
			printf("command not found \n");
			//exit(1);
		}
		in = dup(fd[0]);
		close (fd[1]);
		close (fd[0]);
		l = l->next;
		j++;
		node++;
	}
	i = 0;
	while(i < n)
	{
		wait(&ev);
		i++;
	}
	
	if(WIFEXITED(ev))
	{
		set_sttc(WEXITSTATUS(ev));
	}
	printf("\n");
	}
}