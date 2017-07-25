#include <iostream>

using namespace std;

class Punkt2D {
	public:
		int x;
		int y;
		
	Punkt2D() {
		x = 0;
		y = 0;
	}

	Punkt2D(int x, int y) {
		this->x = x;
		this->y = y;
	}
	
	void wyswietl() {
		cout << "x:" << x << "\ny:" << y << endl;
	}

};

int main(int argc, char** argv) {
	Punkt2D test(10,50);
	test.wyswietl();
	return 0;
}
