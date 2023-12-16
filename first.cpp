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
				{
				//количество сумм
				int n;
				cout << "Введите количество денежных сумм: " << endl;
				cin >> n;
				//создание массива
				money *summi = new money[n];
				for (int w = 0; w < n; w++){
					cout << endl << w+1 << " сумма.";
					vvod(summi[w]);
				}
				//вывод значений
				cout << "\nВведённые суммы:" << endl; 
				for (int w = 0; w < n; w++){
					cout << w+1 << ")";
					vivod(summi[w]);
					perevodmin(summi[w]);
				}
				cout << endl;  
				//вычисления
				int sum = 0, srpens;
				for (int i = 0; i < n; i++) sum += summi[i].pens;
				srpens = sum/n;
				m1.funt = 0;
				m1.sch = 0;
				m1.pens = srpens;
				perevodmax(m1);
				cout << "\nСреднее значение введённых сумм: " << endl;
				vivod(m1);
//				cout << "\nРезультат:" << endl; for (int w = 0; w < n; w++) vivod(summi[w]); cout << endl;
				cout << endl;
				break;
			}
				
			//Действие: пары сумм наиболее близкие и наиболее далекие по значению
			case 4:
				{
				//количество сумм
				int m;
				cout << "Введите количество денежных сумм: " << endl;
				cin >> m;
				//создание массива
				money *summ = new money[m];
				for (int w = 0; w < m; w++){
					cout << endl << w+1 << " сумма.";
					vvod(summ[w]);
				}
				//вывод значений
				cout << "\nВведённые суммы, конвертированные в максимальные единицы:" << endl; 
				for (int w = 0; w < m; w++){
					perevodmax(summ[w]);
					cout << w+1 << ")";
					vivod(summ[w]);
					perevodmin(summ[w]);
				}
				cout << endl;  
				
				//сортировка
				for (int l = 0; l < m-1; ++l){
					for (int k = 0; k < m-l-1; ++k){
						if (summ[k].pens > summ[k+1].pens){
							money temp = summ[k];
							summ[k] = summ[k+1];
							summ[k+1] = temp;
						}
					}
				}
				
				int minrazn = summ[m-1].pens;
				for (int i = 0; i < m-1; i++){
					if (summ[i+1].pens - summ[i].pens < minrazn) minrazn = summ[i+1].pens - summ[i].pens;
				}
				
				cout << "\nСамые близкие по значению суммы: " << endl;
				for (int j = 0; j < m-1; j++){
					if (summ[j+1].pens - summ[j].pens == minrazn){
						perevodmax(summ[j]);
						perevodmax(summ[j+1]);
						vivod(summ[j]);
						vivod(summ[j+1]);
					}
				}
				
				
				//вывод
				cout << "\nСамые далёкие: " << endl;
				cout << endl;
				perevodmax(summ[0]);
				perevodmax(summ[m-1]);
				vivod(summ[0]);
				vivod(summ[m-1]);
				cout << endl;
				break;
			}
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

