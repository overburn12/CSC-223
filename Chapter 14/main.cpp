#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define __PATH 'O'
#define __SOLVED '@'
#define __WALL '+'

#define __START 'S' 
#define __END 'E'

//used for storing the path coordinates
struct point{ int x, y; };

struct maze_data{
    char** data;
    std::vector<point> path;
    int size_x, size_y, start_x, start_y;

    //construct maze_data by reading in the maze data from a given file
    maze_data(std::string file_name){
        std::ifstream in_file (file_name);

        in_file >> size_y >> size_x >> start_y >> start_x;
        data = new char*[size_y];

        for(int y = 0; y < size_y; y++){
            data[y] = new char[size_x];

            for(int x = 0; x < size_x; x++)
                in_file >> data[y][x];
        }   
    }

    //automatic delete for the pointer array
    ~maze_data(){
        for(int y = 0; y < size_y; y++) 
            delete [] data[y]; 
        delete [] data;
    }

    //print the maze to the terminal
    void print(){
        std::string hbar (size_x, '-');
        char corner = '+';
        char vbar = '|';

        std::cout << '\t' << corner << hbar << corner << std::endl;
        for(int y = 0; y < size_y; y++){
            std::cout << '\t' << vbar;

            for(int x = 0; x < size_x; x++)
                std::cout << data[y][x];

            std::cout << vbar << std::endl;
        }
        std::cout << '\t' << corner << hbar << corner << std::endl;
    }

    //recursive algorithm to solve the maze path
    //this function will solve for the shortest path, and store it to this->path
    void solve(std::vector<point> current_path, int x, int y){

        //exit if the coordinate is invalid
        if(x < 0 || x > size_x - 1 || y < 0 || y > size_y - 1)
            return;

        //exit if the coordinate is a wall
        if(data[y][x] == __WALL)
            return;

        //exit if the coordinate is already in the solve path
        for(int i = 0; i < current_path.size(); i++)
            if(current_path[i].x == x && current_path[i].y == y)
                return;

        //exit if the current path plus this coodrinate is longer or equal to the stored solve path
        if(current_path.size() + 1 >= path.size() && path.size() != 0)
            return;

        //add this coordinate to the current solve path
        current_path.push_back({x , y});

        //if we have found the end of the path
        if(data[y][x] == __END){
            //store the path with the maze
            path = current_path;
            return;
        }

        //branch in each direction
        solve(current_path, x, y + 1); // down
        solve(current_path, x + 1, y); // right
        solve(current_path, x - 1, y); // left
        solve(current_path, x, y - 1); // up
    }

    //the starting function for initiating the recursive solve algorithm
    void solve(){
        //a blank starting point for building the solve algorithm path
        std::vector<point> current_path;

        //the starting point of the recursive solve algorithm
        solve(current_path, start_x, start_y);

        //fill in the map with the solve path
        for(int i = 1; i < path.size() - 1; i++)
            data[ path[i].y ][ path[i].x ] = __SOLVED;
    }
};


int main(){
    std::string file_name;

    std::cout << "Enter a file name: ";
    std::cin >> file_name;

    //exit if the file cannot be opened
    std::ifstream test_file(file_name);
    if(!test_file.good()){
        std::cout << "File not good";
        return 0;
    }
    test_file.close();

    //the maze object
    maze_data maze(file_name);

    std::cout << "UNSOLVED:" << std::endl;
    maze.print();

    maze.solve();

    std::cout << "SOLVED:" << std::endl;
    maze.print();

    return 0;
}