#pragma once

#include <lux.h>

namespace core
{
    class Application
    {
    private:
        lx_window* m_window;

    public:
        Application(const char* title, int width, int height, bool debug);
        ~Application();
    
        void Update();
        void Render();

        double GetDeltaTime();
        int GetFps();
        bool IsAlive();
    };
}
