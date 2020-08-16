NAME = cub3d

HEAD = cub3d.h

INCLUDES = ./

COMP_FLAGS = #-Wall -Wextra -Werror

PARSER_SRCS = error_handler.c get_next_line.c \
			  get_next_line_utils.c init_parsing.c texture_parse.c \
			  atoi_str.c

SRCS = 

PARSER_DIR = parser/

LIBFT_DIR = libft/

LIBFT_SRCS = ft_strchr.c ft_atoi.c ft_isdigit.c \
	     ft_calloc.c ft_strdup.c ft_substr.c \
	     ft_strlcpy.c ft_memset.c ft_putstr.c \
	     ft_putchar.c 

OBJS = $(PARSER_FILES:.c=.o) $(LIBFT_FILES:.c=.o)

PARSER_FILES = $(addprefix $(PARSER_DIR), $(PARSER_SRCS))

LIBFT_FILES = $(addprefix $(LIBFT_DIR), $(LIBFT_SRCS))

ALL_FILES = $(PARSER_FILES) $(LIBFT_FILES)

all: $(NAME)

$(NAME): $(OBJS)
	gcc -o $@ $^

#all: $(NAME)

#$(NAME): $(OBJS)
	#@ar rc $(NAME) $(OBJS)
	#@ranlib $(NAME)
	#@echo "libftprintf.a has been created"

clean:
	rm -f $(OBJS)
	#@echo "all .o files has been deleted"

#fclean: clean
	#@rm -f $(NAME)
	#@echo "libftprintf.a has been deleted"

re: fclean all

%.o: %.c
	gcc -c $(COMP_FLAGS) -o $@ $<


.PHONY: all clean fclean re

#NAME = main.c

#all:
	#gcc -I ./mlx/. $(NAME) -L ./mlx/. -lmlx -framework OpenGL -framework AppKit
