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

void makeGray(Image&  image){
    cv::Mat mat=ImageToMat(image);
    cv::cvtColor(mat, mat, 6);
    image=MatToImage(mat);
}

void blurImage(Image& image){
    cv::Mat mat=ImageToMat(image);
    cv::GaussianBlur(mat, mat, cv::Size(3, 3), 0);
    imshow("Original", mat);
    image=MatToImage(mat);
} 


void foo(Image& img ){
    cv::Mat mat=ImageToMat(img);
    if (mat.empty())
    {
        std::cout << "Could not open or find the image" << std::endl;
        return;
    }
    cv::Mat left_half = mat(cv::Rect(0, 0, mat.cols / 2, mat.rows));
    cv::Mat right_half = mat(cv::Rect(mat.cols / 2, 0, mat.cols / 2, mat.rows));
    cv::Mat blue_filter = cv::Mat::zeros(left_half.size(), left_half.type());
    blue_filter.setTo(cv::Vec3b(225, 0, 0));
    cv::Mat red_filter = cv::Mat::zeros(right_half.size(), right_half.type());
    red_filter.setTo(cv::Vec3b(0, 0, 225));
    cv::Mat blue_image;
    addWeighted(left_half, 0.5, blue_filter, 0.5, 0.0, blue_image);
    cv::Mat red_image;
    addWeighted(right_half, 0.5, red_filter, 0.5, 0.0, red_image);
    cv::Mat output_image(mat.size(), mat.type());
    cv::Mat left_roi(output_image, cv::Rect(0, 0, mat.cols / 2, mat.rows));
    blue_image.copyTo(left_roi);
    cv::Mat right_roi(output_image, cv::Rect(mat.cols / 2, 0, mat.cols / 2, mat.rows));
    red_image.copyTo(right_roi);
    img=MatToImage(output_image);
}