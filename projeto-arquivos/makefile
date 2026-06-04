CXX = g++
CXXFLAGS = -Wall -std=c++17

TARGET = detran

SRCS = main.cpp menu.cpp usuarios.cpp carro.cpp

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)