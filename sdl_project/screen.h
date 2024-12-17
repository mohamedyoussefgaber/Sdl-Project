#include <SDL.h>
#include <vector>
#include<cmath>
struct p_to_draw {
    float x, y, z;
};
struct connections {
    int a, b;
};

class screen {
    SDL_Event e;
    SDL_Window* window;
    SDL_Renderer* renderer;
    std::vector <SDL_FPoint> points;
    
public:
    screen() {
        SDL_Init(SDL_INIT_VIDEO);
        SDL_CreateWindowAndRenderer(680 , 680, 0, &window, &renderer);
        SDL_RenderSetScale(renderer, 2, 2);
    }

    void pixel(float x, float y) {

        points.emplace_back(SDL_FPoint{ x, y });
    }

    void show() {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        for (auto& point : points) {
            SDL_RenderDrawPointF(renderer, point.x, point.y);
        }
        SDL_RenderPresent(renderer);
    }
    void clear() {
        points.clear();
    }

    void line( float x1,float y1 ,float x2, float y2 ) {
        float dy = y2 - y1;
        float dx = x2 - x1;
        float len = std:: sqrt((x1 - x2) * (x1 - x2) + (y1 - y2)*(y1 - y2));
        float angle = std:: atan2(dy, dx);
        for (int i = 0; i < len; i++) {
            pixel(x1 + std::cos(angle) * i
                , y1 + std::sin(angle) * i
            );
        }
    }
    void circuil(float x, float y,float r ) {
        float angle = 0;
        for (float i = 0; i < 2 * 3.14; i += 0.005) {
            pixel(x + std::cos(i) * r
                , y + std::sin(i) * r
            );
        }
    }

    

    void input(){

        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                SDL_Quit(); exit(0);
            }

        }
    }

    void rotate(p_to_draw& p, float radx = 1, float rady = 1, float radz = 1) {
        //rotation around x axis with angle radx
        p.y = std::cos(radx) * p.y - std::sin(radx) * p.z;
        p.z = std::sin(radx) * p.y + std::cos(radx) * p.z;
        //rotation around y axis with angle rady
        p.x = std::cos(rady) * p.x + std::sin(rady) * p.z;
        p.z = -std::sin(rady) * p.x + std::cos(rady) * p.z;
        //rotation around z axis with angle radz
        p.x = std::cos(radz) * p.x - std::sin(radz) * p.y;
        p.y = std::sin(radz) * p.x + std::cos(radz) * p.y;
    }

    

};
//variables
std::vector <p_to_draw> p;
std::vector <connections> con;
std::vector <p_to_draw> p1;
std::vector <connections> con1;
///////////////////////////////
void squre(std::vector <p_to_draw>& p, std::vector <connections>& con, p_to_draw& cental) {
    p = {
    { 100,100,100 },
    { 200,100,100 },
    { 200,200,100 },
    { 100,200,100 },

    {100,100,200},
    { 200,100,200 },
    { 200,200,200 },
    { 100,200,200 },
    };
    con = {

    {0,4},{1,5},{2,6},{3,7},
    {0,3},{1,0},{1,2},{3,2},
    {4,5},{5,6},{6,7},{7,4}

    };
    for (auto P : p) {
        cental.x += P.x;
        cental.y += P.y;
        cental.z += P.z;
    }
    cental.x /= p.size();
    cental.y /= p.size();
    cental.z /= p.size();
}

void piramid(std::vector <p_to_draw>& p, std::vector <connections>& con,p_to_draw& cental) {
    p = {
    /*{ 100,100,100 },
    { 200,100,100 },
    { 200,200,100 },
    { 100,200,100 },

    {150,150,200},*/
    { 300,100,300 },
    { 100,100,300 },
    { 100,300,100 },
    { 300,300,100 },
    
    

    {200,141.42,141.42},
    
    };
    con = {
    {0,3},{1,0},{1,2},{3,2},
    {4,3},{4,2},{4,1},{4,0}
    };
    for (auto P : p) {
        cental.x += P.x;
        cental.y += P.y;
        cental.z += P.z;
    }
    cental.x /= p.size();
    cental.y /= p.size();
    cental.z /= p.size();
}