#include "../includes/ft_ls.h"

void free_struct(t_content *content) {
  int i;

  i = 0;
  while (content->files[i]) {
    free(content->files[i]);
    free(content->owner[i]);
    free(content->group[i]);
    free(content->updated_at[i]);
    free(content->size[i]);
    i++;
  }
  free(content->files);
  free(content->is_dir);
  free(content->owner);
  free(content->group);
  free(content->updated_at);
  free(content->size);
  free(content->timestamps);
  free(content);

  i = 0;
}
