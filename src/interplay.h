#ifndef _INTERPLAY
#define _INTERPLAY


#include "ofMain.h"
#include "shader.h"

enum IPState {
	playing

};

class Interplay : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);

		//--------------------------------------------------------------
		vector<ofVideoPlayer*> videos;	// TODO refactor into class?
		vector<ofTexture*> results;
		// TODO not in use atm, may refactor into "blob extractor" class
		ofTexture result;

		shader mask;

		int w, h;



	//--------------------------------------------------------------
	//--------------------------------------------------------------

	protected:

	//--------------------------------------------------------------
	//--------------------------------------------------------------

	private:
		ofVideoPlayer* loadVideo(string filename);

};

#endif
