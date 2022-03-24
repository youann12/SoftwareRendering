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

    Scene scene;
    scene.bindFramebuffer(&f);

    m.loadData(vertices, index, 3 * 6, 1);
    
    scene.loadMesh(m, glm::vec3{0, 0, 0});
    
    shader.setView(0, 0, 800, 800);
    while (key != 27)
    {
        float t_front = (double)getTickCount();
        
        scene.draw(draw_mode);
        
        key = waitKey(1);
        float t_now = ((double)getTickCount() - t_front) / getTickFrequency();
        float fps = 1.0 / t_now;
        std::cout << "Fps: " << fps << '\n';
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