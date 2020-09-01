#include "mnist.h"

MNISTDataset::MNISTDataset(const std::string &images_file_name, const std::string &labels_file_name) {

}

torch::data::Example<> MNISTDataset::get(size_t index) {
    return torch::data::Example<>();
}

torch::optional<size_t> MNISTDataset::size() const {
    return torch::optional<size_t>();
}
