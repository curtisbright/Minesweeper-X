CPPFILES = $(wildcard *.cpp)
OBJFILES = $(CPPFILES:.cpp=.o)
msx: $(OBJFILES)
	g++ $(OBJFILES) `wx-config --libs` -o msx
%.o: %.cpp
	g++ $< -c `wx-config --cxxflags`
clean:
	rm -f msx *.o
