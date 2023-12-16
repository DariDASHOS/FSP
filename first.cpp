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
				{
				//���������� ����
				int n;
				cout << "������� ���������� �������� ����: " << endl;
				cin >> n;
				//�������� �������
				money *summi = new money[n];
				for (int w = 0; w < n; w++){
					cout << endl << w+1 << " �����.";
					vvod(summi[w]);
				}
				//����� ��������
				cout << "\n�������� �����:" << endl; 
				for (int w = 0; w < n; w++){
					cout << w+1 << ")";
					vivod(summi[w]);
					perevodmin(summi[w]);
				}
				cout << endl;  
				//����������
				int sum = 0, srpens;
				for (int i = 0; i < n; i++) sum += summi[i].pens;
				srpens = sum/n;
				m1.funt = 0;
				m1.sch = 0;
				m1.pens = srpens;
				perevodmax(m1);
				cout << "\n������� �������� �������� ����: " << endl;
				vivod(m1);
//				cout << "\n���������:" << endl; for (int w = 0; w < n; w++) vivod(summi[w]); cout << endl;
				cout << endl;
				break;
			}
				
			//��������: ���� ���� �������� ������� � �������� ������� �� ��������
			case 4:
				{
				//���������� ����
				int m;
				cout << "������� ���������� �������� ����: " << endl;
				cin >> m;
				//�������� �������
				money *summ = new money[m];
				for (int w = 0; w < m; w++){
					cout << endl << w+1 << " �����.";
					vvod(summ[w]);
				}
				//����� ��������
				cout << "\n�������� �����, ���������������� � ������������ �������:" << endl; 
				for (int w = 0; w < m; w++){
					perevodmax(summ[w]);
					cout << w+1 << ")";
					vivod(summ[w]);
					perevodmin(summ[w]);
				}
				cout << endl;  
				
				//����������
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
				
				cout << "\n����� ������� �� �������� �����: " << endl;
				for (int j = 0; j < m-1; j++){
					if (summ[j+1].pens - summ[j].pens == minrazn){
						perevodmax(summ[j]);
						perevodmax(summ[j+1]);
						vivod(summ[j]);
						vivod(summ[j+1]);
					}
				}
				
				
				//�����
				cout << "\n����� ������: " << endl;
				cout << endl;
				perevodmax(summ[0]);
				perevodmax(summ[m-1]);
				vivod(summ[0]);
				vivod(summ[m-1]);
				cout << endl;
				break;
			}
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

