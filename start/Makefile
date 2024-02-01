CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCDIR = sources
OBJDIR = objects
LIBFTDIR = libft
LIBFT = $(LIBFTDIR)/libft.a
PROGRAM = so_long

SRCS = $(SRCDIR)/example0.c \
	$(SRCDIR)/example1.c \
	$(SRCDIR)/example2.c \
	$(SRCDIR)/example3.c \
	$(SRCDIR)/example4.c \
	$(SRCDIR)/example5.c \
	$(SRCDIR)/example6.c \
	$(SRCDIR)/example7.c \
	$(SRCDIR)/example8.c \
	$(SRCDIR)/example9.c

OBJS = $(OBJDIR)/example0.o \
    $(OBJDIR)/example1.o \
    $(OBJDIR)/example2.o \
    $(OBJDIR)/example3.o \
    $(OBJDIR)/example4.o \
    $(OBJDIR)/example5.o \
    $(OBJDIR)/example6.o \
    $(OBJDIR)/example7.o \
    $(OBJDIR)/example8.o \
    $(OBJDIR)/example9.o

all: $(PROGRAM)

$(PROGRAM): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C $(LIBFTDIR)

clean:
	$(RM) -rf $(OBJDIR)
	$(MAKE) -C $(LIBFTDIR) clean

fclean: clean
	$(RM) $(PROGRAM)
	$(MAKE) -C $(LIBFTDIR) fclean

re: fclean all

.PHONY: all clean fclean re
