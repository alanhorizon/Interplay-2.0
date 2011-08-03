// standard code for vertex shader that does nothing; simply passes to fragment shader.
void main() {
	gl_TexCoord[0] = gl_MultiTexCoord0;
	gl_Position = ftransform();
}
