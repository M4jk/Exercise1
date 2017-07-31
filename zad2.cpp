#include <iostream>

using namespace std;

class Stack {
	private:
		int size;
		int capacity;
		int *elements;
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
	
	Stack(const Stack &stack) {			//
		capacity = stack.capacity;
		this->size = stack.size;
		elements = new int[capacity];
		int i;
		for(i = 0; i < capacity; i++)
			elements[i] = stack.elements[i];
	}
	
	~Stack() {
		delete [] elements;
	}
	
	void operator + (int value) {	//
		push(value);
	}
	
	friend ostream & operator << (ostream &wyjscie, const Stack &s);	//
};

	ostream & operator << (ostream &wyjscie, const Stack &s) {	//
		for(int i = s.size - 1 ; i>=0; i--)
			cout << s.elements[i] << " ";		
	}

int main(int argc, char** argv) {
	try {
		Stack stos(5);
		stos + 5;
		stos + 6;
		stos + 8;
		stos + 9;
	//	stos.show();
	//	cout << "\nZwrocona wartosc:" << stos.stackPop() << endl;
	//	stos.show();
	//	cout << "\nAktualny rozmiar stosu:" << stos.getSize() << endl;
		Stack stos1(stos);
	//	stos1.show();
		cout << stos1;
	}
	catch(string x) {
		cout << "Blad: " << x;
	}
	
	return 0;
}
