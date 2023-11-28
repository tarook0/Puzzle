#include <Grid.h>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <fstream>

using namespace std;
using namespace sf;
using namespace glm;
Grid::Grid() {}
Grid &Grid::instance() {
  static Grid grid;
  return grid;
}
void Grid::init() {
  glClearColor(0, 0, 0, 1);
  glEnable(GL_PROGRAM_POINT_SIZE);
  glDisable(GL_CULL_FACE);
  glActiveTexture(GL_TEXTURE0);
  horizontalTilesCount = 3;
  verticalTilesCount = 3;

  if (horizontalTilesCount > verticalTilesCount) {
    tileSideSize = 2.0f / (float)horizontalTilesCount;
  } else {
    tileSideSize = 2.0f / (float)verticalTilesCount;
  }
  for (int i = 0; i < horizontalTilesCount; ++i) {
    for (int j = 0; j < verticalTilesCount; ++j) {
      tiles.push_back(
          Tile(i + 1, j + 1, (Tile::Type)(i * verticalTilesCount + j)));
    }
  }

  // Load textures
  Image images[Tile::NUM_TYPES];
  images[Tile::TILE_1].loadFromFile("./Assets/tile_1.png");
  images[Tile::TILE_2].loadFromFile("./Assets/tile_2.png");
  images[Tile::TILE_3].loadFromFile("./Assets/tile_3.png");
  images[Tile::TILE_4].loadFromFile("./Assets/tile_4.png");
  images[Tile::TILE_5].loadFromFile("./Assets/tile_5.png");
  images[Tile::TILE_6].loadFromFile("./Assets/tile_6.png");
  images[Tile::TILE_7].loadFromFile("./Assets/tile_7.png");
  images[Tile::TILE_8].loadFromFile("./Assets/tile_8.png");
  images[Tile::VOID].loadFromFile("./Assets/void.png");
  images[Tile::TILE_1].flipVertically();
  images[Tile::TILE_2].flipVertically();
  images[Tile::TILE_3].flipVertically();
  images[Tile::TILE_4].flipVertically();
  images[Tile::TILE_5].flipVertically();
  images[Tile::TILE_6].flipVertically();
  images[Tile::TILE_7].flipVertically();
  images[Tile::TILE_8].flipVertically();
  images[Tile::VOID].flipVertically();

  for (int i = 0; i < Tile::NUM_TYPES; ++i) {
    glGenTextures(1, &textures[i]);
    glBindTexture(GL_TEXTURE_2D, textures[i]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTextureParameteri(textures[i], GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTextureParameteri(textures[i], GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, images[i].getSize().x,
                 images[i].getSize().y, 0, GL_RGBA, GL_UNSIGNED_BYTE,
                 images[i].getPixelsPtr());
  }
  glBindTexture(GL_TEXTURE_2D, 0);
  shaderProgram =
      loadShaderProgram("Assets/VertexShader.vs", "Assets/FragmentShader.fs");
  assert(glGetError() == 0);
  glUseProgram(shaderProgram);
  uniformsLocations[Uniforms::X] = glGetUniformLocation(shaderProgram, "x");
  uniformsLocations[Uniforms::Y] = glGetUniformLocation(shaderProgram, "y");
  uniformsLocations[Uniforms::POINT_SIZE] =
      glGetUniformLocation(shaderProgram, "size");
  uniformsLocations[Uniforms::SIZE_FACTOR] =
      glGetUniformLocation(shaderProgram, "sizeFactor");
  glUniform1f(uniformsLocations[Uniforms::SIZE_FACTOR],
              (float)WINDOW_SIDE * 0.48828125f);
  glUniform1f(uniformsLocations[Uniforms::POINT_SIZE], tileSideSize);
  Tile::init();
  assert(glGetError() == 0);
}
void Grid::draw() {
  glClear(GL_COLOR_BUFFER_BIT);
  for (Tile tile : tiles) {
    tile.draw();
  }
  assert(glGetError() == 0);
}
void Grid::selectedTilecordinateInit() {
  for (int i = 0; i < tiles.size(); i++) {
    if (tiles[i].type == Tile::VOID) {
      cordinate.x = tiles[i].x;
      cordinate.y = tiles[i].y;
      cordinate.i=i;
    }
  }
}

void Grid::solve(Destination des) {
  // up
  if ((des == Destination::up) && cordinate.y != 3) {
    tiles[cordinate.i].type=tiles[cordinate.i+1].type;
    tiles[cordinate.i+1].type=Tile::VOID;
    cordinate.i++;
    cordinate.y++;
  }
  // down
  if ((des == Destination::down) && cordinate.y != 1) {
    tiles[cordinate.i].type=tiles[cordinate.i-1].type;
    tiles[cordinate.i-1].type=Tile::VOID;
    cordinate.i--;
    cordinate.y--;
  }
  // left
  if ((des == Destination::left) && cordinate.x != 1) {
    tiles[cordinate.i].type=tiles[cordinate.i-3].type;
    tiles[cordinate.i-3].type=Tile::VOID;
    cordinate.i-=3;
    cordinate.x--;
  }
  // right
  if ((des == Destination::right) && cordinate.x != 3) {
    tiles[cordinate.i].type=tiles[cordinate.i+3].type;
    tiles[cordinate.i+3].type=Tile::VOID;
    cordinate.i+=3;
    cordinate.x++;
  }
}

GLuint Grid::loadShaderProgram(const char *vertexShaderPath,
                               const char *fragmentShaderPath) {
  GLuint program;
  vector<char> vertexShaderCode = readBinFile(vertexShaderPath);
  vector<char> fragmentShaderCode = readBinFile(fragmentShaderPath);
  GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
  GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
  GLint vertexShaderSize = vertexShaderCode.size();
  GLint fragmentShaderSize = fragmentShaderCode.size();
  char *pVertexShaderCode = vertexShaderCode.data();
  char *pFragmentShaderCode = fragmentShaderCode.data();
  glShaderSource(vertexShader, 1, &pVertexShaderCode, &vertexShaderSize);
  glShaderSource(fragmentShader, 1, &pFragmentShaderCode, &fragmentShaderSize);
  glCompileShader(vertexShader);
  glCompileShader(fragmentShader);
#ifdef DEBUG
  GLint infoLogLen;
  glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &infoLogLen);
  vector<char> infoLog(infoLogLen);
  glGetShaderInfoLog(vertexShader, infoLog.size(), nullptr, infoLog.data());
  infoLog.push_back('\0');
  printf(infoLog.data());
  infoLog.resize(0);
  glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &infoLogLen);
  infoLog.resize(infoLogLen);
  glGetShaderInfoLog(fragmentShader, infoLog.size(), nullptr, infoLog.data());
  infoLog.push_back('\0');
  printf(infoLog.data());
  infoLog.resize(0);
#endif
  program = glCreateProgram();
  glAttachShader(program, vertexShader);
  glAttachShader(program, fragmentShader);
  glLinkProgram(program);
#ifdef DEBUG
  glGetProgramiv(program, GL_INFO_LOG_LENGTH, &infoLogLen);
  infoLog.resize(infoLogLen);
  glGetProgramInfoLog(program, infoLogLen, nullptr, infoLog.data());
  infoLog.push_back('\0');
  printf(infoLog.data());
#endif
  glDetachShader(program, vertexShader);
  glDetachShader(program, fragmentShader);
  glDeleteShader(vertexShader);
  glDeleteShader(fragmentShader);

  assert(glGetError() == 0);
  return program;
}

vector<char> Grid::readBinFile(const char *path) {
  vector<char> data;
  fstream fileStream(path, ios::binary | ios::ate | ios::in);
  if (!fileStream.is_open()) {
    printf("Failed to open file at %s", path);
    assert(0);
  }
  data.resize(fileStream.tellg());
  fileStream.seekg(0, ios::beg);
  fileStream.read(data.data(), data.size());
  fileStream.flush();
  fileStream.close();
  return data;
}
