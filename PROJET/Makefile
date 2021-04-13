### VARIABLES ###
 
CC = gcc

CFLAGS = -Wall \
         -ansi 

C_END = -lgraph


EXE = blocus

OFILES = first_ecran.o \
         second_ecran.o \
         partie_en_cours.o \
         third_ecran.o \
         main.o
 
### BUT PAR DEFAUT ###
 
but : ${EXE}
 
### REGLES ESSENTIELLES ###
  
main.o : first_ecran.h second_ecran.h index.h partie_en_cours.h third_ecran.h

first_ecran.o : first_ecran.h index.h

second_ecran.o : second_ecran.h index.h

partie_en_cours.o : partie_en_cours.h second_ecran.h index.h

third_ecran.o : third_ecran.h index.h

${EXE} : ${OFILES}
	$(CC) $(CFLAGS) -o ${EXE} ${OFILES} ${C_END}

### REGLES OPTIONNELLES ###

clean :
	-rm -f ${OFILES} ${EXE}

run :
	./${EXE}

### BUTS FACTICES ###
 
.PHONY : clean run but
 
### FIN ###