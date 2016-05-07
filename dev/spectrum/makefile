include ../rules.mak
FLAGS+=-I../pxl -I../wavl
LFLAGS=-lncurses

run: foo
	arecord -t wav -f cd --rate 2000 -d 10 | ./foo

run3: foo
	./foo < nick-kos-butterfly.wav

run2: foo
	./play_all
