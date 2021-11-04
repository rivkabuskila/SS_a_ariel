CC=gcc
AR=ar
FLAGS=-g -Wall
LOOP= basicClassification.o advancedClassificationLoop.o
REC= basicClassification.o advancedClassificationRecursion.o

all: libclassloops.a libclassrec.a libclassrec.so libclassloops.so libclassrec.so mains maindloop maindrec


loops: libclassloops.a
recursives:libclassrec.a
recursived: libclassrec.so
loopd:libclassloops.so

#creat libraries
libclassloops.a:$(LOOP) 
	$(AR) -rcs libclassloops.a $(LOOP) 

libclassrec.a:$(REC) 
	$(AR) -rcs libclassrec.a $(REC) 

libclassrec.so:$(REC) 
	$(CC) -shared -o libclassrec.so $(REC)

libclassloops.so:$(LOOP) 
	$(CC) -shared -o libclassloops.so $(LOOP)

basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c -lm

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c -lm

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c -lm


mains: main.o libclassrec.a
	$(CC) $(FLAGS) -o mains main.o libclassrec.a -lm

maindloop: main.o libclassloops.so
	$(CC) $(FLAGS) -o maindloop main.o ./libclassloops.so -lm

maindrec: main.o libclassrec.so
	$(CC) $(FLAGS) -o maindrec main.o ./libclassrec.so -lm

main.o: main.c NumClass.h
	$(CC) $(FLAGS) -c main.c

.PHONY: clean all

clean:
	rm *.o *.a *.so mains maindloop maindrec