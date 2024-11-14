all: railway_debug railway_release

railway_debug: main.cpp Platform.cpp Line.cpp
	g++ -g main.cpp Platform.cpp Line.cpp -o railway_debug

railway_release: main.cpp Platform.cpp Line.cpp
	g++ -O2 main.cpp Platform.cpp Line.cpp -o railway_release

clean:
	del /f railway_debug.exe railway_release.exe
