#include <uvsqgraphics.h>

int main () 
{
    POINT P1, P2, P3;
    init_graphics (800,600);
    P1.x = lire_entier_clavier(); P2.x=lire_entier_clavier(); 
    P1.y = 100; P2.y = 100; 
    
    draw_circle(P1, 5, red);
    draw_circle(P2, 5, red);
    draw_line(P1, P2, blue);
    
    P3.x = (P1.x + P2.x)/2; P3.y = 300;
    
    draw_line(P2, P3, blue);
    draw_line(P3, P1, blue);
    
    wait_escape();
    exit(0);
}
