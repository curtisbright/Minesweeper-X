compile:
	g++ msxapp.cpp `wx-config --libs` `wx-config --cxxflags` -o msx
clean:
	rm -f msx
