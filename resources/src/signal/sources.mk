MAIN	:= signal_handler.c changement_taille_fenetre.c pause_programme.c reprise_programme.c

OBJ		:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRSIGNAL)/%.c $(HEAD)
	$(COMPIL)
