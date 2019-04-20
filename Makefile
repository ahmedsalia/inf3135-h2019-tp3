# Compilateur et flags
CFLAGS = -Wall -pedantic -std=c99

# Nom cible
TARGET = tp3

CP = $(shell cat cp.txt)

default: all
 
all: $(TARGET).o
	gcc $(CFLAGS) -g -o $(TARGET) $(TARGET).o outils.o

outils.o : outils.h outils.c
	gcc $(CFLAGS) -c -o outils.o outils.c

$(TARGET).o : $(TARGET).c
	gcc $(CFLAGS) -g -c $(TARGET).c outils.c 

clean:
	rm -f $(TARGET)
	rm -f *.o
	rm -f code.txt
	rm -f *.out


resultat:
	git add resultat.txt
	git commit -m "RESULTAT AJOUTER"
	git push
push:
	git add .
	git commit -m "Modification TP2"
	git push

test:
	./$(TARGET) -c $(CP) -i data.txt -o resultat.txt

data:
	wget https://www.github.com/guyfrancoeur/INF3135_H2019/raw/master/tp1/data.zip 
	unzip data.zip -d ./data
	rm data.zip
