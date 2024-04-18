#include <graphics.h>

void boundaryFill(int x, int y, int fill_color, int boundary_color) {
    if (getpixel(x, y) != boundary_color && getpixel(x, y) != fill_color) {
        putpixel(x, y, fill_color);
        boundaryFill(x + 1, y, fill_color, boundary_color);
        boundaryFill(x - 1, y, fill_color, boundary_color);
        boundaryFill(x, y + 1, fill_color, boundary_color);
        boundaryFill(x, y - 1, fill_color, boundary_color);
    }
}

int main() {
    int gd = DETECT, gm;

//    initgraph(&gd, &gm, "");
	initwindow(800,600,"Boundary Fill Algorithm",WHITE);


    // Drawing a boundary
    rectangle(100, 100, 300, 300);

    // Filling the region inside the boundary
    boundaryFill(150, 150, RED, WHITE);

    getch();
    closegraph();
    return 0;
}

