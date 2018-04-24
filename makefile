CXX = g++
CXXFLAGS = -Wall -Wextra `pkg-config --cflags gtkmm-3.0`
LDFLAGS = `pkg-config --libs gtkmm-3.0`
OBJ = ./objs/main.o ./objs/fenetre.o ./objs/grille.o
EXEC = aggir.exe

$(EXEC) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
./objs/main.o : main.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $< $(LDFLAGS)
./objs/fenetre.o : fenetre.cpp fenetre.hpp
	$(CXX) $(CXXFLAGS) -o $@ -c $< $(LDFLAGS)
./objs/grille.o : grille.cpp grille.hpp
	$(CXX) $(CXXFLAGS) -o $@ -c $< $(LDFLAGS)

clean :
	rm -rf *.exe *~ objs/* 
