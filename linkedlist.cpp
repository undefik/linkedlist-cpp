
class LinkedListItem {
public:
	int value;
	LinkedListItem* next;
	LinkedListItem(int value) {
		this->value = value;
		this->next = nullptr;
	}
};

class LinkedList {
private:
	int count;
	LinkedListItem *first;

public:
	LinkedList() {
		this->first = nullptr;
		this->count = 0;
	}
	LinkedListItem* getptr(int pos){
		if(pos >= this->count || pos < 0){return nullptr;}
		LinkedListItem* auxitem = this->first;
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
			this->first = new LinkedListItem(val);
		}else{
			LinkedListItem* last = this->getptr(this->count-1);
			last->next = new LinkedListItem(val);
		}
		count++;
	}

	void insert(int pos, int val){
		if(pos > this->count || pos < 0){return;}
		if(pos == this->count){this->push(val);return;}
		LinkedListItem* auxitem = getptr(pos-1);
		LinkedListItem* following = auxitem->next;
		LinkedListItem* newitem = new LinkedListItem(val);
		auxitem->next = newitem;
		newitem->next = following;
		this->count++;
	}
	void remove(int pos){
		if(pos >= this->count || pos < 0){return;}
		if(pos == 0){
			LinkedListItem* delitem = this->first;
			this->first = delitem->next;
			delete delitem;
		}else if(pos == this->count-1){
			LinkedListItem* auxitem = getptr(pos-1);
			LinkedListItem* delitem = auxitem->next;
			delete delitem;
			auxitem->next = nullptr;
		}else{
			LinkedListItem* auxitem = getptr(pos-1);
			LinkedListItem* delitem = auxitem->next;
			LinkedListItem* following = delitem->next;
			delete delitem;
			auxitem->next = following;
		}
		this->count--;
	}
};
