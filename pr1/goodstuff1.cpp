#include "pch.h"
#include <iostream>
#include <ctime>
//#include <math.h>

using namespace std;

void task1() {
	int a = 2+2*2;
	std::cout <<"Результат вычисления выражения 2+2*2 = " << a << std::endl;
}

void task2() {
	int a = 3;
	int b = 3.994;

	double da = 3;
	double db = 3.14;

	std::cout << a << "\n" << b << "\n" << da << "\n" << db << "\n" << std::endl; // Результат обьясняется тем, что переменная типа int может принимать только целое значение
}

void task3() {
	int a1, b1;
	std::cin >> a1 >> b1;
	std::cout << a1 + b1 << "\n" << a1 - b1 << "\n" << a1 * b1 << "\n" << a1 / b1 << "\n" << std::endl; //при делении выделяется только целая часть, т.к. переменная типа int может принимать только целые значения.
	
	double a2, b2;
	std::cin >> a2 >> b2;
	std::cout << a2 + b2 << "\n" << a2 - b2 << "\n" << a2 * b2 << "\n" << a2 / b2 << "\n" << std::endl;

	int a3; double b3;
	std::cin >> a3 >> b3;
	std::cout << a3 + b3 << "\n" << a3 - b3 << "\n" << a3 * b3 << "\n" << a3 / b3 << "\n" << std::endl;

	double a4; int b4;
	std::cin >> a4 >> b4;
	std::cout << a4 + b4 << "\n" << a4 - b4 << "\n" << a4 * b4 << "\n" << a4 / b4 << "\n" << std::endl;
	
}

void task4() {
	int a, b;
	std::cin >> a >> b;
	
	//с использованием третьей переменной
	int t = a;
	a = b;
	b = t;
	std::cout << a << " " << b << std::endl;

	//без использования третьей переменной
	std::cin >> a >> b;
	a = a + b;
	b = a - b;
	a = a - b;
	std::cout << a << " " << b << std::endl;

}

void task5() {
	double x0, v0, t;
	const double g = -9.8;
	std::cout << "Введите начальную высоту, начальную скорость, и время падения." << std::endl;
	std::cin >> x0 >> v0 >> t;
	//double x = x0 + v0 * t + g * t * t / 2; // в данном случае выражение делит на два только второе t
	//double x1 = x0 + v0 * t + 1 / 2 * g * t * t; // в данном случае выражение тоже неверно
	double x = x0 + v0 * t + (g*t*t) / 2;
	std::cout << "за время t = " << t << ", падая с начальной высоты x0 = " << x0 << "с c начальной скоростью v0 = " << v0 << " тело окажется на координате x = " << x << std::endl;
}

void task6() {
	double a, b, c;
	std::cout << "Введите а, b, c" << std::endl;
	std::cin >> a >> b >> c;
	
	if (a == 0) {
		std::cout << "x1 = -1" << std::endl;
		return;
	}

	double D = b * b - 4 * a * c;
	
	if (D < 0) {
		std::cout << "Нет корней" << std::endl;
	} else if(D!=0){
		double x1 = (-b + sqrt(D)) / (2 * a);
		double x2 = (-b - sqrt(D)) / (2 * a);

		std::cout << "x1 = " << x1 << "\n" << "x2 = " << x2 << std::endl;
	}
	else {
		double x1 = (-b + sqrt(D)) / (2 * a);
		std::cout << "x1 = x2 = " << x1 << std::endl;
	}
}

void task7() {
	int option = 0;
	double S = 0;
	double p = 0;

	std::cout << "Введите метод решения (1 для вычисления по длинам сторон треугольника) (2 для вычисления по координатам вершин) " << std::endl;
	std::cin >>  option;

	switch (option) {
	case 1:
		double a, b, c;
		std::cout << "Введите через пробел длины сторон треугольника" << std::endl;
		std::cin >> a >> b >> c;
		p = 0.5 * (a + b + c); //по формуле Герона
		S = sqrt(p * (p-a) * (p-b) * (p-c));
		std::cout << "S = " << S << std::endl;
		break;

	case 2:
		double x1, y1, x2, y2, x3, y3;
		std::cout << "Введите координаты вершин треугольника" << std::endl;
		std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
		S = 0.5 * abs((x2-x1)*(y3-y1) - (x3-x1)*(y2-y1));
		std::cout << "S = " << S << std::endl;
		break;

	default:
		std::cout << "выберите число 1(расчет по длинам сторон) или 2(расчет по координатам вершин)" << std::endl;
		break;
	}

}

void task8() {
	double a, b, result;
	char op;

	std::cin >> a >> op >> b;
	
	switch (op) {
	case '+':
		result = a + b;
		std::cout << result << std::endl;
		break;

	case '-':
		result = a - b;
		std::cout << result << std::endl;
		break;

	case '*':
		result = a * b;
		std::cout << result << std::endl;
		break;

	case '/':
		result = a / b;
		std::cout << result << std::endl;
		break;

	default:
		std::cout << "Неверный оператор" << std::endl;
		break;
	}
}

void task9() {
	int n;
	srand(unsigned(time(0)));
	
	n = (rand() % 100) + 1;
	
	int gn = 0;

	bool end = false;

	while (!end) {

		bool win = false;
		std::cout << "Угадай число." << std::endl;

		for(int i = 0; i<10; i++){

			std::cin >> gn;

			if (gn == n) {
				std::cout << "Угадал!" << std::endl;
				win = true;
				break;
			}
			if (gn > n) {
				std::cout << "Загаданное число меньше." << std::endl;
				continue;
			}
			if (gn < n) {
				std::cout << "Загаданное число больше." << std::endl;
			}

		}

		if (!win) {
			std::cout << "Вы проиграли. Было загадано: " << n << std::endl;
		}
		int c = 0;

		incorrect:
		std::cout << "Ещё раз? (1 - да; 2 - нет)" << std::endl;
		std::cin >> c;
		switch (c) {
		case 1:
			system("CLS");
			break;
		case 2:
			end = true;
			break;
		default:
			system("CLS");
			goto incorrect;
			break;
		}
	}
}

void task10() {
	int n, p;
	std::cout << "Введите число и степень в которую нужно его ввести." << std::endl;
	std::cin >> n >> p;
	int res = n;
	for (int i = 0; i < p-1; i++) {
		res *= n;
	}
	std::cout << "Ответ: " << res << std::endl;
}

void task11() {
	int n;
	std::cout << "Введите число факториал которого нужно найти." << std::endl;
	std::cin >> n;
	int res = n;
	for (int i = 1; i < n; i++) {
		res *= i;
	}
	std::cout << res << std::endl;
}

void task12() {
	int n;
	bool pr = true;

	cout << "Введите число" << endl;
	cin >> n;

	for (int i = 2; i <= (sqrt(abs(n))); i++) {
		if (n%i == 0) {
			pr = false;
			break;
		}
	}
	if (pr == true)
		cout << "Введенное число простое." << endl;
	else
		cout << "Введенное число составное." << endl;
}

void task13() {
	int n;
	cin >> n;
	int k = 0;
	for (int i = 1; i <= n; i *= 2)
		k++;
	cout << k << endl;
}

void task14() {
	int s;
	int l1, l2, r1, r2;
	int x1 = NULL, x2 = NULL;

	bool found = false;
	cin >> s >> l1 >> r1 >> l2 >> r2;

	for (int i = l1; i <= r1; i++) {
		for (int j = l2; j <= r2; j++) {
			if (i + j == s) {
				//cout << i << " " << j << endl;
				if (i < x1 || x1 == NULL) {
					x1 = i;
					x2 = j;
				}
				found = true;
				break;
			}
		}
	}

	if (!found) {
		cout << -1 << endl;
	}
	else cout << x1 << " " << x2 << endl;
}

void task15() {
	int n;
	cin >> n;
	
	int *a = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	
	for (int i = 1; i <= n; i++) {
		

		int *b = new int[i];

		for (int j = 0; j < i; j++) {
			b[j] = a[j];
			
		}
		
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < i - j - 1; k++) {
				if (b[k] > b[k + 1]) {
					int t = b[k + 1];
					b[k + 1] = b[k];
					b[k] = t;
				}
			}
		}

		int s = i;
		if (s > 5) s = 5;
		for (int j = s-1; j >= 0; j--) {
			cout << b[j] << " ";
		}

		delete[] b;
		cout << endl;
	}

	delete[] a;
}

//
//void trash() {
//	int a = 5;
//	int b = 15;
//	if (a>b);
//	std::cout << a;
//
//}

int main()
{
	setlocale(LC_ALL, "Russian"); //решает проблему вывода текста на русском языке
	
	task12();
	
	return 0;
}
