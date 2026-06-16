import os
import shutil

# 1. Crear una carpeta temporal segura
carpeta_destino = "archivos_renombrados"
os.makedirs(carpeta_destino, exist_ok=True)

# 2. Procesar todos los archivos posibles (ahora incluimos hasta el 24)
for i in range(25):
    nombre_actual = f"{i:02d}.py"
    
    # Si el archivo original no existe, ignorarlo
    if not os.path.exists(nombre_actual):
        continue
        
    # 3. Aplicar la nueva lógica de descarte y resta
    if i == 16 or i == 17:
        # Se omiten por completo (quedan eliminados en el resultado)
        print(f"Omitido (eliminado): {nombre_actual}")
        continue
    elif 18 <= i <= 24:
        # A partir del 18 se les resta 2 (18->16, ..., 24->22)
        nuevo_numero = i - 2
    else:
        # Del 00 al 15 se quedan exactamente igual
        nuevo_numero = i
        
    nombre_nuevo = f"{nuevo_numero:02d}.py"
    ruta_nueva = os.path.join(carpeta_destino, nombre_nuevo)
    
    # 4. Copiar de forma segura
    shutil.copy2(nombre_actual, ruta_nueva)
    print(f"Procesado seguro: {nombre_actual} -> {ruta_nueva}")

print("\n¡Proceso completado! Revisa la carpeta 'archivos_renombrados'.")
