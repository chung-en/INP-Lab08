CFLAG = -g -Wall -static
FILES = udpsrv udpcli file_generator
HFILE = include/*.h
MODUL = module/*.c
all: $(FILES)

udpsrv: udpsrv.c $(MODUL) $(HFILE)
	gcc $(CFLAG) -o udpsrv udpsrv.c $(MODUL)

udpcli: udpcli.c $(MODUL) $(HFILE)
	gcc $(CFLAG) -o udpcli udpcli.c $(MODUL)

file_generator: file_generator.c
	gcc -o file_generator file_generator.c

clean:
	rm $(FILES)
