make:
	#!/usr/bin/env -S make -f
	dwmstb: dwmstb.c dwmstb.h clock.c
		gcc -lX11 -flto -O3 -o dwmstb dwmstb.c clock.c

run: make
	DISPLAY=:0 ./dwmstb
