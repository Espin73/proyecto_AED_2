# proyecto_AED_2

## 📝 Instrucciones para colaborar en el proyecto

### 1️⃣ Clonar el repositorio (solo la primera vez)
```bash
git clone https://github.com/usuario/proyecto_AED_2.git
cd proyecto_AED_2
code .
```

> **Nota:** Sustituye `usuario` por el nombre real del propietario del repositorio.

### 2️⃣ Configurar tu usuario (solo la primera vez)
```bash
git config --global user.name "TuNombre"
git config --global user.email "tuemail@ejemplo.com"
```

### 3️⃣ Traer los cambios más recientes (pull)

Antes de empezar a programar, descarga los cambios que haya subido tu compañero:
```bash
git pull
```

### 4️⃣ Guardar tus cambios localmente (commit)

Cuando hagas cambios en los archivos:
```bash
git add .
git commit -m "Descripción de lo que cambiaste"
```

### 5️⃣ Subir tus cambios al repositorio (push)
```bash
git push
```

> **💡 Consejo:** Siempre haz primero `git pull` antes de `push` para evitar conflictos.

### 6️⃣ Resolver conflictos (si ocurren)

1. Git marcará los archivos en conflicto con `<<<<<<<`, `=======`, `>>>>>>>`.
2. Edita el archivo para conservar los cambios correctos.
3. Luego ejecuta:
```bash
git add .
git commit -m "Resolviendo conflicto"
git push
```
