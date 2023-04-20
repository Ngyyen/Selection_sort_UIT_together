#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream>
#include <iomanip>
using namespace std;

class Node {
public:
	Node() = default;
	Node(int data) {
		this->data = data;
		next = NULL;
	}
	int data = 0;
	Node* next = NULL;
};

class Linked_list {
public:
	Linked_list() = default;
	Linked_list(int data) {
		Node* new_node = new Node(data);
		head = new_node;
		tail = new_node;
		size++;
	}
	Node* get(int index);
	void append(int data);
	void prepend(int data);
	void insert(int index, int data);
	void remove(int index);
	void reverse();
	void best_reverse();
	void Nhap(istream&);
	void print(ostream&);
	void Interchange_sort();
	void Bubble_sort();
	void Selection_sort();

	Node* head = NULL;
	Node* tail = NULL;
	size_t size = 0;
};

void Linked_list::append(int data) {
	Node* new_node = new Node(data);
	if (head == NULL) {
		head = new_node;
		tail = new_node;
		size++;
		return;
	}
	tail->next = new_node;
	tail = new_node;
	size++;
}

void Linked_list::prepend(int data) {
	Node* new_node = new Node(data);
	if (head == NULL) {
		head = new_node;
		tail = new_node;
		size++;
		return;
	}
	new_node->next = head;
	head = new_node;
	size++;
}

void Linked_list::insert(int index, int data) {
	if (index == 0) {
		this->prepend(data);
		return;
	}
	if (index == size) {
		this->append(data);
		return;
	}
	Node* ite = this->get(index - 1);
	// ite is currently points to node before insert location
	Node* new_node = new Node(data);
	new_node->next = ite->next;
	ite->next = new_node;
	++size;
}

void Linked_list::remove(int index) {
	if (index == 0) {
		head = head->next;
		--size;
		return;
	}
	Node* ite = this->get(index - 1);
	// ite is currently points to node before delete location
	ite->next = ite->next->next;
	--size;
	if (index == size) {
		tail = ite;
	}
}

void Linked_list::print(ostream& os) {
	Node* ite = head;
	while (ite != NULL) {
		os << setw(5) << ite->data;
		ite = ite->next;
	}
	os << endl;
}

Node* Linked_list::get(int index) {
	int i = 0;
	Node* ite = head;
	while (i < index) {
		ite = ite->next;
		++i;
	}
	return ite;
}

void Linked_list::reverse() {
	Node* ite = tail;
	Node* temp = tail;
	for (int i = size - 2; i >= 0; --i) {
		ite->next = this->get(i);
		ite = ite->next;
	}
	ite->next = NULL;
	head = temp;
	tail = ite;
}

void Linked_list::best_reverse() {
	Node* temp = head;
	Node* current = head;
	Node* next = NULL;
	Node* prev = NULL;
	while (current != NULL) {
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
	tail = temp;
}

void Linked_list::Nhap(istream& is) {
	int n;
	is >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		is >> x;
		this->append(x);
	}
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void Linked_list::Interchange_sort() {
	for (Node* ite1 = head; ite1->next != NULL; ite1 = ite1->next)
		for (Node* ite2 = ite1->next; ite2 != NULL; ite2 = ite2->next) {
			if (ite1->data > ite2->data) {
				swap(ite1->data, ite2->data);
			}
		}
}

void Linked_list::Bubble_sort() {
	int index = this->size - 1;
	for (Node* ite1 = tail; ite1 != head; ite1 = this->get(index--)) {
		for (Node* ite2 = head; ite2 != ite1; ite2 = ite2->next) {
			if (ite2->data > ite1->data) {
				swap(ite2->data, ite1->data);
			}
		}
	}
}

void Linked_list::Selection_sort() {
	for (Node* ite1 = head; ite1 != tail; ite1 = ite1->next) {
		Node* min_ite = ite1;
		for (Node* ite2 = ite1->next; ite2 != NULL; ite2 = ite2->next) {
			if (ite2->data < min_ite->data) {
				min_ite = ite2;
			}
		}
		swap(min_ite->data, ite1->data);
	}
}

#endif