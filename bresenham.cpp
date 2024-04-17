#include <graphics.h>
#include <conio.h> 

int main() {
    // Coordinates of the line
    int x1=100, y1=200, x2=200, y2=400;
    
    int gd = DETECT, gm;
    int dx, dy, p, x, y;

    // Initialize graphics mode
    initgraph(&gd, &gm, "");

    // Calculate dx and dy
    dx = x2 - x1;
    dy = y2 - y1;

    // Initial point
    x = x1;
    y = y1;

    // Calculate initial decision parameter
    p = 2 * dy - dx;

    // Plot initial point
    putpixel(x, y, WHITE);

    // Loop to plot the line
    while (x < x2) {
        x++;
        // If decision parameter is positive, choose y = y+1
        if (p >= 0) {
            y++;
            p = p + 2 * dy - 2 * dx;
        } else {
            p = p + 2 * dy;
        }
        // Plot the point
        putpixel(x, y, WHITE);
    }

    getch();
    closegraph();
    return 0;
}

