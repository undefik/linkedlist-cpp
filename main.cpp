#include <cstdio>
#include <cstdlib>

using namespace std;

class ListItem {
public:
	int value;
	ListItem* next;
	ListItem(int value) {
		this->value = value;
		this->next = NULL;
	}
};

class List {
private:
	int count;
	ListItem *first;

public:
	List() {
		this->first = NULL;
		this->count = 0;
	}
	ListItem* getptr(int pos){
		if(pos >= this->count || pos < 0){return NULL;}
		ListItem* auxitem = this->first;
		int aux = 0;
		while(aux < pos){
			auxitem = *(&auxitem->next);
			aux++;
		}
		return auxitem;
	}
	int get(int pos){
		return getptr(pos)->value;
	}
	int length(){
		return this->count;
	}
	void push(int val){
		if(count == 0){
			this->first = new ListItem(val);
		}else{
			ListItem* last = this->getptr(this->count-1);
			last->next = new ListItem(val);
		}
		count++;
	}

	void insert(int pos, int val){
		if(pos > this->count || pos < 0){return;}
		if(pos == this->count){this->push(val);return;}
		ListItem* auxitem = getptr(pos-1);
		ListItem* following = auxitem->next;
		ListItem* newitem = new ListItem(val);
		auxitem->next = newitem;
		newitem->next = following;
		this->count++;
	}
	void remove(int pos){
		if(pos > this->count || pos < 0){return;}
		ListItem* auxitem = getptr(pos-1);
		ListItem* delitem = auxitem->next;
		ListItem* following = delitem->next;
		delete delitem;
		auxitem->next = following;
		this->count--;
	}
};

int main() {
	List l = List();
	l.push(3);
	l.push(4);
	l.insert(1,5);
	l.remove(1);
	printf("Pole ma delku %d a obsahuje prvky: [ ", l.length());
	for(int i = 0; i < l.length(); i++){
		printf("%d ", l.get(i));
	}
	printf("]\n");
	return 0;
	
}
