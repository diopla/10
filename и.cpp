﻿
#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include<stdexcept>
using namespace std;


double divide(int a, int b)
{
	if (b == 0) {
		throw invalid_argument("Деление на ноль\n");
	}
	return a / b;
}
void age(int a) {
	if (a <= 0 || a > 120) {
		throw invalid_argument("Ошибка в возрасте\n");
	}
	cout << "Ваш возраст " << a << "\n";
}

int sumarray(int mas[], int el) {
	if (el < 0) {
		throw invalid_argument("Ошибка: размер массива отрицательный\n");
	}
	int sum = 0;
	for (int i = 0; i < el; i++) {
		sum += mas[i];
	}
	return sum;
}
double koren(int a) {
	if (a < 0) {
		throw invalid_argument("Ошибка корень отрицательный\n");
	}
	return sqrt(a);
}
template<class T>
void sovpadenie(T mas[], int size, T a) {
	bool sovpad = false;
	for (int i = 0; i < size; i++) {

		if (a == mas[i]) {
			cout << "Совпадение найдено в " << i + 1 << " эллементе массива\n";
			sovpad = true;
		}
	}
	if (sovpad == false) {
		throw invalid_argument("Ошибка совпадений нет\n");
	}
}

#



class Calculator {
public:
	static double add(double a, double b) { return a + b; }
	static double subtract(double a, double b) { return a - b; }
	static double multiply(double a, double b) { return a * b; }
	static double divide(double a, double b) {
		if (b == 0) throw runtime_error("Ошибка: деление на ноль!");
		return a / b;
	}
};


double inputNumber() {
	cout << "Введите число: ";
	double num;
	cin >> num;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		throw runtime_error("Ошибка: введено не число!");
	}
	return num;
}


class Stack {
private:
	vector<int> data;
public:
	void push(int value) { data.push_back(value); }
	int pop() {
		if (data.empty()) throw runtime_error("Ошибка: стек пуст!");
		int value = data.back();
		data.pop_back();
		return value;
	}
};


class Point {
private:
	int x, y;
public:
	Point(int x, int y) : x(x), y(y) {
		if (x < 0 || x > 100 || y < 0 || y > 100)
			throw out_of_range("Ошибка: координаты должны быть от 0 до 100!");
	}
	void print() const { cout << "Точка (" << x << ", " << y << ")" << endl; }
};


string readFile(const string& filename) {
	ifstream file(filename);
	if (!file.is_open()) throw runtime_error("Ошибка: файл не найден!");

	string content((istreambuf_iterator<char>(file)),
		istreambuf_iterator<char>());
	file.close();
	return content;
}

class StringArray {
private:
	vector<string> strings;
public:
	void addString(const string& str) { strings.push_back(str); }
	string getString(size_t index) const {
		if (index >= strings.size())
			throw out_of_range("Ошибка: индекс выходит за границы массива!");
		return strings[index];
	}
};


class Square {
private:
	double side;
public:
	Square(double side) : side(side) {
		if (side <= 0) throw invalid_argument("Ошибка: сторона квадрата должна быть положительной!");
	}
	double area() const { return side * side; }
};





class FileHandler {
private:
	ifstream file;
public:
	FileHandler(const string& filename) {
		file.open(filename);
		if (!file.is_open()) throw runtime_error("Ошибка: не удалось открыть файл!");
	}
	~FileHandler() { if (file.is_open()) file.close(); }
	string readContent() {
		return string((istreambuf_iterator<char>(file)),
			istreambuf_iterator<char>());
	}
};


int main()
{
	setlocale(LC_ALL, "Ru");





	try
	{
		cout << "Результат деления " << divide(50, 0) << "\n";
	}
	catch (const std::invalid_argument& e)
	{
		cerr << e.what() << "\n";
	}


	try
	{
		age(-2);
	}
	catch (const std::invalid_argument& e)
	{
		cerr << e.what() << "\n";
	}


	int mas[10] = { 1,2,3,4,5,6,7,8,9,0 };
	try
	{
		cout << "сумма элементов массива равна :" << sumarray(mas, -1) << "\n";
	}
	catch (const std::invalid_argument& e)
	{
		cerr << e.what() << "\n";
	}


	try {
		cout << "Корень числа равен: " << koren(-2) << "\n";
	}
	catch (const std::invalid_argument& e)
	{
		cerr << e.what() << "\n";
	}


	int mas1[4] = { 2,3,4,1 };
	string mas21[6] = { "ура","практическая","по","системному","программированию","!" };
	try {
		sovpadenie(mas1, 4, 1);
		sovpadenie(mas21, 6, string("по"));
	}
	catch (const std::invalid_argument& e)
	{
		cerr << e.what() << "\n";
	}
	try {

		cout << "5 + 3 = " << Calculator::add(5, 3) << endl;
		cout << "5 / 0 = ";
		cout << Calculator::divide(5, 0) << endl;
	}
	catch (const runtime_error& e) {
		cout << e.what() << endl;
	}

	try {

		double num = inputNumber();
		cout << "Вы ввели: " << num << endl;
	}
	catch (const runtime_error& e) {
		cout << e.what() << endl;
	}

	try {

		Stack s;
		s.push(10);
		cout << "Извлечено из стека: " << s.pop() << endl;
		cout << "Извлечено из стека: " << s.pop() << endl;
	}
	catch (const runtime_error& e) {
		cout << e.what() << endl;
	}

	try {

		Point p(50, 50);
		p.print();
		Point p2(-1, 101);
	}
	catch (const out_of_range& e) {
		cout << e.what() << endl;
	}

	try {

		string content = readFile("test.txt");
		cout << "Содержимое файла: " << content << endl;
	}
	catch (const runtime_error& e) {
		cout << e.what() << endl;
	}

	try {

		StringArray sa;
		sa.addString("Привет");
		sa.addString("Мир");
		cout << "Строка 0: " << sa.getString(0) << endl;
		cout << "Строка 2: " << sa.getString(2) << endl;
	}
	catch (const out_of_range& e) {
		cout << e.what() << endl;
	}

	try {

		Square sq(5);
		cout << "Площадь квадрата: " << sq.area() << endl;
		Square sq2(-1);
	}
	catch (const invalid_argument& e) {
		cout << e.what() << endl;
	}




	try {

		Square sq(-5);
	}
	catch (const runtime_error& e) {
		cout << "Ошибка выполнения: " << e.what() << endl;
	}
	catch (const out_of_range& e) {
		cout << "Ошибка диапазона: " << e.what() << endl;
	}
	catch (const invalid_argument& e) {
		cout << "Ошибка аргумента: " << e.what() << endl;
	}
	catch (...) {
		cout << "Неизвестная ошибка!" << endl;
	}








}