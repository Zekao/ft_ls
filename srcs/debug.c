#include "../includes/ft_ls.h"

void print_options(t_options opts) {
  ft_putstr("LIST: ");
  ft_putendl(opts.flags[LIST] ? "true" : "false");
  ft_putstr("ALL: ");
  ft_putendl(opts.flags[ALL] ? "true" : "false");
  ft_putstr("RECURSIVE: ");
  ft_putendl(opts.flags[RECURSIVE] ? "true" : "false");
  ft_putstr("REVERSE: ");
  ft_putendl(opts.flags[REVERSE] ? "true" : "false");
  ft_putstr("TIME: ");
  ft_putendl(opts.flags[TIME] ? "true" : "false");
}
