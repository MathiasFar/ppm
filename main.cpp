#include <iostream>
#include <cmath>
#include <fstream>
#include <string>

using namespace std;

#define IMG_WIDTH 200
#define IMG_HEIGHT 200
#define CIRCLE_RADIUS 100

struct Color {
	int r = 0;
	int g = 0;
	int b = 0;
};

struct Point {
	int x;
	int y;
};

int distance(Point a, Point b) {
	int dX = (a.x - b.x);
	int dY = (a.y - b.y);
	int hyp = sqrt(pow(dX, 2) + pow(dY, 2));

	return hyp;
}


void write_image(Color image[IMG_HEIGHT][IMG_WIDTH]) {
	ofstream file;
	file.open("image.ppm");

	string filestring = "P3 " + to_string(IMG_WIDTH) + " " + to_string(IMG_HEIGHT) + " 255 \n";

	for(int i = 0; i < IMG_HEIGHT; ++i) {
		for(int j = 0; j < IMG_WIDTH; ++j) {
			Point center = {50, 50};
			Point pix= {j, i};
			int dist = distance(center, pix); 
			if(dist < CIRCLE_RADIUS) {
				string line = "0 " + to_string(255) + " 0\n";
				filestring += line;
			} else {
				string line = "0 " + to_string(0) + " 0\n";
				filestring += line;
			}
		}
	}

	file<<filestring;
	file.close();
}


int main() {
	Color image[IMG_HEIGHT][IMG_WIDTH];
	write_image(image);


	return 0;
}
