MAIN	:= main.c parser.c cursor_next.c cursor_prev.c capacity.c select.c loop.c termios.c\

OBJ		:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRMAIN)/%.c $(HEAD)
	$(COMPIL)
