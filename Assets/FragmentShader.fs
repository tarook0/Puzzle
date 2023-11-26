#version 330
uniform sampler2D albedo;
out vec4 color;
in vec2 pos_model_out;
void main(){
  vec2 uv=(pos_model_out+vec2(1,1))/2.0;
  color=texture(albedo,uv);
}
