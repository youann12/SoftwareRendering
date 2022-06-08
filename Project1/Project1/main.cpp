//#include "FrameBuffer.h"
#include "sourceData.h"
#include "Scene.h"
#include "Camera.h"


using namespace std;
using namespace cv;

int frame_count = 0;
int draw_mode = 1; // mode = 0 represent wireframe mode, and 1 represent full rendering
Camera camera(glm::vec3(0.0f, 0.0f, 5.0f)); 

void keyboardEvent(int key);
void OnMouse(int event, int x, int y, int flags, void* ustc);

float lastX = 400, lastY = 400;

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
    
        glm::mat4 sCamView = camera.GetViewMatrix();
        shader.setCameraView(sCamView);

        shader.setModel(glm::vec3{ 0.0f, 0.0f, 0.0f }, glm::vec3{ 1.0f, 1.0f, 1.0f }, glm::radians(angle), glm::vec3{ 0.0f, 0.5f, 0.5f});
        
        scene.draw(draw_mode);
        angle += 50.0f;

        key = waitKey(1);
        setMouseCallback("soft render", OnMouse);
        float t_now = ((double)getTickCount() - t_front) / getTickFrequency();
        float fps = 1.0 / t_now;
        std::cout << "Fps: " << fps << '\n';
        //std::cout << "angle: " << angle << '\n';
        //std::cout << "key: " << key << '\n';
        keyboardEvent(key);
    }
    return 0;
}  

void keyboardEvent( int key )
{

    if (key == Key_R)
        draw_mode = 1;
    if (key == Key_F)
        draw_mode = 0;
    if (key == Key_W)
        camera.ProcessKeyboard(W, 0.016);
    if (key == Key_A)
        camera.ProcessKeyboard(A, 0.016);
    if (key == Key_S)
        camera.ProcessKeyboard(S, 0.016);
    if (key == Key_D)
        camera.ProcessKeyboard(D, 0.016);

}

void OnMouse(int event, int x, int y, int flags, void* ustc)
{

    if (event == CV_EVENT_MOUSEMOVE)
    {
        float xoffset = x - lastX;
        float yoffset = lastY - y;
        lastX = x;
        lastY = y;
        camera.MoveMouse(xoffset, yoffset);
    } 

}

