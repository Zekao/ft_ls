#include "../includes/ft_ls.h"

void print_options(t_options opts) {
  printf("LIST: %d\n", opts.flags[LIST]);
  printf("ALL: %d\n", opts.flags[ALL]);
  printf("RECURSIVE: %d\n", opts.flags[RECURSIVE]);
  printf("REVERSE: %d\n", opts.flags[REVERSE]);
  printf("TIME: %d\n", opts.flags[TIME]);
}
