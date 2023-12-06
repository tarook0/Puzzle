#version 330
uniform sampler2D albedo;
out vec4 color;
in vec2 pos_model_out;
void main(){
  vec2 uv=(pos_model_out+vec2(1,1))/2.0;
  color=vec4 (0.870588f, 0.721569f, 0.529412f,1.0f)*texture(albedo,uv);
}
