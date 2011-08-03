/*
 *	shader.h
 *	openFrameworks
 *
 *	Wrapper around ofxShader addon and ofxFBOTexture addon.
 *
 *
 */

#include "ofMain.h"
#include "ofxShader.h"
#include "ofxFBOTexture.h"

class shader{

	public:
		void setup(int fboW, int fboH);

		void beginRender();
		void endRender();

		void setMaskParams(int, int, int, int);
		void draw(float x, float y, float w, float h, bool useShader);

		ofxShader masker;

		ofxFBOTexture fbo;

		int minX, maxX, minY, maxY;

//		float blurDistance;
//		int noPasses;
};
