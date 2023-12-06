#version 330
layout(location=0) in vec2 pos_model;
out vec2 pos_model_out;
uniform int x,y;
void main(){
  pos_model_out=pos_model;
  mat4 scale=mat4(0.333);
  scale[3][3]=1;
  mat4 translate=mat4(1.0);
  translate[3][0]=(y-2)*0.666;
  translate[3][1]=(2-x)*0.666;
  gl_Position=translate*scale*vec4(pos_model,0,1);
}
