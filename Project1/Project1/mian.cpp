#include "FrameBuffer.h"
#include "sourceData.h"

using namespace std;
using namespace cv;
int frame_count = 0;

int draw_mode = 0; // mode = 0 represent wireframe mode, and 1 represent full rendering

int main()
{
    int key = 0;
    FrameBuffer f = FrameBuffer::FrameBuffer(800,800);
    
    f.loadData(vertices, index, 3 * 6, 1);
    
    while (key != 27)
    {
        float t_front = (double)getTickCount();
        f.draw(draw_mode);
        //cv::Mat image(800, 800, CV_32FC3, f.frame_buffer().data());
        //line(image, p1, p2, Scalar(0, 0, 255), 1);
        //imshow("soft render", image);
        key = waitKey(1);
        float t_now = ((double)getTickCount() - t_front) / getTickFrequency();
        float fps = 1.0 / t_now;
        std::cout << "Fps: " << fps << '\n';
    }
    return 0;
}  