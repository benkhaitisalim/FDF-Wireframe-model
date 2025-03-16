CC = gcc
CFLAGS = -Wall -Wextra -Werror 

LIBFT_DIR = libft
GET_NEXT_LINE_DIR = get_next_line
LIBFT_SRC_DIR = $(LIBFT_DIR)/src
LIBFT_INC_DIR = $(LIBFT_DIR)/include
GET_NEXT_LINE_SRC_DIR = $(GET_NEXT_LINE_DIR)
GET_NEXT_LINE_INC_DIR = $(GET_NEXT_LINE_DIR)
FDF_SRC_DIR = src
FLAG_MLX =  /Users/bsalim/MLX/build/libmlx42.a  /Users/bsalim/MLX/build/libglfw3.a -Iinclude -lm -framework Cocoa -framework OpenGL -framework IOKit 
LIBFT_A = $(LIBFT_DIR)/libft.a
GET_NEXT_LINE_O = $(GET_NEXT_LINE_SRC_DIR)/get_next_line.c $(GET_NEXT_LINE_SRC_DIR)/get_next_line_utils.c
INCLUDE_FDF = fdf.h
LIBFT_OBJS = $(LIBFT_SRC_DIR)/ft_isalpha.o $(LIBFT_SRC_DIR)/ft_isdigit.o $(LIBFT_SRC_DIR)/ft_isalnum.o \
             $(LIBFT_SRC_DIR)/ft_isascii.o $(LIBFT_SRC_DIR)/ft_substr.o $(LIBFT_SRC_DIR)/ft_strjoin.o \
             $(LIBFT_SRC_DIR)/ft_strtrim.o $(LIBFT_SRC_DIR)/ft_split.o $(LIBFT_SRC_DIR)/ft_isprint.o \
             $(LIBFT_SRC_DIR)/ft_strlen.o $(LIBFT_SRC_DIR)/ft_memset.o $(LIBFT_SRC_DIR)/ft_bzero.o \
             $(LIBFT_SRC_DIR)/ft_memcpy.o $(LIBFT_SRC_DIR)/ft_memmove.o $(LIBFT_SRC_DIR)/ft_putendl_fd.o \
             $(LIBFT_SRC_DIR)/ft_putnbr_fd.o $(LIBFT_SRC_DIR)/ft_strlcpy.o $(LIBFT_SRC_DIR)/ft_strlcat.o \
             $(LIBFT_SRC_DIR)/ft_toupper.o $(LIBFT_SRC_DIR)/ft_tolower.o $(LIBFT_SRC_DIR)/ft_strchr.o \
             $(LIBFT_SRC_DIR)/ft_strrchr.o $(LIBFT_SRC_DIR)/ft_putchar_fd.o $(LIBFT_SRC_DIR)/ft_putstr_fd.o \
             $(LIBFT_SRC_DIR)/ft_strncmp.o $(LIBFT_SRC_DIR)/ft_memchr.o $(LIBFT_SRC_DIR)/ft_memcmp.o \
             $(LIBFT_SRC_DIR)/ft_strnstr.o $(LIBFT_SRC_DIR)/ft_atoi.o $(LIBFT_SRC_DIR)/ft_calloc.o \
             $(LIBFT_SRC_DIR)/ft_strdup.o $(LIBFT_SRC_DIR)/ft_strmapi.o $(LIBFT_SRC_DIR)/ft_striteri.o \
             $(LIBFT_SRC_DIR)/ft_itoa.o

FDF_SRCS = print_map.c dda_algo.c read_map.c isometric.c free_ram.c main.c scale.c key_exit.c fdf_utlis.c alloc_map.c
FDF_OBJS = $(FDF_SRCS:.c=.o)

NAME = fdf

all: $(NAME)

$(NAME): $(FDF_OBJS) $(LIBFT_A) $(GET_NEXT_LINE_O)
	$(CC) $(FLAG_MLX) $(FDF_OBJS) $(LIBFT_A) $(GET_NEXT_LINE_O) -o $(NAME)

$(LIBFT_A):
	make -C $(LIBFT_DIR)

$(GET_NEXT_LINE_SRC_DIR)/%.o: $(GET_NEXT_LINE_SRC_DIR)/%.c $(GET_NEXT_LINE_INC_DIR)/get_next_line.h
	$(CC) $(FLAG_MLX) $(CFLAGS) -I$(GET_NEXT_LINE_INC_DIR) -I$(LIBFT_INC_DIR) -c $< -o $@

$(FDF_SRC_DIR)/%.o: $(FDF_SRC_DIR)/%.c $(LIBFT_INC_DIR)/libft.h $(GET_NEXT_LINE_INC_DIR)/get_next_line.h
	$(CC) $(CFLAGS) -I$(LIBFT_INC_DIR) -I$(GET_NEXT_LINE_INC_DIR) -I$(FDF_SRC_DIR) -c $< -o $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(GET_NEXT_LINE_SRC_DIR)/*.o
	rm -f $(FDF_OBJS)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all
