CFLAG = -g -Wall -static
FILES = udpsrv udpcli 
HFILE = include/*.h
MODUL = module/*.c
all: $(FILES)

udpsrv: udpsrv.c $(MODUL) $(HFILE)
	gcc $(CFLAG) -o udpsrv udpsrv.c $(MODUL)

udpcli: udpcli.c $(MODUL) $(HFILE)
	gcc $(CFLAG) -o udpcli udpcli.c $(MODUL)

clean:
	rm $(FILES)
