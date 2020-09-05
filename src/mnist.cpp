#include "mnist.h"
#include <opencv2/opencv.hpp>

torch::Tensor CvImageToTensor(const cv::Mat &image) {
    assert(image.channels() == 1);
    std::vector<int64_t> dims{
            static_cast<int64_t>(1),
            static_cast<int64_t>(image.rows),
            static_cast<int64_t>(image.cols)
    };
    torch::Tensor tensor_image = torch::from_blob(
            image.data,
            torch::IntArrayRef(dims),
            torch::TensorOptions().dtype(torch::kFloat).requires_grad(false)).clone();
    // clone is required to copy data from temporary object

    return tensor_image.to(torch::DeviceType::CUDA);
}

MNISTDataset::MNISTDataset(const std::string &images_file_name, const std::string &labels_file_name) {

}

torch::data::Example<> MNISTDataset::get(size_t index) {
    return {
            CvImageToTensor(images_[index]), torch::tensor(static_cast<int64_t>(labels_[index]),
                                                           torch::TensorOptions().dtype(torch::kLong).device(
                                                                   torch::DeviceType::CUDA))
    };
}

// number of labels loaded from disk
torch::optional<size_t> MNISTDataset::size() const {
    return labels_.size();
}

void MNISTDataset::ReadLabels(const std::string &labels_file_name) {

}

void MNISTDataset::ReadImages(const std::string &images_file_name) {

}


