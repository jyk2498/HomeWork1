main.o : main.cc GF_field.hh
	g++ -c main.cc

GF_field.o : GF_field.cc GF_field.hh
	g++ -c GF_field.cc

GF_field : main.o GF_field.o
	g++ GF_field.o main.o -o GF_field