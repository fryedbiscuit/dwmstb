module dwmstb::x;

alias Display = void;
alias Window = CULong;

extern fn Display* openDisplay(char*) @cname("XOpenDisplay");
extern fn Window defaultRootWindow(Display*) @cname("XDefaultRootWindow");
extern fn int storeName(Display*,Window,char*) @cname("XStoreName");
extern fn int flush(Display*) @cname("XFlush");
