# Ce Makefile permet de générer les executables
#-  pour le programme pccmain du repertoire src

# les fichiezrs executables sont situés sdnas le repertoire bin
# teste

#Les repertoires
#Pour les fichiers d'entete
INCDIR=./include
#Pour les fichiers executables
BINDIR=./bin
#Pour les fichiers binaires (.o)
OBJDIR=./obj
#Pour les fichiers de tests
TEST=./test
#Pour les fichiers sources .c
SRCDIR=./src

#Le nom du compilateur
CC=gcc

#Les options du compilateur : compilation (-c) et debug (-g). On peut ajouter -O3 pour optimiser quand le code est juste
CFLAGS=-c -g -I$(INCDIR)

#Les options de l'editeur de liens : -lm pour la bibliothèque mathématique. Voir les Makefile de TP pour ajouter la SDL si besoin
LDFLAGS= -lm

#Les executables que l'on veut construire: a la fois ceux des tests et ceux des programmes finaux
#exemple : EXEDIR=$(BINDIR)/pccmain $(BINDIR)/test_algo $(BINDIR)/test_algoTempo  $(BINDIR)/test_list $(BINDIR)/list $(BINDIR)/graph $(BINDIR)/arc $(BINDIR)/test_edge $(BINDIR)/test_readprint $(BINDIR)/test_hashtable $(BINDIR)/test_space $(BINDIR)/space $(BINDIR)/test_affichage
EXEDIR=$(BINDIR)/Test_ArbrePrefixe $(BINDIR)/Test_ArbreRadix $(BINDIR)/ArbrePrefixe $(BINDIR)/ArbreRadix $(BINDIR)/Test_remplirArbre
#Les fichiers binaire : ajouter les noms des nouveaux fichiers ici (pas les test)
OBJ=$(OBJDIR)/ArbrePrefixe.o $(OBJDIR)/ArbreRadix.o

#Pour construire tous les executables
all: $(EXEDIR)

#pour construire pccmain qui utilise tous les fichiers binaires
#exemple : $(BINDIR)/pccmain : $(OBJ) $(OBJDIR)/pccmain.o
#	$(CC) -o $@ $^ $(LDFLAGS)

#pour construire le test test_edge qui utilise arc.o
$(BINDIR)/Test_ArbrePrefixe : $(OBJ) $(OBJDIR)/Test_ArbrePrefixe.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(BINDIR)/Test_ArbreRadix : $(OBJ) $(OBJDIR)/Test_ArbreRadix.o
	$(CC) -o $@ $^ $(LDFLAGS)

$(BINDIR)/Test_remplirArbre : $(OBJ) $(OBJDIR)/Test_remplirArbre.o
	$(CC) -o $@ $^ $(LDFLAGS)


# pour construire les fichiers binaires .o
$(OBJDIR)/%.o : $(TEST)/%.c
	$(CC) $(CFLAGS) $^ -o $@

$(OBJDIR)/%.o : $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $^ -o $@


clean:
	rm -rf $(OBJDIR)/* $(BINDIR)/* $(EXEDIR) *.dSYM
