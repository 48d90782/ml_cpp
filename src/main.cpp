#include "main.h"
#include <cstdlib>
#include <torch/torch.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "mnist.h"

int main() {
    torch::Tensor tensor = torch::eye(3);
    std::cout << tensor << std::endl;
    return EXIT_SUCCESS;
}