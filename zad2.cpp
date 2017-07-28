#include <iostream>

using namespace std;

class Stack {
	private:
		int size;
		int capacity;
		int *elements; //tablica liczb;
	public:
		
	Stack() {
		capacity = 4;
		this->size = 0;
		elements = new int[capacity];
	}
	
	Stack(int capacity) {
		this->capacity = capacity;
		this->size = 0;
		elements = new int[capacity];
	}
	
	void show() {
		for(int i = size - 1 ; i>=0; i--)
		cout << elements[i] << " ";
	}

	bool isEmpty() {
		if(size == 0)
			return true;
		return false;
	}

	bool isFull() {
		if(size == capacity)
			return true;
		return false;
	}

	void push(int value) {
		if (isFull()) {
			string error = "Stos jest pelny";
			throw error;
		}
		elements[size++] = value;
	}

	int stackPop() {
		if(isEmpty()) {
			string error = "Stos jest pusty";
			throw error;
		}
		return elements[--size];
	}

	int getSize() {
		return size;
	}
	
	~Stack() {
		delete [] elements;
	}
	
};

int main(int argc, char** argv) {
	try {
		Stack stos(5);
	//	cout << "Stos pusty: " << stos.isEmpty() << endl;
		stos.push(10);
	//	stos.stackPop();
	//	stos.stackPop();
		stos.push(20);
		stos.push(30);
	//	stos.Push(30);
	//	stos.Push(30);
	//	cout << "Stos pelen: " << stos.isFull() << endl;
		stos.show();
		cout << "\nZwrocona wartosc:" << stos.stackPop() << endl;
		stos.show();
		cout << "\nAktualny rozmiar stosu:" << stos.getSize() << endl;
	}
	catch(string x) {
		cout << "Blad: " << x;
	}
	
	return 0;
}
