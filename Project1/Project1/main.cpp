//#include "FrameBuffer.h"
#include "sourceData.h"
#include "FrameBuffer.h"

using namespace std;
using namespace cv;
int frame_count = 0;

int draw_mode = 0; // mode = 0 represent wireframe mode, and 1 represent full rendering

int main()
{
    int key = 0;
    Shader shader = Shader();
    FrameBuffer f = FrameBuffer::FrameBuffer(800, 800, &shader);

    
    f.loadData(vertices, index, 3 * 6, 1);
    while (key != 27)
    {
        float t_front = (double)getTickCount();
        
        f.draw(draw_mode);
        
        key = waitKey(1);
        float t_now = ((double)getTickCount() - t_front) / getTickFrequency();
        float fps = 1.0 / t_now;
        std::cout << "Fps: " << fps << '\n';
    }
    return 0;
}  