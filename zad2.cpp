#include <iostream>
#include <cstdlib>
#include <cctype>

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
	
	Stack(const Stack &stack) {
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
	
	void operator + (int value) {
		push(value);
	}
	
	friend ostream & operator << (ostream &wyjscie, const Stack &s);
};

	ostream & operator << (ostream &wyjscie, const Stack &s) {
		for(int i = s.size - 1 ; i>=0; i--)
			cout << s.elements[i] << " ";		
	}

int main(int argc, char** argv) {
	
	int rozmiar = 0, liczba = 0;
	bool flaga = true;
	string bufor;
	try {
	cout << "Podaj rozmiar stosu: ";
	cin >> rozmiar;
	
	if(cin.fail() || rozmiar <= 0) {
		string error = "Nieprawidlowa wartosc";
		throw error;
	}
	
	Stack stos(rozmiar);
	cout << "Dozwolone komendy: push (value), pop, print, size, end - konczy program" << endl;
	
	while(1) {
		flaga = true;
		cin >> bufor;
		
		if(bufor != "push" && bufor != "pop" && bufor != "print" && bufor != "size" && bufor != "end") {
			string error = "Nieprawidlowa komenda";
			throw error;
		}
		
		if(bufor == "push") {
			cin.ignore(10, ' ');
			cin >> bufor;
			for(int i = 0; i < bufor.length(); i++) {
				if(isdigit(bufor[i]) == 0) {
					flaga = false;
					string error = "Nieprawidlowa wartosc";
					throw error;
				}
			}	
			if(flaga) {
			liczba = atoi(bufor.c_str());
			stos.push(liczba);
			}
		}
		
		if(bufor == "pop") stos.stackPop();
		
		if(bufor == "print") {
			cout << "Zawartosc stosu: [ ";
			stos.show();
			cout << "]" << endl;
		}
		
		if(bufor == "size") cout << "Aktualny rozmiar: " << stos.getSize() << endl;
		
		if(bufor == "end") break;
	}
	}
	catch(string x) {
		cout << "Wyjatek: " << x;
	}
	
	return 0;
}
