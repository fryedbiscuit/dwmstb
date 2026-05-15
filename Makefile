dwmstb: dwmstb.c dwmstb.h battery.c clock.c
	gcc -lX11 -o dwmstb dwmstb.c dwmstb.h battery.c clock.c

run: dwmstb
	./dwmstb
