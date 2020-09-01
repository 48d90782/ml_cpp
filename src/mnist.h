#ifndef ML_CPP_MNIST_H
#define ML_CPP_MNIST_H

#include <string>
#include <torch/torch.h>

class MNISTDataset : public torch::data::Dataset<MNISTDataset> {
public:
    MNISTDataset(const std::string &images_file_name, const std::string &labels_file_name);
    torch::data::Example<> get(size_t index) override;
    torch::optional<size_t> size() const override;
};


#endif //ML_CPP_MNIST_H
