#include <iostream>
#include <fstream>
#include <string>

struct point{ 
    int x, y; 
};

struct maze_data{
    char** data; 
    point size, start;

    //construct a maze_data by reading in the maze data from a given file
    maze_data(std::string file_name){
        std::ifstream in_file (file_name);

        in_file >> size.y >> size.x >> start.y >> start.x;

        data = new char*[size.y];

        for(int y = 0; y < size.y; y++){
            data[y] = new char[size.x];

            for(int x = 0; x < size.x; x++)
                in_file >> data[y][x];
        }

        in_file.close();    
    }

    //treat maze_data[][] as the data array itself
    char* operator [] (int index){ 
        return data[index]; 
    }

    //automatic delete for the pointer array
    ~maze_data(){ 
        for(int y = 0; y < size.y; y++) 
            delete [] data[y]; 

        delete [] data; 
    }

    //print the maze to the terminal
    void print(){
        for(int y = 0; y < size.y; y++){
            std::cout << '\t';

            for(int x = 0; x < size.x; x++)
                std::cout << data[y][x];

            std::cout << '\n';
        }
    }
};

struct maze_check{
    bool** data; 
    bool path_found; 
    point size;

    //create a bool pointer array of the same size as the maze_size
    maze_check(point maze_size){
        size = maze_size;
        path_found = false;

        data = new bool*[size.y];

        for(int y = 0; y < size.y; y++){
            data[y] = new bool[size.x];

            for(int x = 0; x < size.x; x++)
                data[y][x] = false;
        }
    }

    //treat maze_check[][] as the data array itself
    bool* operator [] (int index){ 
        return data[index]; 
    }

    //automatic delete for the pointer array
    ~maze_check(){ 
        for(int y = 0; y < size.y; y++) 
            delete [] data[y]; 

        delete [] data; 
    }
};
