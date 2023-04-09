#include "functionFilter.h"

void fun(Image& img){
    cv::Mat mat=ImageToMat(img);
    if (mat.empty())
    {
        std::cout << "Could not open or find the image" << std::endl;
        return;
    }
    cv::Mat noise = cv::Mat::zeros(mat.size(), mat.type());
    randn(noise, cv::Scalar::all(0), cv::Scalar::all(50)); // mean=0, SD=50
    mat+=noise;

    img=MatToImage(mat);
}