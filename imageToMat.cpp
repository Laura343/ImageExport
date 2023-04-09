#include "imageToMat.h"

cv::Mat ImageToMat(Image& img) // stanum enq struktura u darcnum Mat
{
    cv::Mat mat(img.rows,img.cols,CV_8UC4,img.data,img.step);
    return mat;
}

Image MatToImage(cv::Mat& mat) //stanum enq Mat darcnum enq Image
{
    Image img(mat.rows,mat.cols,mat.data,mat.step);
    return img;
}

