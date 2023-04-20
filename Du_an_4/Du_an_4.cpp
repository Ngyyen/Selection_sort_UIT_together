#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int Nhap(int**&, int&, int&, const string&);
int Xuat(int**, int, int, const string&);
int Selection_sort(int**, int, int);

int main()
{
	for (int i = 1; i <= 13; ++i) {
		string file_name = "intmatrandata";
		if (i < 10) {
			file_name += "0";
		}
		string num_file = to_string(i);
		string file_in = file_name + num_file + ".inp";
		string file_out = file_name + num_file + ".out";
		int** arr;
		int n, m;
		cout << Nhap(arr, n, m, file_in);
		cout << Selection_sort(arr, n, m);
		cout << Xuat(arr, n, m, file_out);
	}
	return 0;
}

int Nhap(int**& a, int& n, int& m, const string& file_in) {
	ifstream fi(file_in);
	if (fi.fail() == true) {
		return 0;
	}
	fi >> n >> m;
	a = new int* [n];
	for (int i = 0; i < n; ++i) {
		a[i] = new int[m];
	}
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			fi >> a[i][j];
		}
	return 1;
}
int Xuat(int** a, int n, int m, const string& file_out) {
	ofstream fo(file_out);
	if (fo.fail() == true) {
		return 0;
	}
	fo << setw(5) << n << "  " << m << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			fo << setw(5) << a[i][j];
		}
		fo << endl;
	}
	for (int i = 0; i < n; ++i) {
		delete[] a[i];
	}
	delete[]a;
	return 1;
}

int Selection_sort(int** a, int n, int m) {
	for (int i = 0; i <= m * n - 2; ++i) {
		int min_index = i;
		for (int j = i + 1; j <= m * n - 1; ++j) {
			if (a[j / m][j % m] < a[min_index / m][min_index % m]) {
				min_index = j;
			}
		}
		swap(a[i / m][i % m], a[min_index / m][min_index % m]);
	}
	return 2;
}
