//
// Created by zacky on 7/14/2021.
//
#include <bits/stdc++.h>
#include "creationDFS.h"
#include "random.h"
grid::grid(const int Size, SDL_Renderer* renderer, int interv, int height) {
    this->size = Size;

    // init vectors
    for (int x = 0; x < size; x++){
        for (int y = 0; y < size; y++){
            // adds all of its neighbors
            if (x != 0){
                ogNeighbors[x][y].emplace_back(x-1, y);
            }
            if (y != 0){
                ogNeighbors[x][y].emplace_back(x, y-1);
            }
            if (x != size - 1){
                ogNeighbors[x][y].emplace_back(x+1, y);
            }
            if (y != size - 1){
                ogNeighbors[x][y].emplace_back(x, y+1);
            }
        }
    }

    // add the origin
    drawing.emplace_back(0,0);

    // set the first val
    dist[0][0].push_back(0);
    // create the maze
    DFSCreate(0,0, renderer, interv, height);

    // find solution
    BFSSolve(0, 0, renderer, interv, height);
    drawPath(Size-1, Size-1, renderer, interv, height);


}
// creates the actual maze
void grid::DFSCreate(int x, int y, SDL_Renderer* renderer, int interv, int height) {
    // makes sure the point has not been visited (i dont think its needed here tbh
    assert(!visited[x][y]);

    // marks this spot as visited
    visited[x][y] = true;

    while (ogNeighbors[x][y].size() != 0){
        int i = randomint(0,ogNeighbors[x][y].size()-1);
        std::pair<int,int> neighbor = ogNeighbors[x][y][i];
        int X = neighbor.first;
        int Y = neighbor.second;
        if (!visited[X][Y]){
            finalizedNeighbors[x][y].emplace_back(X,Y);
            ogNeighbors[x][y].erase(ogNeighbors[x][y].begin()+i);
            drawing.emplace_back(X,Y);
            draw(renderer, x, y, X, Y, interv, height);
            DFSCreate(X,Y, renderer, interv, height);
        }else ogNeighbors[x][y].erase(ogNeighbors[x][y].begin()+i);
    }
}
void grid::BFSSolve(int x, int y, SDL_Renderer *renderer, int interv, int height) {
    // makes sure the point has not been visited (i dont think its needed here tbh)
    if (visited2[x][y]) return;

    visited2[x][y] = true;

    for (std::pair<int,int> Pair:finalizedNeighbors[x][y]){
        // set variables
        int X = Pair.first;
        int Y = Pair.second;

        // make sure the node has not already been visited
        if (!visited2[X][Y]){
            long long Short = 999999;
            for (int i = 0; i < dist[x][y].size(); i++){
                // find the shortest path
                Short = std::min(Short, dist[x][y][i]);
            }
            dist[X][Y].push_back(Short+1);
            cameFrom[X][Y].emplace_back(x,y);
            BFSSolve(X,Y, renderer, interv, height);
        }
    }
}
void grid::drawPath(int x, int y, SDL_Renderer *renderer, int interv, int height) {
    // inits short to a unreachable number
    long long Short = 100000;
    for (int i = 0; i < dist[x][y].size(); i++){
        // find the shortest path
        Short = std::min(Short, dist[x][y][i]);
    }
    // finds the one it came from based off its dist (if the dist is Short - 1)
    for (std::pair<int,int> Pair:cameFrom[x][y]){
        int s = dist[Pair.first][Pair.second][0];
        if (dist[Pair.first][Pair.second][0] == Short-1){
            // found the parent
            drawSquare(renderer, x, y, interv, height);

            drawPath(Pair.first, Pair.second, renderer, interv, height);
        }
    }
}