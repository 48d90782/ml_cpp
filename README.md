# ML C++ experiments

1. Download pytorch from the [link](https://pytorch.org/get-started/locally/)
2. Download cuDNN from the NVIDIA site [link](https://developer.nvidia.com/rdp/cudnn-download), registration needed
3. Create dir with name `external` in the project root.
4. Put cuDNN and libtorch in it.
5. Install openCV (openSUSE -> `sudo zypper in opencv opencv-devel`)  
Other option to install all needed stuff is to use `https://github.com/microsoft/vcpkg` and delete lines 8-10 from CmakeList.txt
