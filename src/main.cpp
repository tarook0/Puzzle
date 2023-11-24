#include <SFML/Window.hpp>
#include <Grid.h>
using namespace sf;
int main(int argc, char **argv)
{
    ContextSettings ctxSettings{};
    ctxSettings.antialiasingLevel = 0;
    ctxSettings.depthBits = 0;
    ctxSettings.majorVersion = 4;
    ctxSettings.minorVersion = 0;
    ctxSettings.sRgbCapable = false;
    ctxSettings.stencilBits = 0;
    Window window(VideoMode(WINDOW_SIDE, WINDOW_SIDE), "Akari", 7U, ctxSettings);
    glewExperimental=true;
    glewInit();
    GRID.init();
    GRID.draw();
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
            case Event::KeyPressed:
                if (event.key.code == Keyboard::Space && !solved)
                {
                    GRID.solve();
                }
            default:
                break;
            }
        }
        GRID.draw();
        window.display();
    }
}
