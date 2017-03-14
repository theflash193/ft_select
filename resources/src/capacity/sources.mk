MAIN	:= cancel_mode.c clear_window.c cp_string.c invisible_cursor.c \
				move_cursor.c normal_cursor.c refresh_window.c reverse_video.c \
			underline_on.c underline_off.c
OBJ		:= $(OBJ) $(MAIN:.c=.o)

$(DIROBJ)/%.o: $(DIRCAPACITY)/%.c $(HEAD)
	$(COMPIL)
