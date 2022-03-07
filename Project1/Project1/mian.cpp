#include "FrameBuffer.h"
#include <opencv2/opencv.hpp>
#include "sourceData.h"

using namespace std;
using namespace cv;
int frame_count = 0;
int main()
{
    int key = 0;
    FrameBuffer f = FrameBuffer::FrameBuffer(800,800);
    f.setPoint(400, 400, glm::vec3{ 1.0f, 0.0f, 0.0f });
    while (key != 27)
    {
        cv::Mat image(800, 800, CV_32FC3, f.frame_buffer().data());
        imshow("soft render", image);
        std::cout << "frame count: " << frame_count++ << '\n';
        key = waitKey(1);
    }
    return 0;
}