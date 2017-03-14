MAIN	:= capacity.c
OBJ		:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRCAPACITY)/%.c $(HEAD)
	$(COMPIL)
