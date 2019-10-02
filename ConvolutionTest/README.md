
Please export the paths of each library like below before running the executable:

export LD_LIBRARY_PATH=path/to/ConvolutionCore:path/to/MultichannelConvolution:$LD_LIBRARY_PATH

An example:

export LD_LIBRARY_PATH=/home/arda/Projects/Github/MultichannelConvolution/ConvolutionCore:/home/arda/Projects/Github/MultichannelConvolution/MultichannelConvolution:$LD_LIBRARY_PATH

After that you can run the program using the command:

./ConvolutionTest beach.jpg kernel3.txt
