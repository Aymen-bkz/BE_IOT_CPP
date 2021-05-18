#ifndef AREA_H
#define AREA_H


#include "JSON.h"
#define areaWidth 500
#define areaHeight 300

class Area {
	private:
		int width;
		int height;
		bool clear;
	public:
    Area();
    ~Area(){};
		void setArea(int width, int height);
		void set_json_area(JSON& json);
};




#endif
