#include <graphics.h>

void floodFill(int x, int y, int old_color, int new_color) {
    if (getpixel(x, y) == old_color) {
        putpixel(x, y, new_color);
        floodFill(x + 1, y, old_color, new_color);
        floodFill(x - 1, y, old_color, new_color);
        floodFill(x, y + 1, old_color, new_color);
        floodFill(x, y - 1, old_color, new_color);
    }
}

int main() {
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "");

    // Drawing a boundary
    rectangle(100, 100, 300, 300);

    // Filling the region inside the boundary
    floodFill(150, 150, BLACK, GREEN); // Starting point (150, 150), old color is BLACK, fill color is GREEN

    getch();
    closegraph();
    return 0;
}

