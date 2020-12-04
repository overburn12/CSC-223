#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define __PATH 'O' //not used
#define __WALL '+'
#define __START 'S' //not used
#define __END 'E'
#define __SOLVED '@'

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

        in_file.close();    
    }

    //treat maze_data[][] as the data array itself
    char* operator [] (int index){ 
        return data[index]; 
    }

    //automatic delete for the pointer array
    ~maze_data(){ 
        for(int y = 0; y < size_y; y++) 
            delete [] data[y]; 

        delete [] data; 
    }

    //print the maze to the terminal
    void print(){
        for(int y = 0; y < size_y; y++){
            std::cout << '\t';

            for(int x = 0; x < size_x; x++)
                std::cout << data[y][x];

            std::cout << '\n';
        }
    }

    //draw the stored path on the map
    void draw_path_on_map(){
        for(int i = 1; i < path.size() - 1; i++)
            data[ path[i].y ][ path[i].x ] = __SOLVED;
    }
};

void solve(maze_data &maze, std::vector<point> path, int x, int y, bool finding_shortest_path){

    //exit if we already found a path and we're not looking for the shortest path
    if(maze.path.size() != 0 && !finding_shortest_path) 
        return;
    
    //exit if the coordinates are invalid
    if(x < 0 || x > maze.size_x - 1 || y < 0 || y > maze.size_y - 1)
        return;

    //exit if the coordinates is a wall
    if(maze[y][x] == __WALL)
        return;

    //exit if the coordinates are already in the solve path
    for(int i = 0; i < path.size(); i++)
        if(path[i].x == x && path[i].y == y)
            return;

    //add this coordinate to the current solve path
    path.push_back({x , y});

    //exit if the current path is longer or equal to the stored solve path
    if(path.size() >= maze.path.size() && maze.path.size() != 0)
        return;

    //if we have found the end of the path
    if(maze[y][x] == __END){
        std::cout << "Path found, length: " << path.size() << std::endl;

        //store the path with the maze
        maze.path = path;

        return;
    }

    //branch in each direction
    solve(maze, path, x, y + 1, finding_shortest_path); // down
    solve(maze, path, x + 1, y, finding_shortest_path); // right
    solve(maze, path, x - 1, y, finding_shortest_path); // left
    solve(maze, path, x, y - 1, finding_shortest_path); // up
}

int main(){
    std::string file_name;
    
    std::cout << "Enter maze file to solve: ";
    std::cin >> file_name;

    std::ifstream test_file (file_name);
    if(test_file.fail()){
        std::cout << "File has failed!" << std::endl;
        test_file.close();
        return 0;
    }
    test_file.close();

    //the data for the maze layout
    maze_data maze(file_name);

    //a blank starting point for building the solve algorithm path
    std::vector<point> path;

    std::cout << "\nUNSOLVED:\n";
    maze.print();

    solve(maze, path, maze.start_x, maze.start_y, true);
    maze.draw_path_on_map();

    std::cout << "\nSOLVED:\n";
    maze.print();

    return 0;
}