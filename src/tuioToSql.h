#ifndef _TEST_APP
#define _TEST_APP


#include "ofMain.h"
#include "ofxSQLite.h"
#include "ofxTuioClient.h"
#include "ofxSQLiteHeaders.h"

class testApp : public ofBaseApp{

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

		// TUIO stuff
		ofxTuioClient myTuioClient;

		void touchDown(ofTouchEventArgs & touch);
		void touchUp(ofTouchEventArgs & touch);
		void touchMoved(ofTouchEventArgs & touch);

		void tuioCursorAdded(TuioCursor & tcur);
		void tuioCursorRemoved(TuioCursor & tcur);
		void tuioCursorUpdated(TuioCursor & tcur);

		// SQL stuff
		ofxSQLite * blobdb;
		void updateDB(int id, int time, double x, double y);



};

#endif
