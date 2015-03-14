/*
** parse.c for parse in /home/durand_u/github/elcrypt
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Sat Mar 14 10:39:24 2015 Rémi DURAND
** Last update Sat Mar 14 12:41:44 2015 Rémi DURAND
*/

#include "elcrypt.h"

int		get_of(char **av, char *to_find)
{
  int		v;

  v = 0;
  while (v != 7 && strcmp(av[v], to_find) != 0)
    ++v;
  if (v == 7)
    return (-1);
  return (v);
}

void		get_primary(t_cry *crypt)
{
  int		v;
  char		tmp[8];

  v = 7;
  strcpy(tmp, crypt->fkey);
  while (v != -1)
    {
      tmp[v] >>= 1;
      --v;
    }
  v = 7;
  crypt->pkey = 0;
  while (v != -1)
    {
      crypt->pkey |= tmp[v];
      crypt->pkey <<= 7;
      --v;
    }
  crypt->pkey >>= 7;
  printf("%lx\n", crypt->pkey);
}

int		get_keys(t_cry *crypt, char **av)
{
  int		of;

  if ((of = get_of(av, "-k")) == 6 || strlen(av[of + 1]) != 8)
    return (-1);
  strcpy(crypt->fkey, av[of + 1]);
  get_primary(crypt);
  return (0);
}

int		get_fd(t_cry *crypt, char **av)
{
  int		sof;
  int		dof;

  if ((sof = get_of(av, "-f")) == 6 || (dof = get_of(av, "-o")) == 6)
    return (-1);
  crypt->sfd = open(av[sof + 1], O_RDWR);
  crypt->dfd = open(av[dof + 1], O_CREAT | O_RDWR, 0666);
  return (0);
}

int		parse_args(t_cry *crypt, char **av)
{
  if (get_keys(crypt, av) == (-1))
    return (-1);
  get_fd(crypt, av);
  if (get_of(av, "-e") != (-1))
    crypt->flag = 0;
  else if (get_of(av, "-d") != (-1))
    crypt->flag = 1;
  return (0);
}
