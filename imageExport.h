#ifndef IMAGE_H
#define IMAGE_H

struct Image{

    int  rows;
    int  cols;
    unsigned char*  data;
    int step;

    Image(int r,int c ,unsigned char* d,int s)
        :rows(r),cols(c),data(d),step(s){}

};
#endif








 	

