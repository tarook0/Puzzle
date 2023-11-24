#pragma once
#include<vector>
#include<Tile.h>
#include<GL/glew.h>
#define WINDOW_SIDE 650
#define GRID Grid::instance()
enum Uniforms
{
    X,
    Y,
    POINT_SIZE,
    SIZE_FACTOR,
    UNIFORM_NUM
};
class Grid
{
private:
    Grid();
    std::vector<char> readBinFile(const char *path);
    GLuint loadShaderProgram(const char *vertexShaderPath, const char *fragmentShaderPath);
    std::vector<Tile> tiles;
    GLuint shaderProgram;
    float tileSideSize;
    int horizontalTilesCount, verticalTilesCount;

public:
    static Grid &instance();
    void init();
    void solve();
    void draw();
    GLuint textures[Tile::NUM_TYPES];
    GLint uniformsLocations[Uniforms::UNIFORM_NUM];
};
