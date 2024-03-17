#include "../includes/ft_ls.h"

int ft_ls_recursive(char **argv, t_options options) {
  DIR *dir;
  struct dirent *dp;
  char *tmp;
  char *path;

  dir = opendir(argv[0]);
  if (!dir)
    return perror("opendir"), 1;

  ft_putstr(argv[0]);
  ft_putstr(":\n");
  while ((dp = readdir(dir)) != NULL) {

    tmp = ft_strjoin(argv[0], "/");
    if (!tmp)
      return 1;
    path = ft_strjoin(tmp, dp->d_name);
    if (!path)
      return (free(tmp), 1);
    free(tmp);

    if (dp->d_name[0] == '.' && options.flags[ALL] == false) {
      free(path);
      continue;
    }
    ft_putendt(dp->d_name);

    if (dp->d_type == DT_DIR && options.flags[RECURSIVE]) {
      if (ft_strcmp(dp->d_name, ".") == 0 || ft_strcmp(dp->d_name, "..") == 0) {
        free(path);
        continue;
      }
      char *new_argv[2];
      new_argv[0] = path;
      new_argv[1] = NULL;
      ft_ls_recursive(new_argv, options);
    }
    free(path);
  }
  return ft_putchar('\n'), closedir(dir), 0;
}
