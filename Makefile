todo:
	gcc -c leercadena.c
	gcc leercadena_ingrid.c -o leercadena_main leercadena.o

limpiar:
	rm -rf leercadena.o leercadena_main
