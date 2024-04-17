#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include <unistd.h> // For usleep() function (microsecond sleep)

// Function to rotate a point (x, y) around a pivot point (xc, yc) by an angle theta (in degrees)
void rotatePoint(int *x, int *y, int xc, int yc, float theta) {
    float radians = theta * (M_PI / 180.0); // Convert angle from degrees to radians
    int newX = xc + (*x - xc) * cos(radians) - (*y - yc) * sin(radians);
    int newY = yc + (*x - xc) * sin(radians) + (*y - yc) * cos(radians);
    *x = newX;
    *y = newY;
}

// Function to draw a triangle
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
    line(x1, y1, x2, y2);
    line(x2, y2, x3, y3);
    line(x3, y3, x1, y1);
}

int main() {
    int gd = DETECT, gm;
    int x1 = 200, y1 = 100; // Coordinates of the first point of the triangle
    int x2 = 100, y2 = 300; // Coordinates of the second point of the triangle
    int x3 = 300, y3 = 300; // Coordinates of the third point of the triangle
    int xc = (x1 + x2 + x3) / 3; // x-coordinate of the centroid of the triangle
    int yc = (y1 + y2 + y3) / 3; // y-coordinate of the centroid of the triangle
    float theta = 0; // Initial rotation angle in degrees
    float dTheta = 1; // Increment in rotation angle for each step

    initgraph(&gd, &gm, "");

    while (!kbhit()) { // Continue animation until a key is pressed
        cleardevice(); // Clear the screen

        // Rotate each vertex of the triangle around the centroid
        rotatePoint(&x1, &y1, xc, yc, theta);
        rotatePoint(&x2, &y2, xc, yc, theta);
        rotatePoint(&x3, &y3, xc, yc, theta);

        // Draw the rotated triangle
        drawTriangle(x1, y1, x2, y2, x3, y3);

        theta += dTheta; // Increment the rotation angle
        if (theta >= 360) // Reset the angle if it exceeds 360 degrees
            theta -= 360;

        delay(50); // Adjust the delay to control the speed of rotation
    }

    getch();
    closegraph();

    return 0;
}
	
