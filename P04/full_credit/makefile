CXXFLAGS = --std=c++17

lines: main.o line.o
	$(CXX) $(CXXFLAGS) main.o line.o -o lines

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

stock.o: stock.cpp *.h
	$(CXX) $(CXXFLAGS) -c stock.cpp -o stock.o

locomotive.o: locomotive.cpp *.h
	$(CXX) $(CXXFLAGS) -c locomotive.cpp -o locomotive.o

coach.o: coach.cpp *.h
	$(CXX) $(CXXFLAGS) -c coach.cpp -o coach.o

train.o: train.cpp *.h
	$(CXX) $(CXXFLAGS) -c train.cpp -o train.o

clean:
	rm -f *.o *.gch ~* a.out lines

