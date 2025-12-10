# 编译器
CXX = g++

# 编译选项
CXXFLAGS = -std=c++11 -Wall

# 目标可执行文件名（可以根据需要修改）
TARGET = myprogram

# 源文件（自动查找当前目录下的 .cpp 文件）
SOURCES = 1-string.cpp

# 默认目标
all: $(TARGET)

# 链接生成可执行文件
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $@ $(SOURCES)

# 清理编译生成的文件
clean:
	rm -f $(TARGET) *.o

# 重新编译
rebuild: clean all

# 运行程序
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean rebuild run