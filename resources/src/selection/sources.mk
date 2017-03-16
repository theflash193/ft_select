MAIN	:= clst_del_elem.c cursor_next.c cursor_prev.c loop.c affichage_element.c \
	affichage_element.c calcul_max.c message_taille_insufisante.c \
	update_maxlen.c affichage_selection.c affichage_pading.c
OBJ		:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRSELECTION)/%.c $(HEAD)
	$(COMPIL)
