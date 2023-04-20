
#include <iostream>
using namespace std;

class Node2 {
public:
	Node2() = default;
	Node2(int data) {
		this->data = data;
		next = NULL;
		prev = NULL;
	}
	int data = 0;
	Node2* next = NULL;
	Node2* prev = NULL;
};

class Double_linked_list {
public:
	Double_linked_list() = default;
	Double_linked_list(int data) {
		Node2* new_node = new Node2(data);
		head = new_node;
		tail = new_node;
		size++;
	}
	void append(int data);
	void prepend(int data);
	void insert(int index, int data);
	void remove(int index);
	void Nhap(istream&);
	void print(ostream&);
	void best_reverse();
	void Bubble_sort();
	void Selection_sort();

	Node2* head = NULL;
	Node2* tail = NULL;
	size_t size = 0;
};

void Double_linked_list::append(int data) {
	Node2* new_node = new Node2(data);
	if (head == NULL) {
		head = new_node;
		tail = new_node;
		size++;
		return;
	}
	tail->next = new_node;
	new_node->prev = tail;
	tail = new_node;
	size++;
}

void Double_linked_list::prepend(int data) {
	Node2* new_node = new Node2(data);
	if (head == NULL) {
		head = new_node;
		tail = new_node;
		size++;
		return;
	}
	new_node->next = head;
	head->prev = new_node;
	head = new_node;
	size++;
}

void Double_linked_list::insert(int index, int data) {
	if (index == 0) {
		this->prepend(data);
		return;
	}
	if (index == size) {
		this->append(data);
		return;
	}
	Node2* pre = head;
	int i = 0;
	while (i < index - 1) {
		pre = pre->next;
		++i;
	}
	// pre is currently pointed to node before insert location
	Node2* new_node = new Node2(data);
	new_node->next = pre->next;
	pre->next = new_node;
	new_node->prev = pre;
	new_node->next->prev = new_node;
	++size;
}

void Double_linked_list::remove(int index) {
	if (index == 0) {
		head = head->next;
		head->prev = NULL;
		--size;
		return;
	}
	if (index == size - 1) {
		tail = tail->prev;
		tail->next = NULL;
		--size;
		return;
	}
	Node2* pre = head;
	int i = 0;
	while (i < index - 1) {
		pre = pre->next;
		++i;
	}
	// pre is currently pointed to node before delete location
	pre->next = pre->next->next;
	pre->next->prev = pre;
	--size;
}

void Double_linked_list::Nhap(istream& is) {
	int n;
	is >> n;
	for (int i = 0; i < n; ++i) {
		int x;
		is >> x;
		this->append(x);
	}
}

void Double_linked_list::print(ostream& os) {
	Node2* ite = head;
	while (ite != NULL) {
		os << "<-" << ite->data << "->";
		ite = ite->next;
	}
	os << endl;
}

void Double_linked_list::best_reverse() {
	Node2* prev = NULL;
	Node2* current = head;
	Node2* next = NULL;
	Node2* new_head = tail;
	Node2* new_tail = head;
	while (current != NULL) {
		prev = current->prev;
		next = current->next;
		current->prev = next;
		current->next = prev;
		current = next;
	}
	head = new_head;
	tail = new_tail;
}

void Double_linked_list::Bubble_sort() {
	for (Node2* ite1 = tail; ite1 != head; ite1 = ite1->prev) {
		for (Node2* ite2 = head; ite2 != ite1; ite2 = ite2->next) {
			if (ite2->data > ite1->data) {
				swap(ite2->data, ite1->data);
			}
		}
	}
}

void Double_linked_list::Selection_sort() {
	for (Node2* ite1 = head; ite1 != tail; ite1 = ite1->next) {
		Node2* min_ite = ite1;
		for (Node2* ite2 = ite1->next; ite2 != NULL; ite2 = ite2->next) {
			if (ite2->data < min_ite->data) {
				min_ite = ite2;
			}
		}
		swap(min_ite->data, ite1->data);
	}
}


