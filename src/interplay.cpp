#include "interplay.h"
#include "VideoMasker.h"
#include "VideoBlender.h"
#include <vector>

VideoMasker masker;
VideoBlender blender;


//--------------------------------------------------------------
void Interplay::setup(){
	mask.setup(320, 240);
	// LOAD MULTIPLE VIDEOS TO PLAY AT ONCE
	videos.push_back(loadVideo("movies/test1.mov"));
	videos.push_back(loadVideo("movies/test2.mov"));
	videos.push_back(loadVideo("movies/test3.mov"));
	videos.push_back(loadVideo("movies/test4.mov"));
	videos.push_back(loadVideo("movies/test5.mov"));
	videos.push_back(loadVideo("movies/test6.mov"));
	videos.push_back(loadVideo("movies/test7.mov"));
	videos.push_back(loadVideo("movies/test8.mov"));
	videos.push_back(loadVideo("movies/test9.mov"));
	videos.push_back(loadVideo("movies/test10.mov"));
	videos.push_back(loadVideo("movies/test11.mov"));
	videos.push_back(loadVideo("movies/test12.mov"));
	videos.push_back(loadVideo("movies/atrium3peopleTest.mov"));

//	result.allocate(moviePlayer.getWidth(), moviePlayer.getHeight(), GL_RGBA);
	mask.setMaskParams(100, 200, 100, 200);
	// CREATE TEXTURES TO STORE RGBA
	for (int i=0; i<13; i++){
		videos.at(i)->play();
		w = videos.at(i)->getWidth();
		h = videos.at(i)->getHeight();



//		ofTexture * result = new ofTexture;
//		result->allocate(w, h, GL_RGBA);
//		results.push_back(result);
	}
}

//--------------------------------------------------------------
void Interplay::update(){
	ofBackground(150,150,150);	// static white background
	for (int i=0; i<13; i++){
		videos.at(i)->update();
	}

	cout << ofGetFrameRate() << endl;

	// CREATE DUMMY MAGENTA MASK, THEN CREATE RGBA FRAMES USING MASK AND VIDEO PIXELS
//	for (int i=0; i<12; i++){
//		int w = videos.at(i)->getWidth();
//		int h = videos.at(i)->getHeight();
//		unsigned char* masked = masker.createMagentaMask(videos.at(i)->getPixels(), w, h, 100, 100, 100, 100);
//		unsigned char* alpha = blender.createRgbaFromMagentaMask(masked, w, h);
//		results.at(i)->loadData(alpha, w, h, GL_RGBA);
//
//		delete [] alpha;
//	}

}

//--------------------------------------------------------------
void Interplay::draw(){
//	ofSetColor(0xff0000);
//	for (int i = 0; i < 100; i++){
//		ofLine(ofRandom(0,200), ofRandom(0,200), ofRandom(0,200), ofRandom(0,200));
//	}

	ofEnableAlphaBlending();



	videos.at(12)->draw(0, 0);
	videos.at(12)->draw(320, 0);
	videos.at(12)->draw(640, 0);
	videos.at(12)->draw(960, 0);
	videos.at(12)->draw(0, 240);
	videos.at(12)->draw(320, 240);
	videos.at(12)->draw(640, 240);
	videos.at(12)->draw(960, 240);
	videos.at(12)->draw(0, 480);
	videos.at(12)->draw(320, 480);
	videos.at(12)->draw(640, 480);
	videos.at(12)->draw(960, 480);

	// DRAW RGBA TEXTURES
//	ofSetColor(0xffffff);
//	results.at(0)->draw(0, 0);
//	results.at(1)->draw(320, 0);
//	results.at(2)->draw(640, 0);
//	results.at(3)->draw(960, 0);
//	results.at(4)->draw(0, 240);
//	results.at(5)->draw(320, 240);
//	results.at(6)->draw(640, 240);
//	results.at(7)->draw(960, 240);
//	results.at(8)->draw(0, 480);
//	results.at(9)->draw(320, 480);
//	results.at(10)->draw(640, 480);
//	results.at(11)->draw(960, 480);


	ofSetColor(0xffffff);


	// store frame information in shader's (mask's) fbo
	for (int i = 0; i < 12; i++){
		mask.beginRender();
		videos.at(i)->draw(0, 0);
		mask.endRender();
		switch (i){
			case 0:
				mask.draw(0, 0, w, h, true);
				break;
			case 1:
				mask.draw(320, 0, w, h, true);
				break;
			case 2:
				mask.draw(640, 0, w, h, true);
				break;
			case 3:
				mask.draw(960, 0, w, h, true);
				break;
			case 4:
				mask.draw(0, 240, w, h, true);
				break;
			case 5:
				mask.draw(320, 240, w, h, true);
				break;
			case 6:
				mask.draw(640, 240, w, h, true);
				break;
			case 7:
				mask.draw(960, 240, w, h, true);
				break;
			case 8:
				mask.draw(0, 480, w, h, true);
				break;
			case 9:
				mask.draw(320, 480, w, h, true);
				break;
			case 10:
				mask.draw(640, 480, w, h, true);
				break;
			case 11:
				mask.draw(960, 480, w, h, true);
				break;

		}
	}


	// use shader
//	mask.draw(0, 0, w, h, true); // TODO

	// DRAW REGULAR VIDEOS WITH NO EDITS
//	ofSetColor(0xffffff);
//	videos.at(0)->draw(0, 0);
//	videos.at(1)->draw(320, 0);
//	videos.at(2)->draw(640, 0);
//	videos.at(3)->draw(960, 0);
//	videos.at(4)->draw(0, 240);
//	videos.at(5)->draw(320, 240);
//	videos.at(6)->draw(640, 240);
//	videos.at(7)->draw(960, 240);
//	videos.at(8)->draw(0, 480);
//	videos.at(9)->draw(320, 480);
//	videos.at(10)->draw(640, 480);
//	videos.at(11)->draw(960, 480);



	ofDisableAlphaBlending();

//	ofEnableAlphaBlending();	// drawing rgba will not work without this function
//	result.draw(0, 0);
//	ofDisableAlphaBlending();	// disable alpha blending when no longer manipulating rgba
}


/**
  * Loads video and check if successful.  Return pointer to video player object.
  */
ofVideoPlayer* Interplay::loadVideo(string filename){
	ofVideoPlayer * video = new ofVideoPlayer;
	if (!video->loadMovie(filename)) std::exit(-1);
	return video;
}


//--------------------------------------------------------------
void Interplay::keyPressed(int key){

}

//--------------------------------------------------------------
void Interplay::keyReleased(int key){

}

//--------------------------------------------------------------
void Interplay::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void Interplay::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void Interplay::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void Interplay::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void Interplay::windowResized(int w, int h){

}

