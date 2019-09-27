#pragma once

#include <string>
#include <vector>
#include "opencv2/opencv.hpp"
#include "image3.h"
#include "kernel3.h"

class Util {
private:
	Util();
public:
	static Kernel3* readKernel3FromFile(std::string);
	static Image3* concatImages(std::vector<Image3*>);
};
