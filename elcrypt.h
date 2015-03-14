/*
** elcrypt.h for header in /home/durand_u/rendu/elcrypt
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Sat Mar 14 09:41:09 2015 Rémi DURAND
** Last update Sat Mar 14 12:34:56 2015 Rémi DURAND
*/

#ifndef _ELC_H_
# define _ELC_H_

# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_cry
{
  char		fkey[8];
  long int	pkey;
  int		sfd;
  int		dfd;
  int		flag;
}		t_cry;

int		parse_args(t_cry *crypt, char **av);

#endif /* !_ELC_H_ */
