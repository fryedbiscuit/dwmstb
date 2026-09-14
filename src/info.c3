module dwmstb::info;
import dwmstb;
import std;
import libc;

fn String clock()
{
	TzDateTime now = datetime::now().to_local();
	now.add_minutes(now.gmt_offset);
	String clock = string::format(tmem,"%02d:%02d:%02d",now.hour,now.min,now.sec);
	return clock;
}

struct BatteryInfo {
	bool plugged;
	int percentage;
	double temp;
}

fn BatteryInfo get_battery()
{
	CFile* p = os::popen("termux-battery-status", "r");
	defer os::pclose(p);
	File pf = file::from_handle(p);

	Object* jbatt = json::tload(&pf)!!;

	int percentage = jbatt.get_int("percentage")!!;
	double temp = jbatt.get_float("temperature")!!;
	bool plugged;
	String str_plugged = jbatt.get_string("plugged")!!;
	if(str_plugged == "UNPLUGGED"){
		plugged = false;
	} else {
		plugged = true;
	}

	return {plugged, percentage,temp};
}
