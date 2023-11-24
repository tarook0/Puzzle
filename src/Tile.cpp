#include <Tile.h>
#include<Grid.h>
Tile::Tile(int x, int y,Type type) : x(x), y(y),type(type)
{
    update();
}
void Tile::draw(){
    glUniform1i(GRID.uniformsLocations[Uniforms::X], x);
    glUniform1i(GRID.uniformsLocations[Uniforms::Y], y);
    glBindTexture(GL_TEXTURE_2D, GRID.textures[type]);
    glDrawArrays(GL_POINTS, 0, 1);
    assert(glGetError() == 0);
}
void Tile::update(){
}
