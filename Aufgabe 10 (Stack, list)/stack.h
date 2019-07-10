#ifndef STACK_H_
#define STACK_H_

#include<cstdlib>
#include<iostream>

using namespace std;

template<typename T>
class Stack {
private:
	struct StackElement {
		T datenfeld;
		StackElement *ne = nullptr;
	};
	StackElement *m_top;
public:
	Stack() {
		m_top = nullptr;
	};
	Stack(const Stack<T>& r){
		m_top = nullptr;
		StackElement *hilf = r.m_top -> ne;
		while(hilf -> ne != nullptr){
			hilf = hilf -> ne;
		}
		while(hilf != r.m_top){
		push(hilf -> datenfeld);
		hilf++;
		}
		push(r.m_top -> datenfeld);
		};
	Stack<T>& operator= (Stack<T>& r){
		if (this == &r)
			return *this;
		else{
			m_top = nullptr;
			StackElement *hilf = r.m_top -> ne;
			while(hilf -> ne != nullptr){
				hilf = hilf -> ne;
			}
			while(hilf != r.m_top){
			push(hilf->datenfeld);
			hilf++;
			}
			push(r.m_top -> datenfeld);
			}
		return *this;
	};
	bool empty() {
		if (m_top == nullptr)
			return true;
		else
			return false;
	};
	void push(T x) {
		StackElement *z;
		z = new StackElement;
		z->datenfeld = x;
		z->ne = m_top;
		m_top = z;
	};
	void pop() {
		if (empty()) {
			cerr << "Stapel ist leer.";
			exit(1);
		} else {
			StackElement *hilf = m_top->ne;
			delete m_top;
			m_top = hilf;
		}
	};
	StackElement* top() {
		if (empty()) {
			cerr << "Stapel ist leer.";
			exit(1);
		}
		return m_top;
	};
	void clear() {
		while (m_top != nullptr){
			pop();
		}
	};
	~Stack() {
		clear();
	};

};

#endif
