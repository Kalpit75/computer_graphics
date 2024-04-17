#include <stdio.h>
#include <graphics.h>
#include <unistd.h> // For sleep() function

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

// Function to translate (move) a triangle by dx along x-axis and dy along y-axis
void translateTriangle(int *x1, int *y1, int *x2, int *y2, int *x3, int *y3, int dx, int dy) {
    *x1 += dx;
    *y1 += dy;
    *x2 += dx;
    *y2 += dy;
    *x3 += dx;
    *y3 += dy;
}

int main() {
    int gd = DETECT, gm;
    int x1 = 100, y1 = 100, x2 = 200, y2 = 100, x3 = 150, y3 = 50;
    int dx = 5, dy = 5; // Translation factors

    initgraph(&gd, &gm, "");

    // Animation loop
    for (int i = 0; i < 40; i++) {
        cleardevice(); // Clear the previous frame

        // Draw the triangle at its new position
        drawTriangle(x1, y1, x2, y2, x3, y3);

        // Translate the triangle
        translateTriangle(&x1, &y1, &x2, &y2, &x3, &y3, dx, dy);

        // Render the frame
        delay(100); // Adjust the delay to control the speed of the animation
    }

    getch();
    closegraph();

    return 0;
}

