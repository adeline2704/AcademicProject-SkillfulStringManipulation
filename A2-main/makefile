stringMe: alaskarovAdelineA2.o alaskarovAdelineA2Main.o
	gcc -Wall -std=c99 alaskarovAdelineA2.o alaskarovAdelineA2Main.o -o bin/stringMe
alaskarovAdelineA2.o: src/alaskarovAdelineA2.c include/alaskarovAdelineA2.h
	gcc -Wall -std=c99 -c src/alaskarovAdelineA2.c
alaskarovAdelineA2Main.o: src/alaskarovAdelineA2Main.c include/alaskarovAdelineA2.h
	gcc -Wall -std=c99 -c src/alaskarovAdelineA2Main.c
clean:
	rm *.o bin/stringMe
