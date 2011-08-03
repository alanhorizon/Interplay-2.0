#extension GL_ARB_texture_rectangle : enable
// req'd for sampler2DRect and texture2DRect
// By default, openFrameworks uses rectangular NPOT textures

uniform sampler2DRect src_tex_unit0;
// shader requires sampler to get pixel data; just need to declare, no need to initialize.

// uniform variables passed in from application:
uniform int minX, maxX, minY, maxY;
//uniform int r, g, b;

/**
  * Sample single texture fragment (pixel) shader:
  * Draws transparent rectangle with diagonals at (minX, minY) and (maxX, maxY).
  *
  * Checks if pixel location is within defined rectangle.
  * If so, set pixel's alpha to 0.0 (transparent), do nothing otherwise.
  *
  */
void main(void)	// main function executed for every single pixel
{
	// Get texture coordinates
	int s = int(gl_TexCoord[0].s);
	int t = int(gl_TexCoord[0].t);
	vec2 st = gl_TexCoord[0].st;
	/*
	 * TexCoord[0]: first (and only) texture coordinates of current pixel
	 * Of type vec4.
	 *
	 * see opengl shaders reference for various component accessors: rgba, stpq, xyzw
	 * http://www.opengl.org/discussion_boards/ubbthreads.php?ubb=showflat&Number=222050
	 * see section 5.5 "Vector Components" of GLSL Spec:
	 * http://www.opengl.org/registry/doc/GLSLangSpec.Full.1.20.8.pdf
	 *
	 * In a nutshell, first two elements of vector is the texel's x,y coordinate.
	 * However, by convention, we refer to them as (s, t).
	 * vec4[0] == vec4.s == vec4.x == vec4.r;
	 *
	 * Can also access multiple components (but must use same "nameset"):
	 * vec4.st is a vec2 containing vec4[0] and vec4[1].
	 */

	vec4 rgba = texture2DRect(src_tex_unit0, st); // get pixel color data
	// Rectangular texture, coordinates st specified as pixel coordinates,
	// with ranges between width and height of texture map, not between 0.0 and 1.0
	// http://stackoverflow.com/questions/6735631/why-does-this-opengl-shader-use-texture-coordinates-beyond-1-0
	// note: each component's rgba sampled value is still between 0.0 and 1.0.

	// check if in defined rectangle
	if (s >= minX && s <= maxX && t >= minY && t <= maxY){
		rgba[3] = 0.0;	// set transparent
	}

	// more sample code: if red value is greater than threshold, set transparent:
//	if (rgba[0] > .5){
//		rgba[3] = 0.0;
//	}

	gl_FragColor = rgba;	// set gl_FragColor to final pixel data to "return"
}
