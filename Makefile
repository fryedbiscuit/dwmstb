LIBS="-lX11"
OBJ = main.o clock.o battery.o setname.o

dwmstb: main.o clock.o battery.o setname.o
	g++ -o dwmstb $(OBJ) $(LIBS)

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
