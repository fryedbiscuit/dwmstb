module dwmstb::bar;
import dwmstb::x;
import std;

extern fn int sleep(int);

fn void main(){
	Display* dpy = x::openDisplay(null);
	if(dpy == null){
		io::eprintn("Error: cound not open X display!");
	}

	Window root = x::defaultRootWindow(dpy);

	while(true){
		x::storeName(dpy,root,"Hello world");
		x::flush(dpy);
		sleep(1);
	}
}
