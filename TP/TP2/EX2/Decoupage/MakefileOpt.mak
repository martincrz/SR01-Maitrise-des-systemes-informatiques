OBJS = main.o explorer.o premier.o my_system.o
CC = gcc
edit : $(OBJS)
	$(CC) -o $@ $(OBJS)
main.o : explorer.h
explorer.o : my_system.h explorer.h premier.h
premier.o : premier.h
my_system.o : my_system.h
clean :
	rm edit *.o
