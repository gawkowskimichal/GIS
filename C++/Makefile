all: GIS

GIS: main.o dfs.o push_relabel_highest_label.o push_relabel.o push.o read_data.o
	g++ main.o dfs.o push_relabel_highest_label.o push_relabel.o push.o -o GIS read_data.o

main.o: main.cpp
	g++ -c main.cpp

dfs.o: dfs.cpp
	g++ -c dfs.cpp

push_relabel_highest_label.o: push_relabel_highest_label.cpp
	g++ -c push_relabel_highest_label.cpp

push_relabel.o: push_relabel.cpp
	g++ -c push_relabel.cpp

push.o: push.cpp
	g++ -c push.cpp

read_data.o: read_data.cpp
	g++ -c read_data.cpp

clean:
	rm -rf *o GIS	
