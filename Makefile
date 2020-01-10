TARGET = main.out

HDRS = \
	   project/include

SRCS = \
	   project/src/nonlin_equ.cpp \
	   project/src/main.cpp \
	   project/src/functions.cpp

.PHONY: all clean

all: $(SRCS)
	$(CXX) -I $(HDRS) -o $(TARGET) $(CXXFLAGS) $(SRCS) 
	./$(TARGET)
clean:
	rm -rf $(TARGET)
