#include "../includes/ft_ls.h"

void free_struct(t_content *content) {
  int i;

  i = 0;
  while (content->files[i]) {
    free(content->files[i]);
    i++;
  }
  free(content->files);
  free(content->is_dir);
  free(content);

  i = 0;
}
