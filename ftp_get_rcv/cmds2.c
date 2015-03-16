/*
** cmds2.c for smds2 in /home/durand_u/rendu/PSU_2014_myftp/server_dir
** 
** Made by Rémi DURAND
** Login   <durand_u@epitech.net>
** 
** Started on  Sat Mar 14 15:27:27 2015 Rémi DURAND
** Last update Mon Mar 16 16:01:02 2015 Rémi DURAND
*/

#include "server.h"

int	        cd(char **args, t_user *user, int cfd)
{
  if (!args[0] || args[1])
    send_msg(cfd, "xxx : Invalid argument number\n");
  else
    {
      if (strcmp(args[0], "..") == 0)
	cdup(&args[1], user, cfd);
      else
	cwd(args, user, cfd);
    }
  return (0);
}

int		get(char **args, t_user *user, int cfd)
{
  int		fd;
  char		*path;
  char		*msg;
  int		len;

  if (!args[0] || args[1] || !(path = make_path(args[0], user->wd, cfd)))
    {
      send_msg(cfd, "xxx : Invalid argument number\n");
      return (-1);
    }
  else if ((fd = open(path, O_RDONLY)) == (-1))
    {
      send_msg(cfd, "xxx : Failed to find file\n");
      return (-1);
    }
  newline_suppr(args[0]);
  if (!(msg = malloc(sizeof(char) * (8 * strlen(args[0])))))
    return (-1);
  sprintf(msg, "777 : %s\n", args[0]);
  send_msg(cfd, msg);
  read(cfd, msg, 1);
  ioctl(fd, FIONREAD, &len);
  sendfile(cfd, fd, NULL, len);
  free(msg);
  return (0);
}

int		write_file(int cfd, int fd)
{
  int		len;
  char		*file;

  while (!len && ioctl(cfd, FIONREAD, &len) >= 0)
    usleep(3000);
  if ((file = malloc(sizeof(char) * len)) == NULL)
    return (-1);
  read(cfd, file, len);
  if (strcmp(file, "xxx : fail") != 0)
    write(fd, file, len);
  free(file);
  return (0);
}

int	        put(char **args, t_user *user, int cfd)
{
  char		*path;
  char		*msg;
  int		fd;

  if (!args[0] || args[1] || !(path = make_path(args[0], user->wd, cfd)))
    {
      send_msg(cfd, "xxx : Invalid argument number\n");
      return (-1);
    }
  else if ((fd = open(path, O_CREAT | O_WRONLY, 0666)) == (-1))
    {
      send_msg(cfd, "xxx : Failed to open file\n");
      return (-1);
    }
  newline_suppr(args[0]);
  if (!(msg = malloc(sizeof(char) * (8 * strlen(args[0])))))
    return (-1);
  sprintf(msg, "778 : %s\n", args[0]);
  send_msg(cfd, msg);
  write_file(cfd, fd);
  free(msg);
  return (0);
}
