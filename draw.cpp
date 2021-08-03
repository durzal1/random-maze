//
// Created by zacky on 7/14/2021.
//
#include <SDL2/SDL.h>
#include <bits/stdc++.h>
#include "draw.h"
void draw(SDL_Renderer* renderer, int x1, int x2, int y1, int y2, int interv, int height){
    // sets color of line
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

    // creates the maze
     int x = x1 * interv;
     int y = x2 * interv;
     int X = y1 * interv;
     int Y = y2* interv;
     if (Y > y){
         // above
         SDL_RenderDrawLine(renderer, x, height - Y, x+interv, height - Y);
         SDL_RenderPresent(renderer);
     }else if (Y < y){
         // below
         SDL_RenderDrawLine(renderer, x, height - y, x+interv, height - y);
         SDL_RenderPresent(renderer);
     }
     else if (X > x){
         // left
         SDL_RenderDrawLine(renderer, X, height - y, X, height - (y+interv));
         SDL_RenderPresent(renderer);
     }else{
         // right
         SDL_RenderDrawLine(renderer, x, height - y, x, height - (y+interv));
         SDL_RenderPresent(renderer);
     }
}
void drawSquare (SDL_Renderer* renderer, int x1, int y1, int interv, int height){
//    // creates the rectangle
//    SDL_Rect Rect;
//    Rect.x = x1 * interv + 5;
//    Rect.y = height - (y1* interv) - interv + 5;
//    Rect.h = interv - 5;
//    Rect.w = interv - 5;
//
//    // sets color
//    SDL_SetRenderDrawColor(renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
//
//    // draws rect
//    SDL_RenderDrawRect(renderer, &Rect);
//    SDL_RenderPresent(renderer);

    int r = 0;
    int g = 0;
    int b = 255;
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
    double offsetx, offsety, d, radius = interv/4;
    int status;


    int x = x1*interv + (interv / 2)  ;
    int y = height - (y1*interv +(interv / 2));
    bool fill = true;
    offsetx = 0;
    offsety = radius;
    d = radius - 1;
    status = 0;

    while (offsety >= offsetx) {
        status += SDL_RenderDrawPoint(renderer, x + offsetx, y + offsety);
        status += SDL_RenderDrawPoint(renderer, x + offsety, y + offsetx);
        status += SDL_RenderDrawPoint(renderer, x - offsetx, y + offsety);
        status += SDL_RenderDrawPoint(renderer, x - offsety, y + offsetx);
        status += SDL_RenderDrawPoint(renderer, x + offsetx, y - offsety);
        status += SDL_RenderDrawPoint(renderer, x + offsety, y - offsetx);
        status += SDL_RenderDrawPoint(renderer, x - offsetx, y - offsety);
        status += SDL_RenderDrawPoint(renderer, x - offsety, y - offsetx);

        if (status < 0) {

            status = -1;
            break;
        }

        if (d >= 2 * offsetx) {
            d -= 2 * offsetx + 1;
            offsetx += 1;
        }
        else if (d < 2 * (radius - offsety)) {
            d += 2 * offsety - 1;
            offsety -= 1;
        }
        else {
            d += 2 * (offsety - offsetx - 1);
            offsety -= 1;
            offsetx += 1;
        }
    }

    if (fill) {


        offsetx = 0;
        offsety = radius;
        d = radius - 1;
        status = 0;

        while (offsety >= offsetx) {

            status += SDL_RenderDrawLine(renderer, x - offsety, y + offsetx,
                                         x + offsety, y + offsetx);
            status += SDL_RenderDrawLine(renderer, x - offsetx, y + offsety,
                                         x + offsetx, y + offsety);
            status += SDL_RenderDrawLine(renderer, x - offsetx, y - offsety,
                                         x + offsetx, y - offsety);
            status += SDL_RenderDrawLine(renderer, x - offsety, y - offsetx,
                                         x + offsety, y - offsetx);

            if (status < 0) {
                status = -1;
                break;
            }

            if (d >= 2 * offsetx) {
                d -= 2 * offsetx + 1;
                offsetx += 1;
            }
            else if (d < 2 * (radius - offsety)) {
                d += 2 * offsety - 1;
                offsety -= 1;
            }
            else {
                d += 2 * (offsety - offsetx - 1);
                offsety -= 1;
                offsetx += 1;
            }
        }
    }
    SDL_RenderPresent(renderer);
}
