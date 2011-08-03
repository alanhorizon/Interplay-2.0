#extension GL_ARB_texture_rectangle : enable
// shader requires sampler to get pixel data; just need to declare, no need to initialize.
uniform sampler2DRect src_tex_unit0;
//uniform float blurAmnt;

// uniform variables passed in from application
uniform int minX, maxX, minY, maxY;
//uniform int r, g, b;

/**
  * draws transparent rectangle with diagonals (minX, minY) and (maxX, maxY):
  * checks if pixel location is within this range, sets transparent if so,
  * returns the pixel untouched if not.
  */
void main(void)	// main function executed for every single pixel
{
	// TexCoord[0] is the first (and only in this case) texture/frame we're dealing with
	// see opengl shaders reference for various component accessors: rgba, stpq, xyzw
	int s = int(gl_TexCoord[0].s);
	int t = int(gl_TexCoord[0].t); // get pixel/texel coordinates
	int g = int(gl_Color[2]);
	vec2 st = gl_TexCoord[0].st;

	vec4 rgba = texture2DRect(src_tex_unit0, st); // get pixel data

//	 check if in certain area.
	if (s >= minX && s <= maxX && t >= minY && t <= maxY){
		rgba[3] = 0.0;
	}

//	if (rgba[0] > .5){
//		rgba[3] = 0.0;
//	}

	gl_FragColor = rgba;
}
