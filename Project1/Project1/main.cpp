//#include "FrameBuffer.h"
#include "sourceData.h"
#include "Scene.h"


using namespace std;
using namespace cv;
int frame_count = 0;

int draw_mode = 1; // mode = 0 represent wireframe mode, and 1 represent full rendering

int main()
{
    int key = 0;
    Shader shader = Shader();
    FrameBuffer f = FrameBuffer::FrameBuffer(800, 800, &shader);
    Mesh m;
    float angle = 0.0f;

    Scene scene(&f);

    m.loadData(boxs, indices, 8 * 8, 12 * 3);
    
    scene.loadMesh(m, glm::vec3{0, 0, 0});
    
    shader.setViewPort(0, 0, 800, 800);
    shader.setProjection(glm::radians(60.0f), (float)800 / 800, 0.3f, 100);
    shader.setView(glm::vec3(0, 0, 5), glm::vec3(0, 0, -1), glm::vec3(1, 0, 0), glm::vec3(0, 1, 0));
    
    
    Texture t;
    t.loadTexture("resource/container.jpg");

    int tex_width, tex_height, nrChannels;
    unsigned char* d = stbi_load("resource/container.jpg", &tex_width, &tex_height, &nrChannels, 0);

    int shaderInd = shader.addTexture(t);
    shader.useTexture(shaderInd);

    while (key != 27)
    {
        float t_front = (double)getTickCount();
        
        shader.setModel(glm::vec3{ 0.0f, 0.0f, 0.0f }, glm::vec3{ 1.0f, 1.0f, 1.0f }, glm::radians(angle), glm::vec3{ 0.0f, 0.5f, 0.5f});
        
        scene.draw(draw_mode);
        angle += 30.0f;

        key = waitKey(1);
        float t_now = ((double)getTickCount() - t_front) / getTickFrequency();
        float fps = 1.0 / t_now;
        std::cout << "Fps: " << fps << '\n';
        std::cout << "angle: " << angle << '\n';
        if (key == 114)
        {
            draw_mode = 1;
        }
        else if (key == 102)
        {
            draw_mode = 0;
        }
    }
    return 0;
}  