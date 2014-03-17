PROGS = switchTest calSize function pointer charPointerCharArray IfBreak cSpecial macro \
printf traps enumTest myGetline scopeBlockScope operator structUnion
CFLAGS = -g -Wall

all: $(PROGS) file

.SECONDEXPANSION:
$(PROGS): $$@.c
	$(CC) $(CFLAGS) -o $@ $@.c $(LDFLAGS)  

file: file.c
	$(CC) $(CFLAGS) -o $@ $@.c -lreadline

clean:
	rm -f $(PROGS) file *.o *.out *.s  *.gch *.txt
