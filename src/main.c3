module dwmstb::main;

import dwmstb;
import std;

fn void main(){
	Display* dpy = x::openDisplay(null);
	if(dpy == null){
		io::eprintn("Error: cound not open X display!");
	}

	Window root = x::defaultRootWindow(dpy);

	while(true){
		@pool(){
			BatteryInfo batt = info::get_battery();
			String buffer = string::format(tmem,"%.0f°C %d%% %s",batt.temp,batt.percentage,info::clock());

			x::storeName(dpy,root,buffer.zstr_tcopy());
			x::flush(dpy);
			os::sleep(1);
		};
	}
}
