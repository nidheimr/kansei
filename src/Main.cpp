#include "core/Application.hpp"

int main()
{
    core::Application* app = new core::Application("Kansei", 1920, 1080, true);

    while (app->IsAlive())
    {
        app->Update();
        app->Render();

        lx_debug("fps: %d, delta: %lf", app->GetFps(), app->GetDeltaTime());
    }

    delete app;
    return 0;
}
