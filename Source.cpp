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
	int font_size;//размер шрифта
	int number_of_pages;//количество страниц
	T indent_on_the_left;//отступ слева
	T indent_on_the_right;//отступ справа
	T indent_on_the_from_above;//отступ сверху
	T indent_on_the_from_below;//отступ снизу
	char* color;//цвет шрифта
	char* text;// текст
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

template <class T> printer<T>& printer<T>::operator=(const printer<T>& m) {		//(полное имя) ("::" оператор расширения области видимости)
						//если адрес не равен содержимому адресу this
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
	if (font_size < m.font_size) cout << "Размер шрифта = small" << endl;
	if (font_size > m.font_size) cout << "Размер шрифта = big" << endl;
	else cout << "Размер шрифта = ravni" << endl;
	if (number_of_pages < m.number_of_pages) cout << "Количество страниц = small" << endl;
	if (number_of_pages > m.number_of_pages) cout << "Количество страниц = big" << endl;
	else cout << "Количество страниц = ravni" << endl;
	if (indent_on_the_left < m.indent_on_the_left)cout << "Отступ слева = small" << endl;
	if (indent_on_the_left > m.indent_on_the_left)cout << "Отступ слева = big" << endl;
	else cout << "Отступ слева = ravni" << endl;
	if (indent_on_the_right < m.indent_on_the_right)cout << "Отступ справа = small" << endl;
	if (indent_on_the_right > m.indent_on_the_right)cout << "Отступ справа = big" << endl;
	else cout << "Отступ справа = ravni" << endl;
	if (indent_on_the_from_above < m.indent_on_the_from_above)cout << "Отступ сверху = small" << endl;
	if (indent_on_the_from_above > m.indent_on_the_from_above)cout << "Отступ сверху = big" << endl;
	else cout << "Отступ сверху = ravni" << endl;
	if (indent_on_the_from_below < m.indent_on_the_from_below)cout << "Отступ снизу = small" << endl;
	if (indent_on_the_from_below > m.indent_on_the_from_below)cout << "Отступ снизу = big" << endl;
	else cout << "Отступ снизу = ravni" << endl;
	if (strlen(text) < strlen(m.text))cout << "Длина текста = small" << endl;
	if (strlen(text) > strlen(m.text))cout << "Длина текста = big" << endl;
	else cout << "Длина текста = ravni" << endl;

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

template <class T> void printer<T>::print() { //определение функции
	cout << "Размер шрифта " << font_size << endl;//размер шрифта
	cout << "Количество страниц " << number_of_pages << endl;
	cout << "Отступ слева " << indent_on_the_left << endl;//отступ слева
	cout << "Отступ справа " << indent_on_the_right << endl;//отступ справа
	cout << "Отступ сверху " << indent_on_the_from_above << endl;//отступ сверху
	cout << "Отступ снизу " << indent_on_the_from_below << endl;//отступ снизу
	cout << "Цвет шрифта " << color << endl;//цвет шрифта
	cout << "Текст " << text << endl;// текст
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
	char tex[100] = "red text red"; //"Красный цвет это цвет текста";
	char tex1[100] = "reds text red";//"Другой текст для третьего объекта";
	
	cout << "Вводим информацию о первом объекте" << endl << endl;
	lazerni_printer print1(12, 25, 2.5, 3.2, 1.2, 2.5, col, tex, 360, 100);

	cout << "Выводим информацию о первом объекте:" << endl << endl;
	print1.print();

	cout << endl;

	cout << "Копируем информацию из первого объекта во второй" << endl << endl;
	lazerni_printer print2 = print1;

	cout << "Выводим информацию о втором объекте:" << endl << endl;
	print2.print();

	cout << "Вводим информацию о третьем объекте" << endl << endl;
	lazerni_printer print3;

	system("pause");
}
