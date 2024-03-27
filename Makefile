CXX = g++
TARGET = sqlist
SRC = $(TARGET).cpp

CXXFLAGS = -o  #-Wall ->all warning

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $@ $^  #（$^）依赖里的所有


.PHONY: clean #消除有文件名为clean时造成的歧义
clean:
	rm -f *.o $(TARGET)
