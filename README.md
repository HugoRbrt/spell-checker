# TP_CorrecteurOrthographique

Au début il faut créer 3 répertoires : test, bin et obj. Ils serviront par la suite pour le Makefile.

! il faut mettre tous les fichiers text dans le dossier text !

➞ Pour lancer le correcteur il faut utiliser le test "verif_ortho.c", pour cela :
	- depuis le terminal dans le fichier tp : 
	- exécuter la commande : make bin/verif_ortho
	- puis : ./bin/verif_ortho text/FR.txt text/a_la_recherche_du_temps_perdu.txt
-----------------------------------------------------------------------------
➞ Pour mesurer le temps de chaques mode du correcteuril faut utiliser le test "Test_remplirArbre.c", pour cela :
	- depuis le terminal dans le fichier tp : 
	- exécuter la commande : make bin/Test_remplirArbre
	- puis : ./bin/Test_remplirArbre text/FR.txt text/a_la_recherche_du_temps_perdu.txt
-----------------------------------------------------------------------------
-----------------------------------------------------------------------------
➞ Pour effectuer des tests simple sur la structure de liste il faut utiliser le test "Test_list.c", pour cela : 
	- depuis le terminal dans le fichier tp : 
	- exécuter la commande : make bin/Test_list
	- puis : ./bin/Test_list
-----------------------------------------------------------------------------
➞ Pour effectuer des tests simple sur la structure d'arbre prefixe il faut utiliser le test "Test_ArbrePrefixe.c", pour cela : 
	- depuis le terminal dans le fichier tp : 
	- exécuter la commande : make bin/Test_ArbrePrefixe
	- puis : ./bin/Test_ArbrePrefixe
-----------------------------------------------------------------------------
➞ Pour effectuer des tests simple sur la structure d'arbre radix il faut utiliser le test "Test_ArbreRadix.c", pour cela : 
	- depuis le terminal dans le fichier tp : 
	- exécuter la commande : make bin/Test_ArbreRadix
	- puis : ./bin/Test_ArbreRadix
-----------------------------------------------------------------------------
Complément : 
➞ Utiliser les commandes suivantes pour obtenir l'empreinte mémoire d'un programme : (avec la fin du nom du fichier à la place de "PID")
valgrind --tool=massif ./bin/verif_ortho text/FR.txt text/a_la_recherche_du_temps_perdu.txt 
ms_print massif.out.PID
➞ Utilise le préfixe time avant la commande d'exécution pour obtenir le temps d'exécution d'un exécutable.