output : DayOfYearSet.o main.o 
	g++ -o output main.o DayOfYearSet.o

DayOfYearSet.o : DayOfYearSet.cpp DayOfYearSet.h
	g++ -c -std=c++11 -Wall DayOfYearSet.cpp

main.o : main.cpp
	g++ -c -std=c++11 -Wall main.cpp

clean:
	rm *.o output