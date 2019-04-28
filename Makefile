# Compilateur et flags
CFLAGS = -Wall -pedantic -std=c99

# Nom cible
TARGET = tp3

CP = $(shell cat cp.txt)

default: all
 
all: $(TARGET).o 
	gcc $(CFLAGS) -g -o $(TARGET) -lm  $(TARGET).o outils.o structure.o
outils.o : outils.h outils.c
	gcc $(CFLAGS) -c -o outils.o outils.c

structure.o : structure.h structure.c
	gcc $(CFLAGS) -c -o structure.o structure.c

$(TARGET).o : $(TARGET).c
	gcc $(CFLAGS) -g -c $(TARGET).c outils.c structure.c




clean:
	rm -f $(TARGET)
	rm -f *.o
	rm -f code.txt
	rm -f *.out
	rm -rf data
	rm -f *.correction
	rm -f tp2
	rm -f resultat.txt
resultat:
	git add resultat.txt
	git commit -m "RESULTAT AJOUTER"
	git push
push:
	git add .
	git commit -m "Modification TP3"
	git push

test:
	make
	./$(TARGET) -c $(CP) -i data/data.txt -o resultat.txt

data:
	wget https://www.github.com/guyfrancoeur/INF3135_H2019/raw/master/tp1/data.zip 
	unzip data.zip -d ./data
	rm data.zip
depot:
	rm -rf ~/depot
	wget https://www.github.com/guyfrancoeur/INF3135_H2019/raw/master/tp3/tp3-data.zip
	unzip tp3-data.zip -d ~/depot
	rm tp3-data.zip
