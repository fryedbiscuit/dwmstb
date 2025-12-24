CC=gcc
CXX=g++

LIBS="-lX11"
OBJ = main.o clock.o battery.o setname.o volume.o

dwmstb: ${OBJ}
	g++ -o dwmstb -flto -O3 $(OBJ) $(LIBS)

${OBJ}:

run: dwmstb
	./dwmstb

clean:
	rm -f dwmstb
	rm $(OBJ)

install: dwmstb
	install -T -D -m 755  dwmstb $(PREFIX)/usr/local/bin/dwmstb

uninstall:
	rm $(PREFIX)/usr/local/bin/dwmstb

.PHONY: all run clean
