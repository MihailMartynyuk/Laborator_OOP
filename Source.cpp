//#include "stdafx.h"
#include "iostream"
#include <string>
#include <string.h>
#include <cstring>

using namespace std;
template <class T>
class printer {
public:
	printer();
	printer(int a, int n, T b, T c, T d, T e, char* f, char* g);
	printer& operator=(const printer& m);
	//~printer();
	void print();
	printer& operator+=(const printer& m2);
	printer& operator>(const printer& m);
	printer& operator+(const printer& m);	

protected:
	int font_size;//������ ������
	int number_of_pages;//���������� �������
	T indent_on_the_left;//������ �����
	T indent_on_the_right;//������ ������
	T indent_on_the_from_above;//������ ������
	T indent_on_the_from_below;//������ �����
	char* color;//���� ������
	char* text;// �����
private:

};
template <class T> printer<T>::printer() {
	font_size = 1;
	number_of_pages = 2;
	indent_on_the_left = 3;
	indent_on_the_right = 4;
	indent_on_the_from_above = 5;
	indent_on_the_from_below = 6;
	char f[100] = "not text";
	//delete[]color;
	color = new char[strlen(f) + 1];
	strcpy(color, f);
	char g[100] = "not text";
	//delete[]text;
	text = new char[strlen(g) + 1];
	strcpy(text, g);
}
template <class T> printer<T>::printer(int a, int n, T b, T c, T d, T e, char* f, char* g) {
	font_size = a;
	number_of_pages = n;
	indent_on_the_left = b;
	indent_on_the_right = c;
	indent_on_the_from_above = d;
	indent_on_the_from_below = e;
	//delete[]color;
	color = new char[strlen(f) + 1];
	strcpy(color, f);
	//delete[]text;
	text = new char[strlen(g) + 1];
	strcpy(text, g);
}

/*template <class T> printer<T>::~printer() {delete[]color;delete[]text;}*/

template <class T> printer<T>& printer<T>::operator=(const printer<T>& m) {		//(������ ���) ("::" �������� ���������� ������� ���������)
						//���� ����� �� ����� ����������� ������ this
	font_size = m.font_size;
	number_of_pages = m.number_of_pages;
	indent_on_the_left = m.indent_on_the_left;
	indent_on_the_right = m.indent_on_the_right;
	indent_on_the_from_above = m.indent_on_the_from_above;
	indent_on_the_from_below = m.indent_on_the_from_below;
	color = new char[strlen(m.color) + 1];
	strcpy(color, m.color);
	text = new char[strlen(m.text) + 1];
	strcpy(text, m.text);
	return *this;
}


template <class T> printer<T>& printer<T>::operator>(const printer<T>& m)
{
	if (font_size < m.font_size) cout << "������ ������ = small" << endl;
	if (font_size > m.font_size) cout << "������ ������ = big" << endl;
	else cout << "������ ������ = ravni" << endl;
	if (number_of_pages < m.number_of_pages) cout << "���������� ������� = small" << endl;
	if (number_of_pages > m.number_of_pages) cout << "���������� ������� = big" << endl;
	else cout << "���������� ������� = ravni" << endl;
	if (indent_on_the_left < m.indent_on_the_left)cout << "������ ����� = small" << endl;
	if (indent_on_the_left > m.indent_on_the_left)cout << "������ ����� = big" << endl;
	else cout << "������ ����� = ravni" << endl;
	if (indent_on_the_right < m.indent_on_the_right)cout << "������ ������ = small" << endl;
	if (indent_on_the_right > m.indent_on_the_right)cout << "������ ������ = big" << endl;
	else cout << "������ ������ = ravni" << endl;
	if (indent_on_the_from_above < m.indent_on_the_from_above)cout << "������ ������ = small" << endl;
	if (indent_on_the_from_above > m.indent_on_the_from_above)cout << "������ ������ = big" << endl;
	else cout << "������ ������ = ravni" << endl;
	if (indent_on_the_from_below < m.indent_on_the_from_below)cout << "������ ����� = small" << endl;
	if (indent_on_the_from_below > m.indent_on_the_from_below)cout << "������ ����� = big" << endl;
	else cout << "������ ����� = ravni" << endl;
	if (strlen(text) < strlen(m.text))cout << "����� ������ = small" << endl;
	if (strlen(text) > strlen(m.text))cout << "����� ������ = big" << endl;
	else cout << "����� ������ = ravni" << endl;

	return (*this);
}


template <class T> printer<T>& printer<T>::operator+=(const printer<T>& m)
{
	int dlin;

	font_size = font_size + m.font_size;
	number_of_pages = number_of_pages + m.number_of_pages;
	indent_on_the_left = indent_on_the_left + m.indent_on_the_left;
	indent_on_the_right = indent_on_the_right + m.indent_on_the_right;
	indent_on_the_from_above = indent_on_the_from_above + m.indent_on_the_from_above;
	indent_on_the_from_below = indent_on_the_from_below + m.indent_on_the_from_below;

	dlin = strlen(color) + strlen(m.color);
	if (strlen(color) < strlen(m.color))	color = new char[strlen(m.color) + 1];
	else color = new char[strlen(color) + 1];
	sprintf(color, "%d", dlin);

	dlin = strlen(color) + strlen(m.color);
	if (strlen(text) < strlen(m.text))	text = new char[strlen(m.text) + 1];
	else text = new char[strlen(text) + 1];
	sprintf(text, "%d", dlin);
	return (*this);
}


template <class T> printer<T>& printer<T>::operator+(const printer<T>& m)
{
	printer n;
	int dlin;
	n.font_size = font_size + m.font_size;
	n.number_of_pages = number_of_pages + m.number_of_pages;
	n.indent_on_the_left = indent_on_the_left + m.indent_on_the_left;
	n.indent_on_the_right = indent_on_the_right + m.indent_on_the_right;
	n.indent_on_the_from_above = indent_on_the_from_above + m.indent_on_the_from_above;
	n.indent_on_the_from_below = indent_on_the_from_below + m.indent_on_the_from_below;

	dlin = strlen(color) + strlen(m.color);
	if (strlen(color) < strlen(m.color))	n.color = new char[strlen(m.color) + 1];
	else color = new char[strlen(color) + 1];
	sprintf(n.color, "%d", dlin);

	dlin = strlen(color) + strlen(m.color);
	if (strlen(text) < strlen(m.text))	n.text = new char[strlen(m.text) + 1];
	else n.text = new char[strlen(text) + 1];
	sprintf(n.text, "%d", dlin);
	return n;
}

template <class T> void printer<T>::print() { //����������� �������
	cout << "������ ������ " << font_size << endl;//������ ������
	cout << "���������� ������� " << number_of_pages << endl;
	cout << "������ ����� " << indent_on_the_left << endl;//������ �����
	cout << "������ ������ " << indent_on_the_right << endl;//������ ������
	cout << "������ ������ " << indent_on_the_from_above << endl;//������ ������
	cout << "������ ����� " << indent_on_the_from_below << endl;//������ �����
	cout << "���� ������ " << color << endl;//���� ������
	cout << "����� " << text << endl;// �����
}






class lazerni_printer:public printer<int> {
public:
	lazerni_printer();
	lazerni_printer(int a, int n, int b, int c, int d, int e, char* f, char* g, int k, int s);
	void print();
	lazerni_printer& operator=(const lazerni_printer& m);
	lazerni_printer& operator+(const lazerni_printer& m);
private:
	int kol_ener;
	int skorost;
};

lazerni_printer::lazerni_printer():printer<int>::printer() {
	kol_ener = 360;
	skorost = 100;
}

lazerni_printer::lazerni_printer(int a, int n, int b, int c, int d, int e, char* f, char* g, int k, int s):printer<int>::printer(a, n, b, c, d, e, f, g) {
	kol_ener = k;
	skorost = s;
}

void lazerni_printer::print(){
	printer<int>::print();
	cout << "kol_ener " << kol_ener << endl;
	cout << "skorost " << skorost << endl;
}

lazerni_printer& lazerni_printer::operator=(const lazerni_printer& m) {
	printer<int>::operator=(m);
	kol_ener = m.kol_ener;
	skorost = m.skorost;
	return *this;
}

lazerni_printer& lazerni_printer::operator+(const lazerni_printer& m)
{	
	lazerni_printer n;
	n.kol_ener = kol_ener + m.kol_ener;
	n.skorost = skorost + m.skorost;
	return n;
}


int main() {
	setlocale(LC_ALL, "Russian");
	char col[10] = "red";
	char tex[100] = "red text red"; //"������� ���� ��� ���� ������";
	char tex1[100] = "reds text red";//"������ ����� ��� �������� �������";
	
	cout << "������ ���������� � ������ �������" << endl << endl;
	lazerni_printer print1(12, 25, 2.5, 3.2, 1.2, 2.5, col, tex, 360, 100);

	cout << "������� ���������� � ������ �������:" << endl << endl;
	print1.print();

	cout << endl;

	cout << "�������� ���������� �� ������� ������� �� ������" << endl << endl;
	lazerni_printer print2 = print1;

	cout << "������� ���������� � ������ �������:" << endl << endl;
	print2.print();

	cout << "������ ���������� � ������� �������" << endl << endl;
	lazerni_printer print3;

	system("pause");
}
