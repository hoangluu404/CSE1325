CXXFLAGS += --std=c++17
GTKFLAGS = `/usr/bin/pkg-config gtkmm-3.0 --cflags --libs`

shelter: mainwin.o main-gui.o shelter.o client.o animal.o cat.o entrydialog.o  *.h
	$(CXX) $(CXXFLAGS) mainwin.o main-gui.o shelter.o client.o animal.o cat.o entrydialog.o $(GTKFLAGS) -o shelter
main-gui.o: main-gui.cpp *.h
	$(CXX) $(CXXFLAGS) -c main-gui.cpp $(GTKFLAGS) -o main-gui.o
mainwin.o: mainwin.cpp *.h
	$(CXX) $(CXXFLAGS) -c mainwin.cpp $(GTKFLAGS) -o mainwin.o
shelter.o: shelter.cpp *.h
	$(CXX) $(CXXFLAGS) -c shelter.cpp -o shelter.o
client.o: client.cpp *.h
	$(CXX) $(CXXFLAGS) -c client.cpp -o client.o
animal.o: animal.cpp *.h
	$(CXX) $(CXXFLAGS) -c animal.cpp -o animal.o
cat.o: cat.cpp *.h
	$(CXX) $(CXXFLAGS) -c cat.cpp -o cat.o
entrydialog.o: entrydialog.cpp *.h
	$(CXX) $(CXXFLAGS) -c entrydialog.cpp $(GTKFLAGS) -o entrydialog.o

clean:
	rm -f *.o *.gch a.out shelter
add:
	git add *.cpp *.h Makefile 

