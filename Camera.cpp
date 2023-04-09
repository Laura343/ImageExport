#include "Camera.h"
#include "imageToQImage.h"
#include "functionFilter.h"
#include "imageToMat.h"

#include <QVBoxLayout>
#include <QPixmap>

CamWidget::CamWidget(QWidget *parent)
    : QWidget(parent)
{
    // Create a label to display the camera stream
    m_label = new QLabel(this);
    m_label->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_label->setAlignment(Qt::AlignCenter);

    // QImage image("C:/Users/hovha/Downloads/image2.jpg");
    // QPixmap pixmap = QPixmap::fromImage(image);
    // m_label->setPixmap(pixmap);


    //N1 
    // cv::Mat mat = cv::imread("C:/Users/hovha/Downloads/image2.jpg");
    // Image img=MatToImage(mat);
    // QImage image=ImageToQImage(img);
    // QPixmap pixmap = QPixmap::fromImage(image);
    // m_label->setPixmap(pixmap);//ashxatox

    //N2
    // QImage image("C:/Users/hovha/Downloads/funny.jpg");
    // Image img=QImageToImage(image);
    // cv::Mat mat=ImageToMat(img);
    // img=MatToImage(mat);
    // image=ImageToQImage(img);
    // QPixmap pixmap = QPixmap::fromImage(image);
    // m_label->setPixmap(pixmap);//chashxatox

    //N3
    // QImage image("C:/Users/hovha/Downloads/funny.jpg");
    // Image img=QImageToImage(image);
    // image=ImageToQImage(img);
    // QPixmap pixmap = QPixmap::fromImage(image);
    // m_label->setPixmap(pixmap);//chashxatox
    
    button=new QPushButton("Image");

    // Create a layout to position the label within the widget
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(m_label);
    layout->addWidget(button);

    connect(button,SIGNAL(clicked()),this,SLOT(filter()));
}


CamWidget::~CamWidget() 
{
}

void CamWidget::filter()
{
    QImage image("C:/Users/hovha/Downloads/funny.jpg");
    Image img=QImageToImage(image);
    //fun(img);
    image=ImageToQImage(img);
    QPixmap pixmap = QPixmap::fromImage(image);

    // QImage image("C:/Users/hovha/Downloads/funny.jpg");
    //     // Create a QPixmap from the QImage
    // QPixmap pixmap = QPixmap::fromImage(image);

     // Set the QPixmap as the pixmap for the label
    m_label->setPixmap(pixmap);
}
