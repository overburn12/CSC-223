#include <iostream>
#include <string>
#include <vector>

#define __PATH 'O' //not used
#define __WALL '+'
#define __START 'S' //not used
#define __END 'E'
#define __SOLVED '@'

#include "maze.cpp"

void solve(maze_data &maze, maze_check &check, std::vector<point> path, int x, int y);

int main(){
    //the data for the maze layout
    maze_data maze ("maze.txt");

    //the path check to see if we have visited a coordinate already and prevent repeats
    maze_check check (maze.size);

    //a blank starting point for building the solve algorithm path
    std::vector<point> path;

    std::cout << "\n\n\nUNSOLVED:\n\n\n";
    maze.print();

    solve(maze, check, path, maze.start.x, maze.start.y);

    std::cout << "\n\n\nSOLVED:\n\n\n";
    maze.print();

    return 0;
}

void solve(maze_data &maze, maze_check &check, std::vector<point> path, int x, int y){

    //if we have already found a path, then exit this recursion branch
    if(check.path_found) 
        return;
    
    //if we are at an invalid coordinate, then exit this recursion branch
    if(x < 0 || x > maze.size.x - 1 || y < 0 || y > maze.size.y - 1)
        return;

    //if this coordinate has already been checked, or it is a wall, then exit this recursion branch
    if(check[y][x] || maze[y][x] == __WALL)
        return;

    //mark this coordinate as being checked by the solve algorithm
    check[y][x] = true;

    //add this coordinate to the current solve path
    path.push_back({x , y});

    //if we have found the end of the path
    if(maze[y][x] == __END){

        //flag that we have found a path, to exit all other ongoing solve branches
        check.path_found = true;

        //change the maze data to show the winning solve path
        for(int i = 1; i < path.size() - 1; i++)
            maze[ path[i].y ][ path[i].x ] = __SOLVED;
            
        return;
    }

    //branch is each direction: above, below, left, right
    solve(maze, check, path, x, y - 1);
    solve(maze, check, path, x, y + 1);
    solve(maze, check, path, x - 1, y);
    solve(maze, check, path, x + 1, y);
}