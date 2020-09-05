#ifndef ML_CPP_MNIST_H
#define ML_CPP_MNIST_H

#include <string>
#include <torch/torch.h>
#include <opencv2/opencv.hpp>

class MNISTDataset : public torch::data::Dataset<MNISTDataset> {
public:
    MNISTDataset(const std::string &images_file_name, const std::string &labels_file_name);

    torch::data::Example<> get(size_t index) override;

    [[nodiscard]] torch::optional<size_t> size() const override;

private:
    void ReadLabels(const std::string &labels_file_name);

    void ReadImages(const std::string &images_file_name);

    uint32_t rows = 0;
    uint32_t columns = 0;

    std::vector<unsigned char> labels_;
    std::vector<cv::Mat> images_;

};


#endif //ML_CPP_MNIST_H
