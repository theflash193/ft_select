MAIN	:= clear_env.c print_select.c \

OBJ		:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRCOREUTILS)/%.c $(HEAD)
	$(COMPIL)
