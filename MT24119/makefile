all: railway_debug railway_release

railway_debug: main.cpp Station.cpp Platform.cpp Line.cpp
	g++ -g main.cpp Station.cpp Platform.cpp Line.cpp -o railway_debug

railway_release: main.cpp Station.cpp Platform.cpp Line.cpp
	g++ -O2 main.cpp Station.cpp Platform.cpp Line.cpp -o railway_release

clean:
	rm -f railway_debug railway_release
