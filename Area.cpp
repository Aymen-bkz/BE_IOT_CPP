#include "Area.h"

Area:: Area(){}

void Area:: setArea(int width, int height) {
	this->width = width;
	this->height = height;
	this->clear = false;
}

void Area:: set_json_area(JSON& json) {
	json.area_w = this->width;
	json.area_h = this->height;
	json.clear = this->clear;
}
