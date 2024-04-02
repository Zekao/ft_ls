NAME = ft_ls

SRCS := main.c \
        utils.c \
        parsing.c \
        exec.c \
        clear.c \
        recursive.c \
        print.c \
        sort.c \
        debug.c \

SRCS := $(addprefix srcs/, $(SRCS))

OBJS = $(patsubst srcs/%.c,objs/%.o,$(SRCS))
DEPS := $(patsubst srcs/%.c,deps/%.d,$(SRCS))

CXX := cc
CXXFLAGS := -Wall -Werror -Wextra -MMD -g


COLORS := $(shell seq 31 37)

all: create_dirs $(NAME)

create_dirs:
	@if [ ! -d "objs" ]; then mkdir objs; fi
	@if [ ! -d "deps" ]; then mkdir deps; fi

objs/%.o: srcs/%.c
	@COLOR_CODE=$$(echo "$(COLORS)" | awk '{srand(); print int(rand()*7)}'); \
	printf "\033[1;%sm\t\tCompiling: $<\033[0m\r" $$((30+COLOR_CODE)); \
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@; \
	mv objs/*.d deps/

clean:
	@if [ -d "objs" ]; then rm -rf objs; fi
	@if [ -d "deps" ]; then rm -rf deps; fi

fclean: clean
	@rm -rf $(NAME)

re: fclean
	@$(MAKE) all

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

-include $(DEPS)

.PHONY: all clean fclean re create_dirs
