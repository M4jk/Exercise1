#include <iostream>

using namespace std;

class Zwierzak {
	public:
		int wiek;
		string imie;
	
	Zwierzak() {
		wiek = 0;
		imie = "brak";
	};
	
	Zwierzak(int age, string name) {
		this->wiek = age;
		this->imie = name;
	}

	void wyswietl() {
		cout << "Imie: " << imie << "\nWiek: " << wiek << endl;
	}
	
	void dajGlos() {
		cout << "grrrrrr" << endl;
	}
};

class Pies : public Zwierzak {
	public:	
		Pies() {
			wiek = 0;
			imie = "brak";
		};
		
		Pies(int age, string name) {
			this->wiek = age;
			this->imie = name;
		}
	
		void dajGlos() {
			cout << "hau" << endl;
		}
};

class Kot : public Zwierzak {
	public:	
		Kot() {
			wiek = 0;
			imie = "brak";
		};
		
		Kot(int age, string name) {
			this->wiek = age;
			this->imie = name;
		}
	
		void dajGlos() {
			cout << "miau" << endl;
		}
};

int main(int argc, char** argv) {
	Zwierzak ges;
	ges.wyswietl();
	ges.dajGlos();
	
	Pies pies(10, "rex");
	pies.wyswietl();
	pies.dajGlos();
	
	Kot cat(8, "tiger");
	cat.wyswietl();	
	cat.dajGlos();
	return 0;
}
