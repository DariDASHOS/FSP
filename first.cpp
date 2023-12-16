#include <iostream>
#include <windows.h>
using namespace std;

//��������� �����
struct money {
	   	int funt;
	   	int sch;
	   	int pens;		
	};
struct money m1;
struct money m2;

//������� ����� �����
void vvod(money & p) {
	//�����
	cout << "\n������� ���������� ������: " << endl;
	cin >> p.funt;
	//��������
	cout << "\n������� ���������� ���������: " << endl;
	cin >> p.sch;
	//�����
	cout << "\n������� ���������� ������: " << endl;
	cin >> p.pens;
}

//������� ������ �����
void vivod(money & p) {
	cout << p.funt << "-" << p.sch << "-" << p.pens << endl;
}

//������� �������� ����� � ������������ �������
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

//������� �������� ����� � �����
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
    //����� ��������
	do {
		cout << "�������� ��������: \n1 - ����� ����� � ������ ��������, \n2 - ������� ��� ������� ��� �����, \n3 - ����� ������� �������� ����, \n4 - ����� ����� ������� � ����� ������ �� �������� �����, \n\n8 - ����� �� ���������." << endl;
		cin >> choice;
		//�������
		switch(choice){
			//��������: ����� �� ���������
			case 8:
				cout << endl;
				break;
			//��������: ����� ����� � ������ ��������
			case 1:
				int a;
				//����� �������
				cout << "\n�������� ������: 1 - � ������������ ��������, 2 - � ������." << endl;
				cin >> a;
				//������� � �������� �������
				switch(a){
					//����. �������
					case 1:
						vvod(m1);
						cout << "\n����������� �����: " << endl;
						vivod(m1);
						perevodmax(m1);
						cout << "\n����� ����� ��������: " << endl;
						vivod(m1);
						break;
					//� �����
					case 2:
						vvod(m1);
						cout << "\n����������� �����: " << endl;
						vivod(m1);
						perevodmin(m1);
						cout << "\n����� ����� ��������: " << endl;
						vivod(m1);
						break;
					default : break;
				}
				cout << endl;
				break;
			//��������: �������� ��� ��������� ���� �����
			case 2:
				int b;
				cout << "\n������� ������ �����." << endl;
				vvod(m1);
				cout << "\n������� ������ �����." << endl;
				vvod(m2);
				cout << "\n������ �����:" << endl;
				vivod(m1);
				cout << "\n������ �����:" << endl;
				vivod(m2);
				cout << "\n�������� ��������: 1 - �������, 2 - �������" << endl;
				cin >> b;
				//���� ��������
				if (b == 1) {
					summa(m1, m2);
					cout << "\n�������� �����: " << endl;
					vivod(m1);
					cout << endl;
					break;
				}
				//���� ���������
				if (b == 2){
					perevodmin(m1);
					perevodmin(m2);
					if (m1.pens > m2.pens){
						razn(m1, m2);
						cout << "\n�������� ��������: " << endl;
						vivod(m1);
					}
					else {
						razn(m2, m1);
						cout << "\n�������� ��������: " << endl << "\n-";
						vivod(m2);
					}
				}
				break;
			//��������: ������� �������� ����
			case 3:
                 cout << "\n������ ������ ��������� � ����������." << endl;
                 cout << endl;
                 break;
				
			//��������: ���� ���� �������� ������� � �������� ������� �� ��������
			case 4:
				 cout << "\n������ ������ ��������� � ����������." << endl;
                 cout << endl;
                 break;
			//������ ���-�� ������
			default: cout << "\n����������� ��������." << endl;
				cout << endl;
				break;
		}
		
	}
	while(choice != 8);
    system("pause");
    return 0;
}

