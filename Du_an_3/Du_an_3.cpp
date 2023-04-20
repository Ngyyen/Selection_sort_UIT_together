#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "Phan_so.h"
using namespace std;

int Nhap(Phan_so*&, int&, const string&);
int Xuat(Phan_so*, int, const string&);
void Selection_sort(Phan_so a[], int n);
int main()
{
	for (int i = 1; i <= 13; ++i) {
		string file_name = "phansodata";
		if (i < 10) {
			file_name += "0";
		}
		string num_file = to_string(i);
		string file_in = file_name + num_file + ".inp";
		string file_out = file_name + num_file + ".out";
		Phan_so* arr;
		int n;
		cout << Nhap(arr, n, file_in);
		Selection_sort(arr, n);
		cout << Xuat(arr, n, file_out);
	}
	return 0;
}

int Nhap(Phan_so*& a, int& n, const string& file_in) {
	ifstream fi(file_in);
	if (fi.fail() == true) {
		return 0;
	}
	fi >> n;
	a = new Phan_so[n];
	for (int i = 0; i < n; ++i) {
		fi >> a[i];
	}
	return 1;
}
int Xuat(Phan_so* a, int n, const string& file_out) {
	ofstream fo(file_out);
	if (fo.fail() == true) {
		return 0;
	}
	fo << setw(5) << n << endl;
	for (int i = 0; i < n; ++i) {
		fo << a[i] << endl;
	}
	delete[] a;
	return 1;
}

void Selection_sort(Phan_so a[], int n) {
	for (int i = n - 1; i >= 1; --i) {
		int max_index = i;
		for (int j = 0; j <= i - 1; ++j) {
			if (a[j] > a[max_index]) {
				max_index = j;
			}
		}
		swap(a[i], a[max_index]);
	}
}
