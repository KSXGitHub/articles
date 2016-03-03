
#include <iostream>
#include <limits>

using namespace std;

template <class Data>
struct Node {
	Data data;
	Node *next;
	Node (Data data, Node *next = NULL) {
		Node::data = data;
		Node::next = next;
	}
};

template <class Data>
struct List {
	Node<Data> *head;
	List () {
		head = NULL;
	}
	void insertHead(Node<Data> *newhead) {
		newhead->next = head;
		head = newhead;
	}
	Node<Data> *insertHead(Data data) {
		auto newhead = new Node<Data>(data);
		insertHead(newhead);
		return newhead;
	}
	bool disposeHead() {
		if (head) {
			auto newhead = head->next;
			delete head;
			head = newhead;
			return true;
		} else {
			return false;
		}
	}
	bool findAndDispose(Data data) {
		if (!head) {
			return false;
		}
		if (head->data == data) {
			auto newhead = head->next;
			delete head;
			head = newhead;
			return true;
		}
		for (auto prev = head; ; ) {
			auto node = prev->next;
			if (node) {
				if (node->data == data) {
					disposeAfter(prev);
					return true;
				}
				prev = prev->next;
			} else {
				return false;
			}
		}
	}
	void sort(bool (*compare)(Data, Data)) {
		constexpr auto swap = [](Data &a, Data &b) {
			auto t = a;
			a = b;
			b = t;
		};
		for (auto i = head; i; i = i->next) {
			for (auto j = i; j; j = j->next) {
				if (compare(i->data, j->data)) {
					swap(i->data, j->data);
				}
			}
		}
	}
	void insertAfter(Node<Data> *position, Node<Data> *newnode) {
		if (position) {
			newnode->next = position->next;
			position->next = newnode;
		} else {
			insertHead(newnode);
		}
	}
	Node<Data> *insertAfter(Node<Data> *position, Data data) {
		auto newnode = new Node<Data>(data);
		insertAfter(position, newnode);
		return newnode;
	}
	Node<Data> *removeAfter(Node<Data> *position) {
		auto node = position->next;
		position->next = node->next;
		return node;
	}
	bool disposeAfter(Node<Data> *position) {
		auto node = removeAfter(position);
		if (node) {
			delete node;
			return true;
		} else {
			return false;
		}
	}
	void clear() {
		auto node = head;
		head = NULL;
		while (node) {
			auto newnode = node->next;
			delete node;
			node = newnode;
		}
	}
	~List () {
		clear();
	}
};

typedef void (*Action)(List<int> &);

int main();

Action getAction();

void inputList(List<int> &);
void printList(List<int> &);
void findInList(List<int> &);
void disposeHead(List<int> &);
void findAndDispose(List<int> &);
void sortAndInsert(List<int> &);
void printInvalidSelectionError(List<int> &);

constexpr Action ACTIONS[] = {
	NULL, &inputList, &printList, &findInList, &disposeHead, &findAndDispose, &sortAndInsert
};

constexpr auto LENGTH_OF_ACTIONS = sizeof(ACTIONS) / sizeof(Action);
constexpr char SELECTION_BEGIN = '0';
constexpr char SELECTION_END = SELECTION_BEGIN + LENGTH_OF_ACTIONS - 1;

void waitUserEnter();
int findInList(List<int>, int);

namespace sorted {
	void askForInsertion(List<int> &);
	void insert(List<int> &, int);
}

int main() {
	List<int> list;
	for ( ; ; ) {
		auto act = getAction();
		if (!act) {
			return 0;
		}
		act(list);
	}
	return 0;
}

Action getAction() {
	constexpr char ASK_FOR_ACTION[] =
		"\x1B[35mChon hanh dong:\n"
		"  \x1B[32m[0] \x1B[36m->\x1B[0m Thoat\n"
		"  \x1B[32m[1] \x1B[36m->\x1B[0m Nhap danh sach \x1B[31m(Danh sach se bi lam trong)\x1B[0m\n"
		"  \x1B[32m[2] \x1B[36m->\x1B[0m Xem danh sach\n"
		"  \x1B[32m[3] \x1B[36m->\x1B[0m Tim x trong danh sach\n"
		"  \x1B[32m[4] \x1B[36m->\x1B[0m Xoa phan tu dau danh sach\n"
		"  \x1B[32m[5] \x1B[36m->\x1B[0m Tim va xoa 1 phan tu x khoi danh sach\n"
		"  \x1B[32m[6] \x1B[36m->\x1B[0m Sap xep theo thu tu tang dan, chen x vao mang da sap xep\n"
		" Nhap mot ki tu: "
	;
	char selection;
	cout << ASK_FOR_ACTION;
	cin >> selection;
	return selection < SELECTION_BEGIN || selection > SELECTION_END ? &printInvalidSelectionError : ACTIONS[selection - '0'];
}

void inputList(List<int> &list) {
	unsigned count;
	list.clear();
	cerr << "Da lam trong danh sach\n";
	cout << "So luong va cac phan tu hoac nhap 0 de lam trong danh sach: ";
	cin >> count;
	if (count) {
		int data;
		cin >> data;
		auto prev = list.insertHead(data);
		for ( ; ; ) {
			--count;
			if (count) {
				cin >> data;
				prev = list.insertAfter(prev, data);
			} else {
				return;
			}
		}
	}
}

void printList(List<int> &list) {
	cout << "List: ";
	for (auto node = list.head; node; node = node->next) {
		cout << '\x20' << node->data;
	}
	cout << endl;
	waitUserEnter();
}

void findInList(List<int> &list) {
	int x;
	cout << "Nhap mot so nguyen: ";
	cin >> x;
	auto index = findInList(list, x);
	if (index == -1) {
		cout << "Khong tim thay " << x << endl;
	} else {
		cout << "Tim thay " << x << " tai vi tri " << index << " (Quy uoc phan tu dau co vi tri 0)\n";
	}
	waitUserEnter();
}

void disposeHead(List<int> &list) {
	if (list.disposeHead()) {
		cout << "Da xoa mot head\n";
		printList(list);
	} else {
		cerr << "Danh sach trong\n";
		waitUserEnter();
	}
}

void findAndDispose(List<int> &list) {
	int x;
	cout << "Nhap mot so nguyen: ";
	cin >> x;
	if (list.findAndDispose(x)) {
		cout << "Da xoa mot phan tu co khoa " << x << " khoi danh sach\n";
		printList(list);
	} else {
		cerr << "Khong co phan tu nao co khoa " << x << endl;
		waitUserEnter();
	}
}

void sortAndInsert(List<int> &list) {
	constexpr auto INCREMENT_SORT = [](int left, int right) {
		return left > right;
	};
	list.sort(INCREMENT_SORT);
	cout << "Da sap xep xong\n";
	printList(list);
	sorted::askForInsertion(list);
}

void printInvalidSelectionError(List<int> &) {
	cerr << "Lua chon khong hop le\n";
	waitUserEnter();
}

void waitUserEnter() {
	cin.get();
	cout << "Nhan \x1B[32mENTER\x1B[0m de tiep tuc...";
	cin.get();
	cout << endl;
}

int findInList(List<int> list, int x) {
	int count = 0;
	for (auto node = list.head; node; node = node->next) {
		if (node->data == x) {
			return count;
		} else {
			++count;
		}
	}
	return -1;
}

void sorted::askForInsertion(List<int> &list) {
	unsigned count;
	cout << "Nhap so luong va cac phan tu can chen: ";
	for (cin >> count; count; --count) {
		unsigned x;
		cin >> x;
		sorted::insert(list, x);
	}
	cout << "Da chen\n";
	printList(list);
}

void sorted::insert(List<int> &list, int x) {
	auto nearest = list.head;
	if (!nearest || nearest->data > x) {
		list.insertHead(x);
		return;
	}
	for (auto prev = nearest; ; ) {
		auto node = prev->next;
		if (node) {
			if (node->data > x) {
				list.insertAfter(prev, x);
				return;
			}
			prev = node;
		} else {
			list.insertAfter(prev, x);
			return;
		}
	}
}
