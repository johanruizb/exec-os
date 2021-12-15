todo:
	gcc -c leercadena.c
	gcc leercadena_main.c -o leercadena_main leercadena.o

limpiar:
	rm -rf leercadena.o leercadena_main
