MAIN	:= event_gesture.c \
	event_return.c event_down.c event_up.c event_quit.c event_select.c\
	event_delete.c 
OBJ		:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIREVENT)/%.c $(HEAD)
	$(COMPIL)
