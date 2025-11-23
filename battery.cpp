#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "inc/json.hpp"
using json = nlohmann::json;


extern "C" void add_battery(char* buffer){

	// char* newbuffer = (char*)std::malloc(10 * sizeof(char));
	char * newbuffer = new char[10];
	FILE* p = popen("termux-battery-status","r");
	json batt = json::parse(p);
	pclose(p);
	sprintf(newbuffer, " [%02d%%}",(int)batt["percentage"]);
	std::strcat(buffer, newbuffer);
	delete [] newbuffer;
}
