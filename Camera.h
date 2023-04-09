#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QImage>

class CamWidget:public QWidget
{
    Q_OBJECT
public:
    explicit CamWidget(QWidget *parent=nullptr);
    ~CamWidget(); 
private:
    QLabel *m_label;
    QPushButton* button;

public slots:
    void filter();
};
#endif