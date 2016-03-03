
#include <iostream>
#include <climits>

using namespace std;

template <class Data>
struct Node {
	Data data;
	Node *node;
	Node (Data data) {
		Node::data = data;
	}
	Node (Data data, Node *next) {
		Node::data = data;
		Node::next = next;
	}
};

template <class Data>
struct List {
	Node *head;
	List () {
		head = NULL;
	}
	void insertHead(Node *newhead) {}
	Node *insertHead(Data data) {}
	bool disposeHead() {}
	bool findAndDispose(Data) {}
	void sort(bool (*compare)(Data, Data)) {}
	void insertAfter(Node *position, Node *newnode) {}
	Node *insertAfter(Node *position, Data data) {}
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

constexpr Action ACTIONS = {
	NULL, &inputList, &printList, &findInList, &disposeHead, &findAndDispose, &sortAndInsert
};

constexpr auto LENGTH_OF_ACTIONS = sizeof(ACTIONS) / sizeof(Action);
constexpr char SELECTION_BEGIN = '0';
constexpr char SELECTION_END = SELECTION_BEGIN + LENGTH_OF_ACTIONS - 1;

int findInList(List<int>, int);

namespace sorted {
	void askForInsertion(List<int> &);
	void insert(List<int> &, int);
}

constexpr char ASK_FOR_ACTION[] = "\
Chon hanh dong:\n\
 [0] -> Thoat\n\
 [1] -> Nhap danh sach\n\
 [2] -> Xem danh sach\n\
 [3] -> Tim x trong danh sach\n\
 [4] -> Xoa phan tu dau danh sach
 [5] -> Tim va xoa 1 phan tu x khoi danh sach\n\
 [6] -> Sap xep theo thu tu tang dan, chen x vao mang da sap xep\n\
 Nhap mot ki tu: \
";

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
	char selection;
	cout << ASK_FOR_ACTION;
	cin >> selection;
	return selection < SELECTION_BEGIN || selection > SELECTION_END ? &printInvalidSelectionError : ACTIONS[selection - '0'];
}

void inputList(List<int> &list) {
	unsigned count;
	Node *node, *prev;
	cout << "So luong: ";
	for (cin >> count; count; --count) {
		int data;
		cin >> data;
		Node *node = new Node(data);
		if (list.head) {
			prev->next = node;
			prev = node;
		} else {
			list.head = prev = node;
		}
	}
}

void printList(List<int> &list) {
	cout << "List: ";
	for (auto node = list.head; node; node = node->next) {
		cout << '\x20' << node->data;
	}
	cout << endl;
}

void findInList(List<int> &list) {
	int x;
	cout << "Nhap mot so nguyen: ";
	cin >> x;
	auto index = findInList(list, x);
	if (index == -1) {
		cout << "Khong tim thay " << x << endl;
	} else {
		cout << "Tim thay " << x << " tai vi tri " << index << endl;
	}
}

void disposeHead(List<int> &list) {
	if (list.disposeHead()) {
		cout << "Da xoa mot head\n";
		printList(list);
	} else {
		cerr << "Danh sach trong\n";
	}
}

void findAndDispose(List<int> &list) {
	int x;
	cout << "Nhap mot so nguyen: ";
	cin >> x;
	if (list.findAndDispose(x)) {
		cout << "Da xoa mot phan tu co khoa " << x << " khoi danh sach\n";
	} else {
		cerr << "Khong co phan tu nao co khoa " << x << endl;
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
	if (!nearest) {
		list.insertHead(x);
		return;
	}
	auto min_distance = nearest->data < x ? (x - nearest->data) : INT_MAX;
	for (auto node = nearest->next; node; node = node->next) {
		if (node->data < x) {
			auto from_node = node->data - x;
			if (from_node < min_distance) {
				nearest = node;
				min_distance = from_node;
			}
		}
	}
	list.insertAfter(nearest, x);
}
