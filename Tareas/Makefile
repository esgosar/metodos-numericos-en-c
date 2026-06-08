# ==========================================================================================
# AUTOMATED COMPILATION SYSTEM (UBICADO EN CARPETA 'Tareas')
# ==========================================================================================

CC       = gcc
CFLAGS   = -Wall -Wextra -O2
LIBS     = -lm

# AHORA INCLUIMOS EL SOLVER DE BISECCION AL MOTOR
CORE_SRC = ../core/aritmetica.c \
           ../errores/excepciones.c \
           ../errores/metricas.c \
           ../teoremas/validacion.c \
           ../metodos/solvers.c

CORE_OBJ = $(CORE_SRC:.c=.o)

# Busca todos los archivos que empiecen con un numero (1.c, 11.c, etc.)
PROB_SRC = $(wildcard [0-9]*.c)
PROB_EXE = $(PROB_SRC:.c=)

# ==========================================================================================
# REGLAS DE COMPILACION ESTRICTAS
# ==========================================================================================

# 1. Regla para compilar los modulos base (.c a .o)
%.o: %.c
	@echo "[COMPILING]: Procesando modulo de hardware: $<"
	$(CC) $(CFLAGS) -c $< -o $@

# 2. REGLA ESTRICTA PARA LAS TAREAS (Anula la regla por defecto de Make)
$(PROB_EXE): %: %.c $(CORE_OBJ)
	@echo "[BUILDING]: Compilando tarea: $<"
	$(CC) $(CFLAGS) $< $(CORE_OBJ) -o $@ $(LIBS)

# ==========================================================================================
# BATCH PROCESSING & CLEANING
# ==========================================================================================

.PHONY: tareas test_all clean_exe clean

tareas: $(PROB_EXE)
	@echo "[BATCH BUILD]: Todas las tareas fueron compiladas exitosamente."

test_all: $(PROB_EXE)
	@echo "[BATCH TEST]: Iniciando ejecucion en cadena..."
	@for script in $(PROB_EXE); do \
		echo "\n================================================================================="; \
		echo " >> EJECUTANDO: $$script"; \
		echo "================================================================================="; \
		./$$script; \
	done

clean_exe:
	@echo "[CLEANING]: Removiendo binarios de tareas..."
	rm -f $(PROB_EXE) $(PROB_EXE:=.exe)

clean: clean_exe
	@echo "[CLEANING]: Removiendo archivos objeto del motor (.o)..."
	rm -f $(CORE_OBJ)