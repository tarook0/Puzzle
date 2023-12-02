#include <Tile.h>
#include<Grid.h>
GLuint Tile::VAO;

void Tile::init(){
    GLfloat vertices[]={-1,-1,1,-1,-1,1,-1,1,1,-1,1,1};
    
    GLuint VBO;
    glGenVertexArrays(1,&VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1,&VBO);
    glBindBuffer(GL_ARRAY_BUFFER,VBO);
    glBufferData(GL_ARRAY_BUFFER,6*2*sizeof(GLfloat),vertices,GL_STATIC_DRAW);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0,2,GL_FLOAT,GL_FALSE,0,(void*)0);
    
}

Tile::Tile(int x, int y,Type type) : x(x), y(y),type(type)
{
    update();
}
    void Tile::draw(){
        glUniform1i(GRID.uniformsLocations[Uniforms::X], x);
        glUniform1i(GRID.uniformsLocations[Uniforms::Y], y);
        glBindTexture(GL_TEXTURE_2D, GRID.textures[type]);
        glDrawArrays(GL_TRIANGLES,0,6);
        assert(glGetError() == 0);
    }
void Tile::update(){
}
