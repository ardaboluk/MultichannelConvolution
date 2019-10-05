CXX = g++ # C compiler
CXXFLAGS = -c -fPIC -Wall -Werror -O2 -g # C flags
LDFLAGS = -shared  # linking flags
RM = rm -f  # rm command
TARGET_LIB = libconvolutioncore.so # target lib

SRCS =  point.cpp rectangle.cpp # source files
OBJS = $(SRCS:.cpp=.o)

.PHONY: all
all: ${TARGET_LIB}

$(TARGET_LIB): $(OBJS)
	$(CXX) ${LDFLAGS} -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $<

.PHONY: clean
clean:
	-${RM} ${TARGET_LIB} ${OBJS}
