#ifndef XOR_CODER_H
#define XOR_CODER_H

#include"coder.h"
#include<vector>
using Keys = std::vector< std::vector<int>>;
class XOR_Coder : public Coder
{
public:

    XOR_Coder(cv::Mat image);
    void code()override;
    void decode()override;
    ~XOR_Coder() = default;
    void save_keys(const std::string &path);
    void load_keys(const std::string &path);
    void set_keys(Keys && keys_);
    void setImage(cv::Mat &image);
private:
    void code_part_image(size_t pos_starti,size_t pos_startj,size_t end_i,size_t end_j);
    void generate_keys();

private:
    std::mt19937 gen;
    Keys keys;
};

#endif // XOR_CODER_H
