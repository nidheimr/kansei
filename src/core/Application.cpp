#include "Application.hpp"

#include <lux.h>

namespace core
{
    Application::Application(const char* title, int width, int height, bool debug)
    {
        lx_enable_debug_messages(debug);
        lx_print_error_on_occurance(debug);

        m_window = lx_window_create(title, width, height);
        m_shader = lx_shader_create("default.vert", "default.frag");
    }
    
    Application::~Application()
    {
        lx_shader_destroy(m_shader);
        lx_window_destroy(m_window);
    }

    void Application::Update()
    {
        lx_window_update(m_window);
        lx_shader_use(m_shader);

        if (lx_key_is_down(LX_KEY_A))
            lx_shader_test(m_shader);
    }
    
    void Application::Render()
    {
        lx_window_render(m_window);
    }

    double Application::GetDeltaTime()
    {
        return lx_window_get_delta_time(m_window);
    }

    int Application::GetFps()
    {
        return lx_window_get_fps(m_window);
    }

    bool Application::IsAlive()
    {
        return lx_window_is_alive(m_window);
    }
}
