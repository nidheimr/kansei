#include "core/Application.hpp"

int main()
{
    core::Application* app = new core::Application("Kansei", 1920, 1080, true);

    while (app->IsAlive())
    {
        app->Update();

        lx_print("fps: %d, delta: %lf", app->GetFps(), app->GetDeltaTime());

        app->Render();
    }

    delete app;
    return 0;
}
