#include "imageToQImage.h"

QImage ImageToQImage(Image& img)  // stanum enq struktura u darcnum QImage
{
    QImage image(img.data, img.cols, img.rows, img.step, QImage::Format_BGR888);
    return image;
}

Image QImageToImage(QImage& image) //stanum enq QImage darcnum enq Image
{
    Image img(image.height(),image.width(),image.bits(),image.bytesPerLine());
    return img;
}//thiiis
