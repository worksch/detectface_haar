#include <stdio.h>

#include <string>
#include <regex>

#ifdef _WIN32
#include <direct.h>
#elif __linux
#include <unistd.h>
#endif

/// Opencv
#include <opencv2/opencv.hpp>

#define CV_COLOR_RED cv::Scalar(0, 0, 255)

using namespace std;

#ifdef _W64
#define FRONTALFACE_ALT2    "\\haarcascade\\haarcascade_frontalface_alt2.xml"
#elif __linux
#define FRONTALFACE_ALT2    "/haarcascade/haarcascade_frontalface_alt2.xml"
#endif


int main(int argc, char** argv)
{

    char path_buffer[256] = "";
    getcwd(path_buffer, sizeof(path_buffer));

    std::string path_string = std::string(path_buffer);
    path_string = path_string+FRONTALFACE_ALT2;

#ifdef _WIN32
    //path_string.replace("\\", "\\\");
    while (1) {
        int pos = path_string.find('\\');
        if (pos == -1)
            break;
        printf("%d\n", pos);
        path_string.replace(pos, 1, "/");
    }
#endif
    std::cout << path_string << std::endl;

    cv::CascadeClassifier faceDetector(path_string);

    cv::VideoCapture capture;
    if (!capture.open(0)) {
        return -1;
    }

    while (1) {
        cv::Mat frame;

        if (!capture.read(frame)) {
            break;
        }

        std::vector<cv::Rect> objects;
        faceDetector.detectMultiScale(frame, objects);
        for (int i = 0; i < objects.size(); i++)
        {
            cv::rectangle(frame, objects[i], CV_COLOR_RED);
        }
        cv::imshow("result", frame);
        cv::waitKey(30);
    }


    return 0;
}
