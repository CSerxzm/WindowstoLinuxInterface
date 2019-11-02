$(CC)      :=gcc

bin/DIR,bin/RD,bin/CD,bin/MD, bin/DEL,bin/REN,bin/XCOPY,\
bin/PROMPT,bin/SORT,bin/TYPE,bin/COPY,bin/COMP,bin/MORE,bin/FIND,bin/MOVE:src/DIR.c \
src/RD.c src/CD.c src/MD.c src/DEL.c src/REN.c \
src/XCOPY.c src/PROMPT.c src/SORT.c src/TYPE.c src/COPY.c src/COMP.c \
src/MORE.c src/FIND.c src/MOVE.c
	mkdir -p bin
	$(CC) src/DIR.c -o bin/DIR
	$(CC) src/RD.c -o bin/RD
	$(CC) src/CD.c -o bin/CD
	$(CC) src/MD.c -o bin/MD
	$(CC) src/DEL.c -o bin/DEL
	$(CC) src/REN.c -o bin/REN
	$(CC) src/XCOPY.c -o bin/XCOPY
	$(CC) src/PROMPT.c -o bin/PROMPT
	$(CC) src/SORT.c -o bin/SORT
	$(CC) src/TYPE.c -o bin/TYPE
	$(CC) src/COPY.c -o bin/COPY
	$(CC) src/COMP.c -o bin/COMP
	$(CC) src/MORE.c -o bin/MORE
	$(CC) src/FIND.c -o bin/FIND
	$(CC) src/MOVE.c -o bin/MOVE
.PHONY: clean
clean:
	rm -r bin/*
