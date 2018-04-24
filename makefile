CXX = g++
CXXFLAGS = -Wall -Wextra `pkg-config --cflags gtkmm-3.0`
LDFLAGS = `pkg-config --libs gtkmm-3.0`
OBJ = ./objs/main.o
EXEC = aggir.exe

$(EXEC) : $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
./objs/main.o : main.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $< $(LDFLAGS)

clean :
	rm -rf *.exe *~ objs/* 
