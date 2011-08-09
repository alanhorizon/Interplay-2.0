uniform sampler2D tex1;
uniform sampler2D tex2;
varying vec2  TexCoord;
uniform float pan;
void main(void)
{
   // get texture info
   vec4 v1 = texture2D(tex1, TexCoord);
   vec4 v2 = texture2D(tex2, TexCoord);
   gl_FragColor =  vec4(mix(v1, v2, pan).rgb, 1.0);
}