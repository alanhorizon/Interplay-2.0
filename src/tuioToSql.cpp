#include "testApp.h"
#include <ctime>

//--------------------------------------------------------------
void testApp::setup(){
	// typical setup skeleton
	ofBackground(200, 200, 200);
	ofSetVerticalSync(true);

	// establish tuio connection
	myTuioClient.connect(3333);
	myTuioClient.setVerbose(true);

	// assign global tuio callback functions
	// PARSEME no idea what this does.
	ofAddListener(ofEvents.touchDown, this, &testApp::touchDown);
	ofAddListener(ofEvents.touchUp, this, &testApp::touchUp);
	ofAddListener(ofEvents.touchMoved, this, &testApp::touchMoved);

	ofAddListener(myTuioClient.cursorAdded,this,&testApp::tuioCursorAdded);
	ofAddListener(myTuioClient.cursorRemoved,this,&testApp::tuioCursorRemoved);
	ofAddListener(myTuioClient.cursorUpdated,this,&testApp::tuioCursorUpdated);

	// setup (open or create) sql database
	blobdb = new ofxSQLite("blob.db");	// create or open db file
	if (blobdb->simpleQuery(""\
						"CREATE TABLE IF NOT EXISTS position ("\
						"id INTEGER,"\
						"time INTEGER,"\
						"x REAL,"\
						"y REAL"\
						");"
						) != SQLITE_OK){
							cout << "error creating database." << endl;
						}

	// TODO load movie or initiate video grabber

	// TODO setup gui

}

//--------------------------------------------------------------
void testApp::update(){
	// update video frame
	// get tracking data in tuio format
	// store tuio data in sqlite db
}

//--------------------------------------------------------------
void testApp::draw(){
	// render tuio cursors and objects
	myTuioClient.drawCursors();
	myTuioClient.drawObjects();




	// draw gui
	// show live feed
	// prompt user controls
	//
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

void testApp::updateDB(int id, int time, double x, double y){
	// TODO insert tuio to sql
	blobdb->insert("position")	// insert() returns ofxSQLiteInsert object
		.use("id", id)			// which has use() method: specify field/column and value
		.use("time", time)		// calls to use() returns the same ofxSQLiteInsert, allowing nested use() calls
		.use("x", x)
		.use("y", y)
	.execute();				// executes query and returns error code (i.e. SQLITE_OK)
}


void testApp::tuioCursorAdded(TuioCursor & tcur){
	cout << " cursor added: " + ofToString(tcur.getCursorID())+
	" X: "+ofToString(tcur.getX())+
	" Y: "+ofToString(tcur.getY())
	<< endl;

//	cout << ofToString(touch.id) << ofToString((int)time(NULL)) << ofToString(touch.x) << endl;
	updateDB(tcur.getCursorID(), time(NULL), tcur.getX(), tcur.getY());
	//forward the touch events to ofxMultiTouch for the InteractiveObjects
//	ofxMultiTouch.touchDown(tcur.getX(), tcur.getY(), tcur.getCursorID(), NULL);
}

void testApp::tuioCursorRemoved(TuioCursor & tcur){
//	cout << " cursor removed: " + ofToString(tcur.getCursorID())+
//	 " X: "+ofToString(tcur.getX())+
//	 " Y: "+ofToString(tcur.getY())
//	 << endl;
	updateDB(tcur.getCursorID(), time(NULL), tcur.getX(), tcur.getY());

	//forward the touch events to ofxMultiTouch for the InteractiveObjects
//	ofxMultiTouch.touchUp(tcur.getX(), tcur.getY(), tcur.getCursorID(), NULL);
}

void testApp::tuioCursorUpdated(TuioCursor & tcur){
	cout << " cursor updated: " + ofToString(tcur.getCursorID())+
	 " X: "+ofToString(tcur.getXSpeed())+
	 " Y: "+ofToString(tcur.getYSpeed())
	 << endl;
	updateDB(tcur.getCursorID(), time(NULL), tcur.getX(), tcur.getY());

	//forward the touch events to ofxMultiTouch for the InteractiveObjects
//	ofxMultiTouch.touchMoved(tcur.getX(), tcur.getY(), tcur.getCursorID(), NULL);
}

/*
 * touch event handlers
 */
void testApp::touchDown(ofTouchEventArgs & touch){
	cout << " cursor added: " + ofToString(touch.id)+
	" X: "+ofToString(touch.x)+
	" Y: "+ofToString(touch.y)
	<< endl;
}

void testApp::touchUp(ofTouchEventArgs & touch){
	cout << " cursor removed: " + ofToString(touch.id)+
	 " X: "+ofToString(touch.x)+
	 " Y: "+ofToString(touch.y)
	 << endl;
}

void testApp::touchMoved(ofTouchEventArgs & touch){
	cout << " cursor updated: " + ofToString(touch.id)+
	 " X: "+ofToString(touch.x)+
	 " Y: "+ofToString(touch.y)
	 << endl;
}
