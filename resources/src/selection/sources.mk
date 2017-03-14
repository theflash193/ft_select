MAIN	:= clst_del_elem.c cursor_next.c cursor_prev.c loop.c select.c
OBJ		:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRSELECTION)/%.c $(HEAD)
	$(COMPIL)
