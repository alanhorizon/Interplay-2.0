#include "VideoManager.h"


VideoManager::VideoManager()
{
	//ctor
	videos.reserve(10);
	counter=0;

}

void VideoManager::loadVideo(string filename){
	ofVideoPlayer *video = new ofVideoPlayer;
	testvideo.loadMovie(filename);
	if (!video->loadMovie(filename)) exit(-1);
	videos.push_back(*video);
	filenameToIdMap[filename] = counter;
	counter++;
}

void VideoManager::playVideo(string filename){
	videos.at(filenameToIdMap[filename]).play();
}

void VideoManager::updateVideo(string filename){
	videos.at(filenameToIdMap[filename]).update();
}

void VideoManager::drawVideo(string filename, int x, int y){
	videos.at(filenameToIdMap[filename]).draw(x, y);
}

ofVideoPlayer* VideoManager::getVideo(string filename){
	return &videos.at(filenameToIdMap[filename]);
}
