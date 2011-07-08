#include "VideoMasker.h"
#include <iostream>

VideoMasker::VideoMasker()
{
	//ctor
}

unsigned char* VideoMasker::createMagentaMask(unsigned char* rgbFrame, int frameWidth, int frameHeight,
											int maskX, int maskY, int maskWidth, int maskHeight){
	return drawRectangle(rgbFrame, frameWidth, frameHeight, maskX, maskY, maskWidth, maskHeight, 255, 0, 255);
}

unsigned char* VideoMasker::drawRectangle(unsigned char * frame, int frameWidth, int frameHeight,
							int pixelX, int pixelY, int width, int height,
							int r, int g, int b){

	// TODO add checks to ensure robustness
	// check validity of arguments: i.e. if out of bounds do nothing
	// assert width/height/x/y >= 0
	// assert rgb >=0 <=255, default value of 0

	// nested for loop from pixelX/Y to width/height
//	std::cout << "masked size: " << frameWidth * frameHeight * 3 << std::endl;

	for (int i = 0; i < width; i++){
		for (int j = 0; j < height; j++){
			frame[3*((pixelY+j)*frameWidth + (pixelX+i)) + 0] = r;
			frame[3*((pixelY+j)*frameWidth + (pixelX+i)) + 1] = g;
			frame[3*((pixelY+j)*frameWidth + (pixelX+i)) + 2] = b;
		}
	}
	return frame;
/*	img.setFromPixels(frame, frameWidth, frameHeight, OF_IMAGE_COLOR);
	sprintf(fileName, "snapshot_%0.3i.png", snapCounter);
	img.saveImage(fileName);
	snapCounter++;*/
}
