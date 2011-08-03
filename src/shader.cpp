/*
 *  shader.cpp
 *  openFrameworks
 */

#include "shader.h"

//--------------------------------------------------------------
void shader::setup(int fboW, int fboH){

	ofBackground(255,255,255);
	ofSetVerticalSync(true);

	fbo.allocate(fboW, fboH, true);

	fbo.clear(0,0,0,0);

	masker.loadShader("shaders/mask");

}

//--------------------------------------------------------------
void shader::beginRender(){
	fbo.swapIn();
	fbo.setupScreenForMe();
}

//--------------------------------------------------------------
void shader::endRender(){
	fbo.swapOut();
	fbo.setupScreenForThem();
}

//--------------------------------------------------------------
void shader::setMaskParams(int minX, int maxX, int minY, int maxY){
	this->minX = minX;
	this->maxX = maxX;
	this->minY = minY;
	this->maxY = maxY;
	cout << "(" << this->minX << "," << this->minY << ") (" << this->maxX << "," << this->maxY << ")" << endl;
}

//--------------------------------------------------------------
void shader::draw(float x, float y, float w, float h, bool useShader){

	ofxFBOTexture * fbop;
	fbop = &fbo;

	if( useShader ){
		// TODO
		ofEnableAlphaBlending();

		ofSetColor(255, 255, 255, 255);
		masker.setShaderActive(true);	// all subsequent draws will go through shader pipeline

		masker.setUniformVariable1i("minX", this->minX);
		masker.setUniformVariable1i("minY", this->minY);
		masker.setUniformVariable1i("maxX", this->maxX);
		masker.setUniformVariable1i("maxY", this->maxY);

		fbop->draw(x, y, w, h);	// all fbo's are swapped out, so this draw goes to actual screen now

		masker.setShaderActive(false);

		ofDisableAlphaBlending();
	}
}



