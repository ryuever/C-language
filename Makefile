PROGS = switchTest calSize function pointer charPointerCharArray IfBreak cSpecial macro \
printf traps enumTest myGetline scopeBlockScope operator structUnion
CFLAGS = -g

all: $(PROGS) file

$(PROGS): 
	$(CC) $(CFLAGS) -o $@ $@.c $(LDFLAGS)  

file:
	$(CC) $(CFLAGS) -o $@ $@.c -lreadline

clean:
	rm -f $(PROGS) file *.o *.out *.s  *.gch
