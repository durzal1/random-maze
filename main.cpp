#include <iostream>
#include <bits/stdc++.h>
#include "creationDFS.h"
#include <ctime>
#include <SDL2/SDL.h>
// const
const int posX =450, posY = 30, width = 1000, height = 1000;

// code time about 5-6 hours

// todo IF SDL DOES NOT WORK MAKE SURE YOU HAVE ****int argc, char* argv[]***
int main(int argc, char* argv[]) {
    // for random
    srand(time(NULL));


    // gets dimensions
    std::cout << "input the dimensions for the grid that is divisable by 10 and <= 200: ";
    int SIZE = 100;

    // gets measurmeants
    int lineSize = width / SIZE;

    /// initializes SDL
    SDL_Window* win = NULL;
    SDL_Renderer* renderer = NULL;

    SDL_Init(SDL_INIT_VIDEO);

    win = SDL_CreateWindow("Hello World", posX, posY, width, height, 0);

    renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);


    // Select the color for drawing. It is set to red here.
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    // Clear the entire screen to our selected color.
    SDL_RenderClear(renderer);

    // sets color of line
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);

    // draws the default
    int interv = height / SIZE;
    for (int x = 0; x <= height; x+= interv){
        for (int y = 0; y <= height; y += interv){
            // adds the lines
            SDL_RenderDrawLine(renderer, x, y, x, height);
            SDL_RenderDrawLine(renderer, x, y, height, y);
        }
    }
    // draws an extra line for the bottom
    SDL_RenderDrawLine(renderer, 0, height-1, height-1,height-1);
    SDL_RenderDrawLine(renderer, height-1, 0, height-1,height-1);

    // creates the grid
    grid Maingrid = grid(SIZE, renderer, interv, height);

    // draws origin rect



    SDL_Delay(100000);


    return 0;
}
