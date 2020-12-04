#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#define __WALL '+'
#define __PATH 'O'
#define __START 'S'
#define __END 'E'
#define __SOLVED '@'

struct point{ int x, y; };

struct maze_bundle{
    char** maze_data;
    bool** maze_check;
    bool path_found;
    int size_x, size_y, start_x, start_y, path_count;

    maze_bundle(std::string file_name){
        path_found = false;
        path_count = 0;

        std::ifstream in_file (file_name);
        
        in_file >> size_y >> size_x >> start_y >> start_x;

        maze_data = new char*[size_y];
        maze_check = new bool*[size_y];

        for(int y = 0; y < size_y; y++){
            maze_data[y] = new char[size_x];
            maze_check[y] = new bool[size_x];

            for(int x = 0; x < size_x; x++){
                in_file >> maze_data[y][x];
                maze_check[y][x] = false;

                if(maze_data[y][x] == __PATH)
                    path_count++;
            }
        }
 
        in_file.close();    
    }

    ~maze_bundle(){
        for(int y = 0; y < size_y; y++){
            delete [] maze_data[y];
            delete [] maze_check[y];
        }
        delete [] maze_data;
        delete [] maze_check;
    }
};


void solve(maze_bundle &maze, std::vector<point> path, int x, int y){

    if(x < 0 || x > maze.size_x - 1 || y < 0 || y > maze.size_y - 1)
        return;

    if(maze.path_found || maze.maze_check[y][x] || maze.maze_data[y][x] == __WALL)
        return;

    maze.maze_check[y][x] = true;
    path.push_back({x , y});

    if(maze.maze_data[y][x] == __END){
        maze.path_found = true;

        for(int i = 1; i < path.size() - 1; i++)
            maze.maze_data[ path[i].y ][ path[i].x ] = __SOLVED;

        return;
    }

    solve(maze, path, x, y - 1);
    solve(maze, path, x, y + 1);
    solve(maze, path, x - 1, y);
    solve(maze, path, x + 1, y);
}

void print(maze_bundle &maze){
    for(int y = 0; y < maze.size_y; y++){
        for(int x = 0; x < maze.size_x; x++)
            std::cout << maze.maze_data[y][x];
        std::cout << std::endl;
    }
}

int main(){
    maze_bundle maze ("maze.txt");
    std::vector<point> the_path;
    
    the_path.reserve(maze.path_count);

    std::cout << "\n\n\nUNSOLVED\n\n\n";

    print(maze);

    std::cout << "\n\n\nSOLVING\n\n\n";

    solve(maze, the_path, maze.start_x, maze.start_y);

    print(maze);

    return 0;
}