#include <iostream>
#include "Linked_list.h"
#include <string>
#include <fstream>
using namespace std;
int main()
{
	for (int i = 1; i <= 13; ++i) {
		string file_name = "intdata";
		if (i < 10) {
			file_name += "0";
		}
		string num_file = to_string(i);
		string file_in = file_name + num_file + ".inp";
		ifstream fi(file_in);
		Linked_list lst;
		lst.Nhap(fi);
		lst.Selection_sort();
		string file_out = file_name + num_file + ".out";
		ofstream fo(file_out);
		lst.print(fo);
	}
	return 0;
}