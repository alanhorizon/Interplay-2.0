#include "testApp.h"

int mWidth = 640;
int mHeight= 480;
//GL_TEXTURE_RECTANGLE_ARB
//--------------------------------------------------------------
void testApp::setup(){

	ofBackground(255,255,255);

	// load shader
	mixShader.loadShader("shaders/mix");

	//video
	vidGrabber.initGrabber(mWidth,mHeight);

	// DisableArbTex !!!
	//////////////////
	ofDisableArbTex();


	////////////image1
	myImg.loadImage("xxx.xxx");
	myImg.setImageType(OF_IMAGE_COLOR);

	w = myImg.width; //640;
	h = myImg.height; //480;

	imgPixels = myImg.getPixels();
	myTexture.allocate(w,h,GL_RGB);
	myTexture.loadData(imgPixels, w,h, GL_RGB);


	w2 = mWidth;
	h2 = mHeight;

	unsigned char *imgPixels2 = vidGrabber.getPixels();
	myTexture2.allocate(w2,h2,GL_RGB);
	myTexture2.loadData(imgPixels2, w2,h2, GL_RGB);




	///// multitextureLoad stuff
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, myTexture.getTextureData().textureID);


	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, myTexture2.getTextureData().textureID);


	// go back to default texture unit !!
	glActiveTexture(GL_TEXTURE0);
}

//--------------------------------------------------------------
void testApp::update(){
	vidGrabber.grabFrame();
	ofSetWindowTitle(ofToString(ofGetFrameRate(), 2.0));
	ofBackground(100,100,100);

	if(vidGrabber.isFrameNew())
	{
		
		myTexture2.loadData(vidGrabber.getPixels(), w2,h2, GL_RGB);
		glActiveTexture(GL_TEXTURE2);
		glBindTexture(GL_TEXTURE_2D, myTexture2.getTextureData().textureID);


		// go back to default texture unit !!
		glActiveTexture(GL_TEXTURE0);
	}
}

//--------------------------------------------------------------
void testApp::draw(){

	vidGrabber.draw(mWidth,mHeight);

	ofEnableAlphaBlending();

	myImg.draw(0,480);


	mixShader.setShaderActive(true);
	mixShader.setUniformVariable1i("tex1", 1); //send the the texture GL_TEXTURE1 to the shader as uniformVar text1.
	mixShader.setUniformVariable1i("tex2", 2); 
	mixShader.setUniformVariable1f("pan", sinf(float(ofGetFrameNum())/100.0f)); 

	// paint your textured stuff here !!
	// whatever you paint here will be painted with the result of the
	// multitexture shader !!
	myImg.draw(0,0,640,480);
	// or

	/*glBegin(GL_QUADS);

	glTexCoord2f(0, 0);
	glVertex2f(0, 0);

	glTexCoord2f(0, 0.5);
	glVertex2f(0, mHeight/);

	glTexCoord2f(0.5, 0.5);
	glVertex2f(mWidth, mHeight);

	glTexCoord2f(0.5, 0);
	glVertex2f(mWidth, 0);*/

	glEnd();

	//not sure where unbind the texture
	myTexture2.unbind();
	myTexture.unbind();
	// to finish, deActivate the multitexture shader !!
	mixShader.setShaderActive(false);


}



//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//------------- -------------------------------------------------
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

