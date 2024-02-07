CC = cc
CFLAGS = -Wall -Wextra -Werror
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

LIBFT_SRC = $(LIBFTDIR)/ft_atoi.c \
		$(LIBFTDIR)/ft_bzero.c \
		$(LIBFTDIR)/ft_calloc.c \
		$(LIBFTDIR)/ft_isalnum.c \
		$(LIBFTDIR)/ft_isalpha.c \
		$(LIBFTDIR)/ft_isascii.c \
		$(LIBFTDIR)/ft_isdigit.c \
		$(LIBFTDIR)/ft_isprint.c \
		$(LIBFTDIR)/ft_memchr.c \
		$(LIBFTDIR)/ft_memcmp.c \
		$(LIBFTDIR)/ft_memcpy.c \
		$(LIBFTDIR)/ft_memset.c \
		$(LIBFTDIR)/ft_strchr.c \
		$(LIBFTDIR)/ft_strdup.c \
		$(LIBFTDIR)/ft_strlcat.c \
		$(LIBFTDIR)/ft_strlcpy.c \
		$(LIBFTDIR)/ft_strlen.c \
		$(LIBFTDIR)/ft_strncmp.c \
		$(LIBFTDIR)/ft_strnstr.c \
		$(LIBFTDIR)/ft_strrchr.c \
		$(LIBFTDIR)/ft_tolower.c \
		$(LIBFTDIR)/ft_toupper.c \
		$(LIBFTDIR)/ft_memmove.c \
		$(LIBFTDIR)/ft_substr.c \
		$(LIBFTDIR)/ft_strjoin.c \
		$(LIBFTDIR)/ft_strtrim.c \
		$(LIBFTDIR)/ft_split.c \
		$(LIBFTDIR)/ft_itoa.c \
		$(LIBFTDIR)/ft_strmapi.c \
		$(LIBFTDIR)/ft_striteri.c \
		$(LIBFTDIR)/ft_putchar_fd.c \
		$(LIBFTDIR)/ft_putstr_fd.c \
		$(LIBFTDIR)/ft_putendl_fd.c \
		$(LIBFTDIR)/ft_putnbr_fd.c \
		$(LIBFTDIR)/ft_strcmp.c \
		$(LIBFTDIR)/ft_strndup.c \
		$(LIBFTDIR)/ft_printf.c \
		$(LIBFTDIR)/ft_ptrhex.c \
		$(LIBFTDIR)/ft_put_unsigned_nbr.c \
		$(LIBFTDIR)/ft_putchar.c \
		$(LIBFTDIR)/ft_puthex.c \
		$(LIBFTDIR)/ft_putnbr.c \
		$(LIBFTDIR)/ft_putstr.c \
		$(LIBFTDIR)/ft_printf.c


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

$(LIBFT): $(LIBFT_SRC)
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