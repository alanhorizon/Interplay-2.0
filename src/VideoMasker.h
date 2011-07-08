#ifndef VIDEOMASKER_H
#define VIDEOMASKER_H


class VideoMasker
{
	public:
		/** Default constructor */
		VideoMasker();

		unsigned char* createMagentaMask(unsigned char* rgbFrame, int frameWidth, int frameHeight,
										int maskX, int maskY, int maskWidth, int maskHeight);

	protected:


	private:
		unsigned char* drawRectangle(unsigned char * frame, int frameWidth, int frameHeight,
						int pixelX, int pixelY, int width, int height,
						int r, int g, int b);


};

#endif // VIDEOMASKER_H
