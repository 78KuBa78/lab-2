#include <iostream>
#include <chrono>

using namespace std;
using namespace chrono;


void genArr(int arr[], int n) {
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 199 - 99;
    }
}

void printArr() {
	const int n = 100;
	int arr[n];
	genArr(arr, n);
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << "\n\n";
}

void cloneArr(int arr[], int arr2[])
{
	for (int i = 0; i < 100; i++)
		arr2[i] = arr[i];
}

void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
}

void shakerSort(int arr[], int n)
{
	for (int j = 0; j < n - 1; j++)
	{
		for (int i = 0; i < n - 1; i++)
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
			}
		for (int i = 1; i < n; i++)
		{
			if (arr[n - 1 - i] < arr[n - 1 - i - 1])
			{
				swap(arr[n - 1 - i], arr[n - 1 - i - 1]);
			}
		}
	}
}

void combSort(int arr[], int n)
{
	float k = 1.247;
	int S = n - 1, swap, count=0;
	while (S >= 1)
	{
		for (int i = 0; i + S < n; i++)
		{
			if (arr[i] > arr[int(i + S)])
			{
				swap = arr[int(i + S)];
				arr[int(i + S)] = arr[i];
				arr[i] = swap;
			}
		}
		S /= k;
	}
	while (true)
	{
		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = swap;
			}
			else count++;
		}
		if (count == n - 1)
			break;
		else
			count = 0;
	}
}

void insertSort(int arr[], int n)
{
	int i, j, key;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j -= 1;
		}
		arr[j + 1] = key;
	}
}

void quickSort(int arr[], int left, int right)
{
	if (left < right)
	{
		int pivot_value = arr[right];
		int j = left;
		for (int i = left; i < right; i++) {
			if (arr[i] <= pivot_value) {
				swap(arr[j], arr[i]);
				j++;
			}
		}
		swap(arr[j], arr[right]);

		int pivot_index = j;

		quickSort(arr, left, pivot_index - 1);

		quickSort(arr, pivot_index + 1, right);
	}
}

void sortArr() {
	setlocale(0, "RU");
	srand(time(NULL));
	cout << "Неотсортированный массив:\n";
	const int n = 100;
	int arr[n],arr1[n];
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 199 - 99;
		cout << arr[i] << ' ';
	}
	cout << "\n\n";
	cout << "Отсортированный массив bubble_sort: \n";
	cloneArr(arr, arr1);
	auto start1 = steady_clock::now();
	bubbleSort(arr1, n);
	auto end1 = steady_clock::now();
	for (int i = 0; i < n; i++) {
		cout << arr1[i] << ' ';
	}
	auto result1 = duration_cast<nanoseconds>(end1 - start1);
	cout << "\nДлительность bubble_sort: " << result1.count() << " nanoseconds\n";

	cout << "\n======================================\n";

	cout << "\nОтсортированный массив shaker_sort: \n";
	cloneArr(arr, arr1);
	auto start2 = steady_clock::now();
	shakerSort(arr1, n);
	auto end2 = steady_clock::now();

	for (int i = 0; i < n; i++) {
		cout << arr1[i] << ' ';
	}
	auto result2 = duration_cast<nanoseconds>(end2 - start2);
	cout << "\nДлительность skaker_sort: " << result2.count() << " nanoseconds\n";

	cout << "\n======================================\n";
	cout << "\nОтсортированный массив comb_sort: \n";
	cloneArr(arr, arr1);
	auto start3 = steady_clock::now();
	combSort(arr1, n);
	auto end3 = steady_clock::now();
	for (int i = 0; i < n; i++) {
		cout << arr1[i] << ' ';
	}
	auto result3 = duration_cast<nanoseconds>(end3 - start3);
	cout << "\nДлительность comb_sort: " << result3.count() << " nanoseconds\n";
	cout << "\n======================================\n";
	cout << "\nОтсортированный массив insert_sort: \n";
	cloneArr(arr, arr1);
	auto start4 = steady_clock::now();
	insertSort(arr1, n);
	auto end4 = steady_clock::now();
	for (int i = 0; i < n; i++) {
		cout << arr1[i] << ' ';
	}
	auto result4 = duration_cast<nanoseconds>(end4 - start4);
	cout << "\nДлительность insert_sort: " << result4.count() << " nanoseconds\n";
	cout << "\n======================================\n";
	cout << "\nОтсортированный массив quick_sort: \n";
	int left = 0;
	int right = n - 1;
	cloneArr(arr, arr1);
	auto start5 = steady_clock::now();
	quickSort(arr1, left, right);
	auto end5 = steady_clock::now();
	for (int i = 0; i < n; i++) {
		cout << arr1[i] << ' ';
	}
	auto result5 = duration_cast<nanoseconds>(end5 - start5);
	cout << "\nДлительность quick_sort: " << result5.count() << " nanoseconds\n";

	cout << "\n\n";
}

void minmaxEl()
{
	const int n = 100;
	int arr[n];
	genArr(arr, n);	
	cout << "Mассив:\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	int min = arr[0];
	int max = arr[0];
	auto start1 = steady_clock::now();
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		else if (arr[i] < min)
			min = arr[i];
	}
	auto end1 = steady_clock::now();
	cout << "\nHеотсортированный массив:\n\n"
		<< "Мин элемент: " << min << "\n"
		<< "Мак элемент: " << max << "\n";
	auto result1 = duration_cast<nanoseconds>(end1 - start1);
	cout << "Время поиска: " << result1.count() << " nanoseconds\n";
	
	bubbleSort(arr, n);
	auto start = steady_clock::now();
	int min_sort = arr[0];
	int max_sort = arr[99];
	auto end = steady_clock::now();
	cout << "\nОтсортированный массив:\n\n"
		<< "Мин элемент: " << min_sort << "\n"
		<< "Макс элемент: " << max_sort << "\n";
	auto result = duration_cast<nanoseconds>(end - start);
	cout << "Время поиска: " << result.count() << " nanoseconds\n\n";
}

void averageVal()
{
	const int n = 100;
	int arr[n];
	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 199 - 99;
	}
	cout << "\nНеотсортированный массив:\n";
	int min = arr[0];
	int max = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
		else if (arr[i] < min)
			min = arr[i];
	}
	cout << "Мин элемент: " << min << "\n"
		<< "Макс элемент: " << max << "\n";

	int averageV;
	averageV = (max + min) / 2;
	cout << "Среднее значение: " << averageV << "\n";

	bubbleSort(arr, n);

	cout << "\nOтсортированный массив:\n";

	int min_sort = arr[0];
	int max_sort = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] > max_sort)
			max_sort = arr[i];
		else if (arr[i] < min_sort)
			min_sort = arr[i];
	}
	cout << "Мин элемент: " << min_sort << "\n"
		<< "Макc элемент: " << max_sort << "\n";

	int averageVSort;
	averageVSort = (max_sort + min_sort) / 2;
	cout << "Среднее значение: " << averageVSort << "\n\n";
	cout << "Индексы элементов, которые равны среднему значению: ";
	int count = 0;

	auto start = steady_clock::now();

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == int(averageVSort))
		{
			cout << i << ' ';
			count = count + 1;
		}
	}
	auto end = steady_clock::now();
	auto result = duration_cast<nanoseconds>(end - start);
	cout << "\nКоличество таких элементов: " << count;
	cout << "\nДлительность нахождения количества таких элементов: " << result.count() << " nanoseconds\n";
	cout << "\nМассив:\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << "\n\n\n";
}

void lessA()
{
	srand(time(NULL));
	const int n = 100;
	int arr[n];
	genArr(arr, n);
	bubbleSort(arr, n);
	cout << "\nОтсортированный массив:\n\n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << "\n\n";
	int a;
	int count=0;
	cout << "Введите число: ";
	cin >> a;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < a) {
			count += 1;
		}
		if (arr[i] == a) {
			break;
		}
	}
	cout << "\nКоличество элементов в отсортированном массиве, которые меньше введенного числа: " << count;

	cout << "\n\n";
}

void moreB()
{
	srand(time(NULL));
	const int n = 100;
	int arr[n];
	genArr(arr, n);
	bubbleSort(arr, n);
	cout << "\nОтсортированный массив:\n\n";
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << ' ';
	}
	cout << "\n\n";
	int b;
	int count = 0;
	cout << "Введите число: ";
	cin >> b;
	for (int i = n; i > 0; i--)
	{
		if (arr[i] > b) {
			count += 1;
		}
		if (arr[i] == b) {
			break;
		}
	}
		
	cout << "\nКоличество элементов в отсортированном массиве, которые больше введенного числа: " << count;
	cout << "\n\n";
}

int binarySearch(int arr[], int left, int right, int c)
{
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == c) {
			return mid;
		}
		if (arr[mid] > c) {
			right = mid - 1;
		}
		if (arr[mid] < c) {
			left = mid + 1;
		}
	}
	return -1;
}

int searchEl()
{
	srand(time(NULL));
	const int n = 100;
	int arr[n];
	genArr(arr, n);
	bubbleSort(arr, n);
	cout << "\nОтсортированный массив:\n\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << "\n\n";
	int c, count = 0;
	cout << "Введите число для проверки, находится ли оно в массиве: ";
	cin >> c;
	auto start = steady_clock::now();
	for (int i = 0; i < n; i++)
	{
		if (arr[i] == c)
			count += 1;
	}
	auto end = steady_clock::now();
	auto result = duration_cast<nanoseconds>(end - start);
	if (count >= 1)
		cout << "\nВведенное число находится внутри массива!";
	else
		cout << "\nВведенное число не находится внутри массива!";
	cout << "\nДлительность метода перебором: " << result.count() << " nanoseconds";
	int left = 0, right = n - 1;
	auto start1 = steady_clock::now();
	int index = binarySearch(arr, left, right, c);
	auto end1 = steady_clock::now();
	auto result1 = duration_cast<nanoseconds>(end1 - start1);
	cout << "\nДлительность бинарного поиска: " << result1.count() << " nanoseconds";
	cout << "\n\n";
	return 0;
}

void swapEl()
{
	srand(time(NULL));
	const int n = 100;
	int arr[n];
	genArr(arr, n);
	bubbleSort(arr, n);
	cout << "\nОтсортированный массив:\n\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << "\n\n";
	int firstEl, secondEl;
	cout << "Введите два числа, соответсвующие индексам элементов, которые хотите поменять местами: ";
	cin >> firstEl >> secondEl;
	auto start = steady_clock::now();
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == firstEl && j == secondEl)
				swap(arr[i], arr[j]);
		}
	}
	auto end = steady_clock::now();
	auto result = duration_cast<nanoseconds>(end - start);
	cout << "\nИзменненый массив:\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	cout << "\n\nСкорость обмена: " << result.count() << " nanoseconds";
	cout << "\n\n";
}

void idz() {
	const int n = 100;
	int arr[n],arr1[n],x;

	genArr(arr, n);
	cout << "\n\nИзначальный массив:\n";
	for (int i = 0; i < n; i++) {
		cout << arr[i] << ' ';
	}
	for (int i = 0; i < n; i += 1) {
		arr1[i] = arr[i];
	}
	cout << "\n\nВведите число,на которое необходимо уменьшить каждый четный элемент массива\n";
	cin >> x;
	cout << "\n\nПосле уменьшения на выбранное число:\n";
	for (int i = 0; i < n; i += 1) {
		if (i % 2 == 0) {
			arr1[i] = arr[i] - x;
		}
		cout << arr1[i] << ' ';
	}
	cout << "\n\nПосле умноения каждого четного элемента на случайное число в диапазоне от 1 до 9:\n";
	srand(time(NULL));
	for (int i = 0; i < n; i += 1) {
		if (i % 2 == 0) {
			arr1[i] = arr1[i] * (rand() % 9 + 1);
		}
		cout << arr1[i] << ' ';
	}
	int cEven = 0, cOdd = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			if (arr1[i] % 2 == 0) { cEven++; }
		}
		else {
			if (arr1[i] % 2 == 1) { cOdd++; }
		}
	}
	cout << "\n\nКоличество четных на четных местах: " << cEven << "\nКоличество нечетных на нечетных местах: " << cOdd << "\n\n";
	int c = 0;
	cout << "Количество элементов, которые нацело делятся\n";
	for (int i = 1; i < 10; i++) {
		c = 0;
		for (int j = 0; j < n; j++) {
			if (arr1[j] % i == 0) c++;
		}
		cout << "на " << i << ": " << c << endl;
	}
}

void menu()
{
    setlocale(0, "RU");
    int x;
    cout << "Какой пункт вы хотите выбрать?\n"
        << "1 - Создать массив со случайными значениями в диапозоне от -99 до 99\n"
        << "2 - Отсортировать массив различными сортировками\n"
        << "3 - Найти максимальный и минимальный элементы массива\n"
        << "4 - Вывести среднее значение максимального и минимального значения\n"
        << "5 - Вывести количество элементов в отсортированном массиве, которые меньше введенного числа\n"
        << "6 - Вывести количество элементов в отсортированном массиве, которые больше введенного числа\n"
        << "7 - Проверка - есть ли введенное число в отсортированном массиве (бинарный поиск)\n"
        << "8 - Поменять местами элементы массива\n"
		<< "9 - ИДЗ\n"
        << "10 - Выход\n\n";
	cin >> x;

	switch (x)
	{
	case 1:
		printArr();
		menu();
		break;
	case 2:
		sortArr();
		menu();
		break;
	case 3:
		minmaxEl();
		menu();
		break;
	case 4:
		averageVal();
		menu();
		break;
	case 5:
		lessA();
		menu();
		break;
	case 6:
		moreB();
		menu();
		break;
	case 7:
		searchEl();
		menu();
		break;
	case 8:
		swapEl();
		menu();
		break;
	case 9:
		idz();
		menu();
	case 10:
		exit(1);
		break;
	default:
		cout << "Ошибка! Попробуйте снова\n";
		menu();
		break;
	}

}
int main()
{
    menu();
    return 0;
}