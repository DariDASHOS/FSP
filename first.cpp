#include <iostream>
#include <windows.h>
using namespace std;

//Структура суммы
struct money {
	   	int funt;
	   	int sch;
	   	int pens;		
	};
struct money m1;
struct money m2;

//Функция ввода суммы
void vvod(money & p) {
	//Фунты
	cout << "\nВведите количество фунтов: " << endl;
	cin >> p.funt;
	//Шиллинги
	cout << "\nВведите количество шиллингов: " << endl;
	cin >> p.sch;
	//Пенсы
	cout << "\nВведите количество пенсов: " << endl;
	cin >> p.pens;
}

//Функция вывода суммы
void vivod(money & p) {
	cout << p.funt << "-" << p.sch << "-" << p.pens << endl;
}

//Функция перевода суммы в максимальную единицу
void perevodmax(money & p) {
	while(p.pens > 11){
		p.sch++;
		p.pens -= 12;
	}
	while(p.sch > 19){
		p.funt++;
		p.sch -= 20;
	}
}

//Функция перевода суммы в пенсы
void perevodmin(money & p){
	while(p.funt > 0){
		p.funt--;
		p.sch += 20;
	}
	while(p.sch > 0){
		p.sch--;
		p.pens += 12;
	}
}

void summa(money & p, money & o){
	p.funt += o.funt;
	p.sch += o.sch;
	p.pens += o.pens;
	perevodmax(p);
}

void razn(money & p, money & o){
	perevodmin(p);
	perevodmin(o);
	p.pens = p.pens - o.pens;
	perevodmax(p);
}

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int choice;
    //Выбор действия
	do {
		cout << "Выберите действие: \n1 - Вывод суммы в разных форматах, \n2 - Сложить или вычесть две суммы, \n3 - Найти среднее значение сумм, \n4 - Найти самые близкие и самые далёкие по значению суммы, \n\n8 - Выйти из программы." << endl;
		cin >> choice;
		//Менюшка
		switch(choice){
			//Действие: выход из программы
			case 8:
				cout << endl;
				break;
			//Действие: вывод суммы в разных форматах
			case 1:
				int a;
				//Выбор формата
				cout << "\nВыберите формат: 1 - в максимальных единицах, 2 - в пенсах." << endl;
				cin >> a;
				//Перевод в заданном формате
				switch(a){
					//Макс. единица
					case 1:
						vvod(m1);
						cout << "\nИзначальная сумма: " << endl;
						vivod(m1);
						perevodmax(m1);
						cout << "\nСумма после перевода: " << endl;
						vivod(m1);
						break;
					//В пенсы
					case 2:
						vvod(m1);
						cout << "\nИзначальная сумма: " << endl;
						vivod(m1);
						perevodmin(m1);
						cout << "\nСумма после перевода: " << endl;
						vivod(m1);
						break;
					default : break;
				}
				cout << endl;
				break;
			//Действие: сложение или вычитание двух суммы
			case 2:
				int b;
				cout << "\nВведите первую сумму." << endl;
				vvod(m1);
				cout << "\nВведите вторую сумму." << endl;
				vvod(m2);
				cout << "\nПервая сумма:" << endl;
				vivod(m1);
				cout << "\nВторая сумма:" << endl;
				vivod(m2);
				cout << "\nВыберите действие: 1 - сложить, 2 - вычесть" << endl;
				cin >> b;
				//Если сложение
				if (b == 1) {
					summa(m1, m2);
					cout << "\nИтоговая сумма: " << endl;
					vivod(m1);
					cout << endl;
					break;
				}
				//Если вычитание
				if (b == 2){
					perevodmin(m1);
					perevodmin(m2);
					if (m1.pens > m2.pens){
						razn(m1, m2);
						cout << "\nИтоговая разность: " << endl;
						vivod(m1);
					}
					else {
						razn(m2, m1);
						cout << "\nИтоговая разность: " << endl << "\n-";
						vivod(m2);
					}
				}
				break;
			//Действие: среднее значение сумм
			case 3:
                 cout << "\nДанный раздел находится в разработке." << endl;
                 cout << endl;
                 break;
				
			//Действие: пары сумм наиболее близкие и наиболее далекие по значению
			case 4:
				 cout << "\nДанный раздел находится в разработке." << endl;
                 cout << endl;
                 break;
			//Выбрал что-то другое
			default: cout << "\nНеизвестная операция." << endl;
				cout << endl;
				break;
		}
		
	}
	while(choice != 8);
    system("pause");
    return 0;
}

