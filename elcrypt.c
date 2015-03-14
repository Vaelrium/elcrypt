/*
** elcrypt.c for elcrypt in /home/durand_u/rendu/elcrypt
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Sat Mar 14 09:40:22 2015 Rémi DURAND
** Last update Sat Mar 14 12:38:32 2015 Rémi DURAND
*/

#include "elcrypt.h"

int		main(int ac, char **av)
{
  t_cry		crypt;

  if (ac != 8 || parse_args(&crypt, &av[1]) == (-1))
    return (-1);
  close(crypt.dfd);
  close(crypt.sfd);
  return (0);
}
