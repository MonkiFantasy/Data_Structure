CXX = g++
TARGET = sqlist
SRC = $(TARGET).cpp
OBJ = $(patsubst %.cpp, %.o, $(SRC))

CXXFLAGS = -c -Wall #-Wall ->all warning

$(TARGET): $(OBJ)
	$(CXX) -o $@ $^  #（$^）依赖里的所有

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ #($<) 依赖里的第一个

.PHONY: clean #消除有文件名为clean时造成的歧义
clean:
	rm -f *.o $(TARGET)
