MAIN	:= main.c singleton.c
OBJ		:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRMAIN)/%.c $(HEAD)
	$(COMPIL)
