CPPFILES = $(wildcard *.cpp)
OBJFILES = $(CPPFILES:.cpp=.o)
compile: $(OBJFILES)
	g++ $(OBJFILES) `wx-config --libs` `wx-config --cxxflags` -o msx
%.o: %.cpp
	g++ $< -c `wx-config --libs` `wx-config --cxxflags`
clean:
	rm -f msx
