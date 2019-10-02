
Please run "make" command to build the project and "make clean" command to remove the files created by the "make" command.

Then, export the paths of each library like below before running the executable:

export LD_LIBRARY_PATH=path/to/ConvolutionCore:path/to/MultichannelConvolution:$LD_LIBRARY_PATH

An example:

export LD_LIBRARY_PATH=/home/arda/Projects/Github/MultichannelConvolution/ConvolutionCore:/home/arda/Projects/Github/MultichannelConvolution/MultichannelConvolution:$LD_LIBRARY_PATH

After that you can run the program with an image argument and a kernel argument:

./ConvolutionTest beach.jpg kernel3.txt

A kernel file format should be like this:

kernel_width kernel_height kernel_depth

matrix_for_channel_1_of_the_kernel

matrix_for_channel_2_of_the_kernel

matrix_for_channel_3_of_the_kernel
