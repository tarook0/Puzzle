#version 330
layout(location=0) in vec2 pos_model;
out vec2 pos_model_out;
uniform int x,y;
uniform float size;
uniform float sizeFactor;
void main(){
  pos_model_out=pos_model;
  gl_Position=vec4(pos_model.x*size-size/2.0-1,pos_model.y*size-size/2.0-1,0.0,1.0);
}
