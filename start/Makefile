CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g
SRCDIR = sources
OBJDIR = objects
LIBFTDIR = libft
MLXDIR = MLX42
MLX42 = $(MLXDIR)/build/libmlx42.a
LIBFT = $(LIBFTDIR)/libft.a
PROGRAM = so_long
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S),Linux)
LDFLAGS = -Iinclude -ldl -lglfw -pthread -lm
endif
ifeq ($(UNAME_S),Darwin)
LDFLAGS = -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"
endif

SRCS = $(SRCDIR)/data_initialization.c \
	$(SRCDIR)/error_handler.c \
	$(SRCDIR)/ft_double_strdup.c \
	$(SRCDIR)/ft_free_substrings.c \
	$(SRCDIR)/get_next_line_utils.c \
	$(SRCDIR)/map_handler.c \
	$(SRCDIR)/map_success_check.c \
	$(SRCDIR)/map_validity_utils.c \
	$(SRCDIR)/map_validity.c \
	$(SRCDIR)/so_long_utils.c \
	$(SRCDIR)/so_long.c \
	$(SRCDIR)/get_next_line.c \
	$(SRCDIR)/movement_control.c
OBJS = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

all: $(PROGRAM)

$(PROGRAM): $(OBJS) $(LIBFT) $(MLX42)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(MLX42) $(LDFLAGS)

check_flags:
	@echo $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c -o $@ $<

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(MLX42):
	cmake $(MLXDIR) -B $(MLXDIR)/build && make -C $(MLXDIR)/build -j4

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	rm -rf $(OBJDIR)
	make -C $(LIBFTDIR) clean
	rm -rf $(MLXDIR)/build

fclean: clean
	rm -rf $(PROGRAM)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re check_flags