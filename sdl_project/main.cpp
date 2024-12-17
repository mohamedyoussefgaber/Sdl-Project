
#include <vector>
#include "screen.h"

p_to_draw cental = { 0,0,0 };
p_to_draw cental1 = { 0,0,0 };
int main(int argc, char* argv[]) {
    //squre(p,con, cental);
    piramid(p, con, cental);
    screen myscreen;
    /*while (1) {
        myscreen.circuil(160, 160, 100);
        //myscreen.circuil(100, 100, 100);
        myscreen.show(); //myscreen.input();
}*/
    while (true)
    {       
       
       for (auto& P : p) {
            P.x -= cental.x; P.y -= cental.y; P.z -= cental.z;
            myscreen.rotate(P, 0.00, 0.02, 0.02);
            P.x += cental.x; P.y += cental.y; P.z += cental.z;
        } 
       for (auto c : con) {
            myscreen.line(p[c.a].x, p[c.a].y, p[c.b].x, p[c.b].y);
        }
       
        
        
        myscreen.show();
        myscreen.clear();
        
        SDL_Delay(30);    
    }

}



