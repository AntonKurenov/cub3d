NAME = cub3D

HEAD = cub3d.h

INCLUDES = ./

COMP_FLAGS = #-Wall -Wextra -Werror

PARSER_SRCS = error_handler.c get_next_line.c \
			  get_next_line_utils.c init_parsing.c texture_parser.c \
			  atoi_str.c map_parser.c map_checker.c map_preparation.c \
			  structures_init.c

ENGINE_SRCS = init_engine.c structs_for_engine.c \
			  check_horizontal.c init_texture.c \
			  check_vertical.c movements.c convert_and_reset.c \
			  math.c textr_work.c get_colour.c draw_ceil_and_floor.c \
			  check_map.c sprt_work.c init_sprites.c aux_sprt_funct.c \
			  get_flags.c draw_sprites.c

SRCS = 

ENGINE_DIR = engine/

PARSER_DIR = parser/

LIBFT_DIR = libft/

LIBFT_SRCS = ft_strchr.c ft_atoi.c ft_isdigit.c \
	     ft_calloc.c ft_strdup.c ft_substr.c \
	     ft_strlcpy.c ft_memset.c ft_putstr.c \
	     ft_putchar.c ft_split.c ft_strncmp.c ft_strjoin.c

OBJS = $(PARSER_FILES:.c=.o) $(LIBFT_FILES:.c=.o) $(ENGINE_FILES:.c=.o)

ENGINE_FILES = $(addprefix $(ENGINE_DIR), $(ENGINE_SRCS))

PARSER_FILES = $(addprefix $(PARSER_DIR), $(PARSER_SRCS))

LIBFT_FILES = $(addprefix $(LIBFT_DIR), $(LIBFT_SRCS))

ALL_FILES = $(PARSER_FILES) $(LIBFT_FILES)

all: $(NAME)

$(NAME): $(OBJS)
	gcc -g -o $@ $^ ./minilibx/libmlx.a -framework OpenGL -framework Appkit -lm

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o: %.c
	gcc -g -c $(COMP_FLAGS) -o $@ $< 

.PHONY: all clean fclean re
