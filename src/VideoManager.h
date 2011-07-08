#include "ofMain.h"

#ifndef VIDEOMANAGER_H
#define VIDEOMANAGER_H


class VideoManager
{
	public:
		ofVideoPlayer testvideo;
		vector<ofVideoPlayer> videos;
		map<string, int> filenameToIdMap;
		int counter;

		/** Default constructor */
		VideoManager();
		void loadVideo(string filename);
		void playVideo(string filename);
		void updateVideo(string filename);
		void drawVideo(string filename, int x, int y);
		ofVideoPlayer* getVideo(string filename);

	protected:
	private:
};

#endif // VIDEOMANAGER_H
