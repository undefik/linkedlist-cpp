#include <cstdio>
#include "linkedlist.cpp"

using namespace std;


int main() {
	LinkedList l = LinkedList();
	l.push(3);
	l.push(4);
	l.insert(1,5);
	printf("Pole ma delku %d a obsahuje prvky: [ ", l.length());
	for(int i = 0; i < l.length(); i++){
		printf("%d ", l.get(i));
	}
	printf("]\n");
	return 0;
	
}
