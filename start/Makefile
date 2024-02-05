CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = sources
OBJDIR = objects
LIBFTDIR = libft
MLXDIR = MLX42
MLX42 = $(MLXDIR)/build/libmlx42.a
LIBFT = $(LIBFTDIR)/libft.a
PROGRAM = so_long

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

OBJS = $(OBJDIR)/data_initialization.o \
    $(OBJDIR)/error_handler.o \
    $(OBJDIR)/ft_double_strdup.o \
    $(OBJDIR)/ft_free_substrings.o \
    $(OBJDIR)/get_next_line_utils.o \
    $(OBJDIR)/map_handler.o \
    $(OBJDIR)/get_next_line.o \
    $(OBJDIR)/map_success_check.o \
    $(OBJDIR)/map_validity_utils.o \
    $(OBJDIR)/map_validity.o \
	$(OBJDIR)/so_long_utils.o \
	$(OBJDIR)/so_long.o \
	$(OBJDIR)/movement_control.o

all: $(PROGRAM)

$(PROGRAM): $(OBJS) $(LIBFT) $(MLX42)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBFT) $(MLX42) -Iinclude -lglfw -L"/Users/$(USER)/.brew/opt/glfw/lib/"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(MLX42):
	cmake $(MLXDIR) -B $(MLXDIR)/build && make -C $(MLXDIR)/build -j4

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	rm -rf $(OBJDIR)
	make -C $(LIBFTDIR) clean
	rm -rf $(LIBMLX)/build

fclean: clean
	rm $(PROGRAM)
	make -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
