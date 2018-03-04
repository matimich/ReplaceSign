
CC =gcc
CFLAGS =-I.
INCLUDE =ReplaceSign.h
OBJECTS = main.o ReplaceSign.o

%.o: %.c $(INCLUDE)
	$(CC) -c -o $@ $< $(CFLAGS)

Replace: $(OBJECTS)
	$(CC) -o $@ $(OBJECTS) $(CFLAGS)

