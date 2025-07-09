#include <lux.h>

int main()
{
    lx_window* window = lx_window_create((lx_window_properties){
        .title = "Kansei",
        .width = 1920,
        .height = 1080,
        .on_resize = NULL 
    });

    unsigned int default_shader = lx_shader_create((lx_shader_properties){
        .vertex_file = "default.vert",
        .fragment_file = "default.frag"
    }); 

    float vertices[] = {
        -0.5f, -0.5f, -0.5f,    0.0f, 0.0f, 0.0f, 
        0.5f, -0.5f, -0.5f,     1.0f, 0.0f, 0.0f,
        0.5f, 0.5f, -0.5f,      0.0f, 1.0f, 0.0f,
        -0.5f, 0.5f, -0.5f,     0.0f, 0.0f, 1.0f,
        -0.5f, -0.5f, 0.5f,     1.0f, 1.0f, 0.0f,
        0.5f, -0.5f, 0.5f,      1.0f, 0.0f, 1.0f,
        0.5f, 0.5f, 0.5f,       0.0f, 1.0f, 1.0f,
        -0.5f, 0.5f, 0.5f,      1.0f, 1.0f, 1.0f
    };

    unsigned int indices[] = {
        0, 1, 2,
        2, 3, 0,
        4, 5, 6,
        6, 7, 4,
        0, 3, 7,
        7, 4, 0,
        1, 5, 6,
        6, 2, 1,
        0, 1, 5,
        5, 4, 0,
        3, 2, 6,
        6, 7, 3
    };

    unsigned int vao;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    unsigned int vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    unsigned int ebo;
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glEnable(GL_DEPTH_TEST);

    while (lx_window_is_alive(window))
    {
        lx_window_update(window);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glUseProgram(default_shader);
        
        lx_mat4 model = lx_mat4_identity();
        lx_mat4 view = lx_mat4_identity();
        lx_mat4 projection = lx_mat4_perspective(45.0f, (float)lx_window_get_width(window)/(float)lx_window_get_height(window), 0.1f, 100.0f);
        model = lx_mat4_translate(model, (lx_vec3){ 0.0f, 0.0f, -3.0f });
        model = lx_mat4_rotate(model, (lx_vec3){ 0.0f, 1.0f, 0.0f }, 45.0f * lx_window_get_time_elapsed(window));

        int model_loc = glGetUniformLocation(default_shader, "model");
        glUniformMatrix4fv(model_loc, 1, GL_FALSE, model.m);
        int view_loc = glGetUniformLocation(default_shader, "view");
        glUniformMatrix4fv(view_loc, 1, GL_FALSE, view.m);
        int projection_loc = glGetUniformLocation(default_shader, "projection");
        glUniformMatrix4fv(projection_loc, 1, GL_FALSE, projection.m);

        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

        lx_window_swap_buffers(window);
    }

    lx_window_destroy(window);
    
    return 0;
}
