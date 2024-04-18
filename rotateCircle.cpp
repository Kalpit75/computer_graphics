#include <stdio.h>
#include <graphics.h>
#include <math.h>

#define PI 3.14159265

int main() {
    int gd = DETECT, gm;
    int x_center = 300, y_center = 400, radius = 40; // Circle center and radius
    int x_fixed = 350, y_fixed = 300; // Fixed point around which the circle rotates
    int angle = 0;
    double angle_rad;

//    initgraph(&gd, &gm, "");
	initwindow(800,600,"roation", WHITE);

    while (!kbhit()) {
        cleardevice();

        // Draw the fixed point
        putpixel(x_fixed, y_fixed, WHITE);

        // Calculate new position of the circle
        angle_rad = angle * (PI / 180);
        int x_new = x_fixed + (x_center - x_fixed) * cos(angle_rad) - (y_center - y_fixed) * sin(angle_rad);
        int y_new = y_fixed + (x_center - x_fixed) * sin(angle_rad) + (y_center - y_fixed) * cos(angle_rad);

        // Draw the circle
        circle(x_new, y_new, radius);

        // Increment angle for next frame
//        angle = (angle + 1) % 360;
		angle +=1;

        delay(50); // Delay for smoother animation
    }

    closegraph();
    return 0;
}

