#pragma once
#include <GL/glew.h>
#include <Tile.h>
#include <vector>
#include <string>
#define WINDOW_SIDE 650
#define GRID Grid::instance()
enum Uniforms { X, Y, POINT_SIZE, SIZE_FACTOR, UNIFORM_NUM };
class Grid {
private:
  Grid();
  std::vector<char> readBinFile(const char *path);
  GLuint loadShaderProgram(const char *vertexShaderPath,
                           const char *fragmentShaderPath);
  std::vector<Tile> tiles;
  GLuint shaderProgram;
  float tileSideSize;
  int horizontalTilesCount, verticalTilesCount;
  std::vector<std::string> inputArr;

public:
  static Grid &instance();
  enum Destination {
    up,
    down,
    left,
    right,
  };
  struct {
    int x;
    int y;
    int i;
  } cordinate;
  void init();

  void InputArrinit(std::string element);
  void selectedTileCordinateInit();
  void player(Destination des);
  void draw();
  void winCheck();
  void initvectorSol();
  std::vector<Tile> solution;
  GLuint textures[Tile::NUM_TYPES];
  GLint uniformsLocations[Uniforms::UNIFORM_NUM];
};
