#include "xor_coder.h"
#include<fstream>
#include<ctime>
#include<random>
XOR_Coder::XOR_Coder(cv::Mat image):Coder(image)
{
    gen.seed(time(0));
}
void XOR_Coder::code()
{
    generate_keys();
    code_part_image(0,0,image.rows/2,image.cols/2);
    code_part_image(image.rows/2-1,image.cols/2-1,image.rows,image.cols);
}
void XOR_Coder::generate_keys()
{
    std::uniform_int_distribution<> diap(0,255);
    for(int i = 0;i<image.rows;++i)
    {
        std::vector<int> temp;
        for(int j = 0;j<image.cols;++j)
        {
            temp.push_back(diap(gen));

        }
        keys.emplace_back(std::move(temp));
    }
}
void XOR_Coder::decode()
{
    code_part_image(0,0,image.rows/2,image.cols/2);
    code_part_image(image.rows/2-1,image.cols/2-1,image.rows,image.cols);
}
void XOR_Coder::code_part_image(size_t pos_starti,size_t pos_startj,size_t end_i,size_t end_j)
{
    for(int i = pos_starti;i<end_i;++i)
    {
        for(int j = pos_startj;j<end_j;++j)
        {
            for(int r =  0;r<3;++r)
            {
                image.at<cv::Vec3b>(i,j)[r] ^= keys[i][j];
            }
        }
    }
}
void XOR_Coder::set_keys(Keys && keys_)
{
    keys = std::move(keys_);
}
void XOR_Coder::load_keys(const std::string &path)
{
    std::ifstream  file(path);
    while(!file.eof())
    {
        int i = 0;
        std::vector<int> temp;
        while(i < image.cols)
        {
            int temp_digit = 0;
            file >> temp_digit;
            temp.push_back(temp_digit);
            ++i;
        }
        keys.emplace_back(std::move(temp));
    }
}
void XOR_Coder::save_keys(const std::string &path)
{
    std::ofstream file(path);
    for(int i = 0;i<keys.size();++i)
    {
        for(int j = 0;j<keys[0].size();++j)
        {
            file << keys[i][j];
        }
    }
}
