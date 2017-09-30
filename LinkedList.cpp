#include <iostream>

using namespace std;

class node 
{
	public:
		node(){};

		int data_;
		node* next_;
};

class LinkedList
{
	public:
		LinkedList() {};
		void AddNode(const int& d);
		void Print();
		void RemoveNode(const int& d);

		node* head_ {nullptr};
};

void LinkedList::AddNode(const int& d)
{
	node* new_node = new node();
	new_node->data_ = d;
	new_node->next_ = head_;
	head_ = new_node;
};

void LinkedList::Print()
{
	node* current_node = head_;
	cout << "head-->";
	do {
		cout << current_node->data_ << " - ";
		current_node = current_node->next_;
	} while (current_node);
	cout << "NULL" << endl;
};

void LinkedList::RemoveNode(const int& d)
{
	node* current_node = head_;
	node* last_node = nullptr;

	/* search for node with data to remove */
	while (current_node->data_ != d) {
		last_node = current_node;
		current_node = current_node->next_;
		if (!current_node) {
			cout << "node "<<d<<" not found!" << endl;
			return;
		}
	}

	/* fix pointers of the remaining nodes */
	if (current_node == head_)
		head_ = current_node->next_;
	else
		last_node->next_ = current_node->next_;

	delete current_node;
};

int main()
{
	LinkedList l;
	l.AddNode(3);
	l.AddNode(4);
	l.AddNode(5);
	l.AddNode(6);
	l.AddNode(7);
	l.Print();
	
	int x;
	do {
		cout << "enter node to remove (0 to exit): ";
		scanf("%d",&x);
		l.RemoveNode(x);
		l.Print();
	} while (x != 0);

	return 0;
}
