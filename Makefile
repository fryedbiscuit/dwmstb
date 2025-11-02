LIBS="-lX11"

dwmstb: main.c modules.c setname.c
	gcc -o dwmstb main.c modules.c setname.c $(LIBS)

run: dwmstb
	./dwmstb

clean:
	rm -f dwmstb

install: dwmstb
	install -T -D -m 755  dwmstb $(PREFIX)/usr/local/bin/dwmstb

.PHONY: all run clean
