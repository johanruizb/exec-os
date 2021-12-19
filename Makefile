todo:
	gcc -c leercadena.c
	gcc leercadena_ingrid.c -o leercadena_ingrid leercadena.o
	gcc leercadena_johan.c -o leercadena_johan leercadena.o

limpiar:
	rm -rf leercadena.o leercadena_johan leercadena_ingrid
