g++ -std=c++11 -c models.cc
g++ -std=c++11 -c controller.cc
g++ -std=c++11 -c views.cc
g++ -std=c++11 -o main main.cc models.o controller.o views.o
