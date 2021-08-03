//
// Created by zacky on 7/14/2021.
//

#include <SDL2/SDL.h>
#ifndef RANDOM_MAZE_CREATIONDFS_H
#define RANDOM_MAZE_CREATIONDFS_H
#include "draw.h"

class grid{
public:
    // constants
    static const int max = 100;

    int size;
    //// vectors
    // nodes that have been visited
    bool visited[max][max];

    // initializes all the neighbors of every node
    std::vector<std::pair<int,int>> ogNeighbors[max][max];

    // the finalized neighbors of every node
    std::vector<std::pair<int,int>> finalizedNeighbors[max][max];

    // cords using for drawing
    std::vector<std::pair<int,int>> drawing;

    /// for the solving

    // nodes that have been visited
    bool visited2[max][max];

    // the cords of the parent of the node
    std::vector<std::pair<int,int>> cameFrom[max][max];

    // the dist away from origin
    std::vector<long long> dist[max][max];

    // constructor
    grid(const int Size, SDL_Renderer* renderer, int interv, int height);

    // recursive function to create the maze
    void DFSCreate(int x, int y, SDL_Renderer* renderer, int interv, int height);

    // recursive function to find the fastest route to the top right
    void BFSSolve(int x, int y,SDL_Renderer* renderer, int interv, int height );

    // draws the path out to the screen
    void drawPath(int x, int y,SDL_Renderer* renderer, int interv, int height );
};

#endif //RANDOM_MAZE_CREATIONDFS_H
