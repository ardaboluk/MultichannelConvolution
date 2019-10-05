CXX = g++ # C compiler
INCLUDEPATH = -I../ConvolutionCore -I../MultichannelConvolution
LIBRARYPATH = -L../ConvolutionCore -L../MultichannelConvolution
LIBS = -lconvolutioncore -lmCXXonvolution `pkg-config --cflags --libs opencv`
CXXFLAGS = $(INCLUDEPATH) -Wall -O2 -g # C flags
LDFLAGS = $(LIBRARYPATH) # linking flags
RM = rm -f  # rm command
TARGET = ConvolutionTest # target

SRCS =  ConvolutionTest.cpp # source files
OBJS = 	$(SRCS:.cpp=.o)

.PHONY: all
all: ${TARGET}

$(TARGET): $(OBJS)
	$(CXX) $(LDFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: clean
clean:
	-${RM} ${TARGET}
