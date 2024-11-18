
template<class T> class LinkedListItem {
public:
	T value;
	LinkedListItem<T>* next;
	LinkedListItem(int value) {
		this->value = value;
		this->next = nullptr;
	}
};

template<class T> class LinkedList {
private:
	int count;
	LinkedListItem<T> *first;

public:
	LinkedList() {
		this->first = nullptr;
		this->count = 0;
	}
	LinkedListItem<T>* getptr(int pos){
		if(pos >= this->count || pos < 0){return nullptr;}
		LinkedListItem<T>* auxitem = this->first;
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
			this->first = new LinkedListItem<T>(val);
		}else{
			LinkedListItem<T>* last = this->getptr(this->count-1);
			last->next = new LinkedListItem<T>(val);
		}
		count++;
	}

	void insert(int pos, int val){
		if(pos > this->count || pos < 0){return;}
		if(pos == this->count){this->push(val);return;}
		LinkedListItem<T>* auxitem = getptr(pos-1);
		LinkedListItem<T>* following = auxitem->next;
		LinkedListItem<T>* newitem = new LinkedListItem<T>(val);
		auxitem->next = newitem;
		newitem->next = following;
		this->count++;
	}
	void remove(int pos){
		if(pos >= this->count || pos < 0){return;}
		if(pos == 0){
			LinkedListItem<T>* delitem = this->first;
			this->first = delitem->next;
			delete delitem;
		}else if(pos == this->count-1){
			LinkedListItem<T>* auxitem = getptr(pos-1);
			LinkedListItem<T>* delitem = auxitem->next;
			delete delitem;
			auxitem->next = nullptr;
		}else{
			LinkedListItem<T>* auxitem = getptr(pos-1);
			LinkedListItem<T>* delitem = auxitem->next;
			LinkedListItem<T>* following = delitem->next;
			delete delitem;
			auxitem->next = following;
		}
		this->count--;
	}
};
