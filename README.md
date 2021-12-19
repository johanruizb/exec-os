# Comprendiendo execvp()
---
## Índice
- [`Descripción`](#descripción)
 

- [`Desarrollo`](#desarrollo)
 
    
    - [`Problemas`](#problemas)
    
    
- [`Solución final`](#solución-final)
    
    - [`Solución de Ingrid`](https://github.com/johanruizb/exec-os#:~:text=Soluci%C3%B3n%20de%20Ingrid%20Echeverri%20Montoya)
    
    
    - [`Solución de Johan`](https://github.com/johanruizb/exec-os#:~:text=Solucion%20de%20Johan%20Andres%20Ruiz)
---

## Descripción
Desarrollo de la actividad comprendiendo `exec()`, propuesto en la clase Sistema Operativos del tema llamadas APIs. La API que utilizamos en este ejercicio es `exec()` más específico `execvp()` utilizado para reemplazar el proceso actual con un nuevo proceso especificado por las entradas que recibe `execvp()` en `PATH`. En el cual ningún `return` es hecho, ya que el proceso anterior fue reemplazado por el nuevo proceso.

Realizamos la creación de un shell básico la cual permite ejecutar comandos de manera interactiva con el código proveído por el profesor realizando los ajustes en el código fuente de `leercadena_main.c`.

---

## Desarrollo

Para el desarrollo de la actividad utilizamos una máquina virtual del sistema operativo Ubuntu descargado por medio de la Microsoft Store que nos permite utilizar la consola de comandos. 

Para empezar, descargamos los archivos proporcionados por el profesor en el siguiente repositorio, luego compilamos el archivo leercadena_main.c utilizando el comando en MakeFile.
```bash
-> make todo
```

El cual nos genera leercadena_main el cual podemos ejecutar utilizando
```bash
->./leercadena_main
```

Después de ver cómo funciona empezamos a editar el archivo `leercadena_main.c` para obtener el resultado deseado.


> [Código fuente: @josanabr - dummy_shell](https://github.com/josanabr/so_80/blob/master/05/dummy_shell/leercadena_main.c)

Para editar el archivo utilizamos el comando `nano <nombre>`.

Para el desarrollo del programa se intentó usar los atributos ‘argc’ y ‘argv’ del método main, porque estos atributos contienen la información necesaria, ‘argc’ es la cantidad de argumentos que se le pasan al programa al momento de ejecutarse y el atributo ‘argv’ es un vector que contiene cada uno de los argumentos, por ejemplo, para el siguiente ejecución:

```bash
> ./leercadena_main.c ls -l
```
El atributo ‘argc’ sería 3, ya que hay 3 argumentos que son ‘./leercadena_main.c’,‘ls’ y ‘ -l’ además de que son guardados en ‘argv’ de la siguiente manera{‘./leercadena_main.c’,‘ls’, ‘ -l’ }. 

Entonces se planeó recortar ‘argv’ y pasarlo directamente a execvp() o bien concatenarlo y usar la función de_cadena_a_vector() proveída por el profesor para sacar el vector organizado.

---

### Problemas
En el transcurso del desarrollo encontramos varios problemas que solucionar para que nuestra solución pudiera funcionar. Inicialmente uno de los problemas estaba relacionado con git, al hacer un push siempre pedía las credenciales del usuario lo cual se volvía muy molesto la solución que encontramos para este problema fue en StackOverflow por el usuario Marteen.

[Git asks for password to push on WSL 2 (Ubuntu), but not on Windows. Why is that? [closed]](https://stackoverflow.com/questions/66503781/git-asks-for-password-to-push-on-wsl-2-ubuntu-but-not-on-windows-why-is-that)

Gracias a este comentario solucionamos el problema.

El siguiente problema causó bastante frustración porque al inicio no entendíamos como solucionarlo, esto fue el segmentation fault error.

```bash
- Argumento 0: ./leercadena_main
- Argumento 1: ls
Segmentation fault 
```

Buscando soluciones en StackOverflow encontramos:

[Segmentation fault using execvp in c shell [duplicate]](https://stackoverflow.com/questions/40330330/segmentation-fault-using-execvp-in-c-shell)

Según el comentario, ese error se debe a que nuestra variable no era inicializada correctamente y no estaba apuntando a un espacio de memoria válido. Entonces, analizando el código podemos ver que a `vector` se le pasa `comando` pero este variable `comando` no tiene nada entonces la inicialización estaba incorrecta. 

De ahí comprendimos que debíamos darle un valor a comando para que el código funcionará de forma correcta. El siguiente error que enfrentamos después de esto fue concatenar strings, principalmente intentamos con comando = comando + *argv[i] pero eso no funcionó tirando el error:
```bash
C invalid operands to binary + (have 'char *' and 'char *')?
```

Siguiendo un video en youtube, encontramos que en C para concatenar debíamos utilizar la función strcat.

[Concatenating strings in C - Youtube](https://youtu.be/5QPPto-LoX4)

¡Aplicando la función correcta y realizando algunos ajustes más, por fin nos funcionó nuestra shell básica!

---

## Solución Final
Al final del desarrollo y solución de los problemas llegamos a la solución final de la actividad. Aplicamos 2 soluciones diferentes que al final tienen el mismo resultado.

Solución de Ingrid Echeverri Montoya: [leercadena_ingrid.c](https://github.com/johanruizb/exec-os/blob/master/leercadena_ingrid.c)

Solución de Johan Andrés Ruiz: [leercadena_johan.c](https://github.com/johanruizb/exec-os/blob/master/leercadena_johan.c)

---
