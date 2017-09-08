#ifndef CODER_H
#define CODER_H

#include<opencv2/opencv.hpp>
#include<memory>

class Coder
{
public:
    Coder() = default;
    Coder(cv::Mat image_);
    virtual void code() = 0;
    virtual void decode() = 0;
    /*
    inline cv::Mat&& get_image()
    {
        return std::move(image);
    }
    */
    inline cv::Mat get_image()
    {
        return image;
    }
    virtual ~Coder(){}
protected:
    //std::unique_ptr<cv::Mat> image;
    cv::Mat image;
};

#endif // CODER_H
