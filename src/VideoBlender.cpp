#include "VideoBlender.h"
#include <iostream>

VideoBlender::VideoBlender()
{
	//ctor
}

/**
  * Generates rgba pixels with alpha channel transparency from rgb pixels with
  * magenta mask.
  *
  */
unsigned char* VideoBlender::createRgbaFromMagentaMask(unsigned char* rgbFrame, int frameWidth, int frameHeight){
//	std::cout << "alpha array size: " << frameWidth*frameHeight*4 << std::endl;
	unsigned char* rgbaFrame = new unsigned char[frameWidth*frameHeight*4];
	for (int i = 0; i < frameWidth; i++){
		for (int j = 0; j < frameHeight; j++){
			if (rgbFrame[3*(j*frameWidth + i) + 0] == 255 &&
				rgbFrame[3*(j*frameWidth + i) + 1] == 0 &&
				rgbFrame[3*(j*frameWidth + i) + 2] == 255){
				// set alpha completely transparent i.e. black 0x000000
				rgbaFrame[4*(j*frameWidth + i) + 0] = 255;
				rgbaFrame[4*(j*frameWidth + i) + 1] = 0;
				rgbaFrame[4*(j*frameWidth + i) + 2] = 255;
				rgbaFrame[4*(j*frameWidth + i) + 3] = 150;
			} else{
				rgbaFrame[4*(j*frameWidth + i) + 0] = rgbFrame[3*(j*frameWidth + i) + 0];
				rgbaFrame[4*(j*frameWidth + i) + 1] = rgbFrame[3*(j*frameWidth + i) + 1];
				rgbaFrame[4*(j*frameWidth + i) + 2] = rgbFrame[3*(j*frameWidth + i) + 2];
				rgbaFrame[4*(j*frameWidth + i) + 3] = 255;
			}
		}
	}
	return rgbaFrame;
}
