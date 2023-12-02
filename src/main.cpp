#include <SFML/Window.hpp>
#include <Grid.h>
#include <vector>
#include <string>
#include <iostream>
using namespace sf;
int main(int argc, char *argv[])
{
    for ( int i = 1 ; i < argc ; i++){
        std::string tmp (argv[i]);
        GRID.InputArrinit(tmp) ;
    }
    if(argc!=10){
        return 0;
    }
    else{
    ContextSettings ctxSettings{};
    ctxSettings.antialiasingLevel = 0;
    ctxSettings.depthBits = 0;
    ctxSettings.majorVersion = 4;
    ctxSettings.minorVersion = 0;
    ctxSettings.sRgbCapable = false;
    ctxSettings.stencilBits = 0;
    Window window(VideoMode(WINDOW_SIDE, WINDOW_SIDE), "Puzzle", 7U, ctxSettings);
    glewExperimental = true;
    glewInit();
    
    GRID.init();
    GRID.selectedTileCordinateInit();
    GRID.draw();
    GRID.initvectorSol();
    window.display();
    bool solved = false;
    while (1)
    {
        Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case Event::Closed:
                return 0;
                break;
            case Event::EventType::KeyPressed:
                if (event.key.code == Keyboard::Escape)
                {
                    return false;
                }
                if (event.key.code == Keyboard::W)
                {
                   GRID.winCheck();
                    GRID.player(Grid::Destination::up);
                }
                if (event.key.code == Keyboard::S)
                {
                    GRID.winCheck();
                    GRID.player(Grid::Destination::down);
                }
                if (event.key.code == Keyboard::D)
                {
                    GRID.winCheck();
                    GRID.player(Grid::Destination::right);
                }
                if (event.key.code == Keyboard::A)
                {
                    GRID.winCheck();
                    GRID.player(Grid::Destination::left);
                }
                 if (event.key.code == Keyboard::R)
                {
                    GRID.
                     GRID.init();
                     GRID.selectedTileCordinateInit();
                   
                }
            default:
                break;
            }
        }
        GRID.winCheck();
        GRID.draw();
        window.display();
    }
    }
}