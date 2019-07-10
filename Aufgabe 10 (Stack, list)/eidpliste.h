
#ifndef EIDPLISTE_H_
#define EIDPLISTE_H_

#include<iostream>

using namespace std;

template<typename T>
class Liste {
public:
	Liste(){
		ez = sz = nullptr;
	};
	Liste(const Liste<T>& liste){
		ez = nullptr;
		for(Objekt *ptr = liste.sz; ptr != nullptr; ptr = ptr->next){
			append(ptr->data);
		}
	};
	void append(const T& x){
		Objekt *obj = new Objekt;
		obj->data = x;
		obj->next = nullptr;
		if(empty()) {
			sz = obj;
			obj -> pre = nullptr; // nullptr aufstellen
		}
		else {
			ez-> next = obj;
			obj -> pre = ez; // pre = ez, Zeiger auf das vorheriges Element aufstellen.
		}
		ez = obj;
	};
	void prepend(const T& x){
		Objekt *obj = new Objekt;
		obj->data =x;
		obj->next = sz;
		obj->pre = nullptr;  // nullptr aufstellen
		sz->pre = obj; //obj wird zu den vorherigen Element.
		sz = obj;
		if(empty()) ez = obj;
	};
	bool empty(){
		return(ez == nullptr);
	};
	bool is_elem(const T& x){
		Objekt *ptr = sz;
		while (ptr != nullptr){
			if (ptr->data == x) return true;
			ptr = ptr->next;
		}
		return false;
	};
	void clear(){
		clear(sz);
		ez = sz = nullptr;
	};
	void print(bool directionForward){
		if(sz == nullptr)
			cout << ' ';
		else{
		if(directionForward){
				for(Objekt *ptr = sz; ptr != ez; ptr = ptr->next){
				cout << ptr->data << ' ';
			}
			cout << ez -> data << ' ';
			}

		else{
			for(Objekt *ptr = ez; ptr != sz; ptr = ptr->pre){
				cout << ptr->data << ' ';
			}
			cout << sz->data<< ' ';
		}
		}
	};
	void reverse(){
		Objekt *anfang = sz;
		Objekt *ende = ez;
		T hilf;
		while(ende != anfang){
			hilf = anfang->data;
			anfang->data = ende->data;
			anfang = anfang->next;
			ende->data = hilf;
			ende = ende->pre;
		}
	};
	void deleteAt(unsigned int position){
		if(!empty()){
		Objekt *hilf = sz;
		for(unsigned int i = 0; i < position; i++){
		if(hilf->next != nullptr)
			hilf = hilf->next;

		}
		if(hilf == sz && hilf == ez){
			 clear();
		}
		else if(hilf == ez){
			hilf->pre->next = nullptr;
			ez = hilf->pre;
			delete hilf;
		}
		else if (hilf == sz){
			sz = hilf->next;
			hilf->next->pre = nullptr;
			delete hilf;
		}
		else {
			hilf->next->pre = hilf->pre;
			hilf->pre->next = hilf->next;
			delete hilf;
		}
		}
	}
	~Liste(){clear();};
private:
	struct Objekt{
		T data;
		Objekt *next, *pre; // pre: Zeiger auf das vorheriges Element.
	} *sz, *ez;
	void clear(Objekt* obj){
		if (obj == nullptr) return;
		clear(obj->next);
		delete obj;
	};
};



#endif
