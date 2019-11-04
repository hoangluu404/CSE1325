CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`



shelter.o: shelter.cpp *.h
	$(CXX) $(CXXFLAGS) -c shelter.cpp -o shelter.o
client.o: client.cpp *.h
	$(CXX) $(CXXFLAGS) -c client.cpp -o client.o
animal.o: animal.cpp *.h
	$(CXX) $(CXXFLAGS) -c animal.cpp -o animal.o
cat.o: cat.cpp *.h
	$(CXX) $(CXXFLAGS) -c cat.cpp -o cat.o
gender.o: gender.cpp *.h
	$(CXX) $(CXXFLAGS) -c gender.cpp -o gender.o


clean:
	rm -f *.o *.gch a.out
add:
	git add *.cpp *.h Makefile 

