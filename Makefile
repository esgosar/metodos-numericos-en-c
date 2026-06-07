# ==========================================================================================
# AUTOMATED COMPILATION SYSTEM (MAKEFILE PRINCIPAL - RAIZ)
# ==========================================================================================
# TARGET: engine | ARCHITECTURE: Modular Central | COMPILER: GCC
# ==========================================================================================

CC       = gcc
CFLAGS   = -Wall -Wextra -O2
LIBS     = -lm

# Mapeo estricto de todos los modulos base de la arquitectura
CORE_SRC = core/aritmetica.c \
           errores/metricas.c \
           errores/excepciones.c \
           teoremas/validacion.c
#          metodos/solvers.c # (Descomenta esto cuando agregues los solvers)

# Convierte la lista de .c en .o
CORE_OBJ = $(CORE_SRC:.c=.o)

# 1. Regla por defecto: Si escribes solo 'make', compila el motor principal
.PHONY: all
all: engine

# 2. Regla para el motor principal (Test Bench)
engine: main.c $(CORE_OBJ)
	@echo "\n[LINKING]: Ensamblando arquitectura modular y generando binario central..."
	$(CC) $(CFLAGS) main.c $(CORE_OBJ) -o engine $(LIBS)
	@echo "================================================================================="
	@echo "[SUCCESS]: Sistema compilado exitosamente. Ejecuta el banco de pruebas con:"
	@echo "           ./engine"
	@echo "=================================================================================\n"

# 3. Regla para compilar los modulos base (.c a .o)
%.o: %.c
	@echo "[COMPILING]: Procesando modulo de hardware: $<"
	$(CC) $(CFLAGS) -c $< -o $@

# ==========================================================================================
# RUTINAS DE MANTENIMIENTO Y LIMPIEZA
# ==========================================================================================

# Limpieza Profunda: Borra el motor y los archivos de registro (.o)
.PHONY: clean
clean:
	@echo "[CLEANING]: Removiendo binario central (engine) y archivos objeto (.o)..."
	rm -f engine engine.exe $(CORE_OBJ)