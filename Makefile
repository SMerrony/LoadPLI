# Modified from SA_make:
# Sample makefile for Iron Spring PL/I [Linux]
# This makefile will compile a PL/I program
# and link it 'stand-alone' (without libc).
# It assumes the compiler has been installed in
# a directory in your $PATH, and that
# the library is in /usr/local/lib.

# The ld flag '-z muldefs' is required to prevent
# link errors caused by possible multiple definitions
# of initialized PL/I EXTERNAL data.

# When linked without libc, the entry point should be
# 'main' or '_pli_Main', defined by the ld option '-e main'.

# 'INC' provides a list of directories to search for include files.
# Each entry should be preceded by '-i'

# Some modifications by SHM

PLI	= plic
PLIFLGS	= -lsaxo "-cn(^)"
INC     = -i.

TARGET	= adfl

default: adfl

adfl.o:	adfl.pl1
	${PLI} -C ${PLIFLGS} ${INC} $^ -o $*.o

swap_bytes_in_word.o:	swap_bytes_in_word.pl1
	${PLI} -C ${PLIFLGS} ${INC} $^ -o $*.o

rev_bytes_in_dword.o:	rev_bytes_in_dword.pl1
	${PLI} -C ${PLIFLGS} ${INC} $^ -o $*.o

get_working_dir.o: get_working_dir.pl1
	${PLI} -C ${PLIFLGS} ${INC} $^ -o $*.o

adfl:	adfl.o swap_bytes_in_word.o rev_bytes_in_dword.o get_working_dir.o
	ld  -z muldefs -Bstatic -M  -e main -t -o $@ 	\
	adfl.o swap_bytes_in_word.o rev_bytes_in_dword.o get_working_dir.o	\
	-lprf    					\
	>$@.map

clean:
	rm -rf adfl *.lst *.map *.o

