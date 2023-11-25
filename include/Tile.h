#pragma once
#include<assert.h>
#include<GL/glew.h>
class Tile{
    int x, y;
    int wallVal;
    static GLuint VAO;
public:
    enum Type
    {
        TILE_1,
        TILE_2,
        TILE_3,
        TILE_4,
        TILE_5,
        TILE_6,
        TILE_7,
        TILE_8,
        VOID,
        NUM_TYPES
    };
    Tile(int x, int y,Type type);
    Type type;
    void draw();
    void update();
    static void init();
};
