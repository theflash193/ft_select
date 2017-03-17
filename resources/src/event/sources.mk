MAIN	:= event_gesture.c event_tools.c \
	event_return.c event_right.c event_left.c event_quit.c event_select.c\
	event_delete.c 
OBJ		:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIREVENT)/%.c $(HEAD)
	$(COMPIL)
