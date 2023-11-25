#version 330
uniform sampler2D albedo;
out vec4 color;
in vec2 pos_model_out;
void main(){
  color=texture(albedo,pos_model_out);
}
