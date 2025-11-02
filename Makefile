all: test dwmstt

dwmstt: main.c modules.c
	gcc -o dwmstt main.c modules.c

run: dwmstt
	./dwmstt

test: main.c modules.c
	gcc -o test main.c modules.c -D TEST

trun: test
	./test

clean:
	rm -f test dwmstt

.PHONY: all run trun clean
