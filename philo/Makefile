# Nombre del programa
NAME = philo

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread

# Directorios
SRC_DIR = src
UTILS_DIR = utils
INCLUDE_DIR = include

# Archivos fuente
SRC_FILES = $(SRC_DIR)/main.c $(SRC_DIR)/init.c $(SRC_DIR)/philo.c $(SRC_DIR)/monitor.c
UTILS_FILES = $(UTILS_DIR)/utils.c $(UTILS_DIR)/ft_atoi.c $(UTILS_DIR)/cleanup.c $(UTILS_DIR)/run_check.c

# Objetos
OBJ_FILES = $(SRC_FILES:.c=.o) $(UTILS_FILES:.c=.o)

# Regla principal
all: $(NAME)

# Compilación del ejecutable
$(NAME): $(OBJ_FILES)
	$(CC) $(CFLAGS) $(OBJ_FILES) -o $(NAME)

# Compilar archivos .c en .o
%.o: %.c
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Limpiar archivos compilados
clean:
	rm -f $(OBJ_FILES)

# Limpiar todo incluyendo el ejecutable
fclean: clean
	rm -f $(NAME)

# Recompilar desde cero
re: fclean all

# Evitar errores si se usa como nombre de archivo en reglas
.PHONY: all clean fclean re
