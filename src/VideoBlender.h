#ifndef VIDEOBLENDER_H
#define VIDEOBLENDER_H


class VideoBlender
{
	public:
		/** Default constructor */
		VideoBlender();

		unsigned char* createRgbaFromMagentaMask(unsigned char* rgbFrame, int frameWidth, int frameHeight);
	protected:
	private:
};

#endif // VIDEOBLENDER_H
