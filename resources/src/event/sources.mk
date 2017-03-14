MAIN	:= event_gesture.c event_tools.c event.c
OBJ		:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIREVENT)/%.c $(HEAD)
	$(COMPIL)
