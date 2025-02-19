//20160922 - Justin Lye: created file
#if !defined(__JEL_QUEUE_HEADER__)
#define __JEL_QUEUE_HEADER__

#include<iostream>
#include"node.h"

/*

simple queue structure

*/

namespace jel {

	template<typename T>
	class queue {
	private:
		void _out(std::ostream& s) const {
			node<T>* temp = _head;
			while (temp != nullptr) {
				s << temp->info << '\n';
				temp = temp->next;
			}
		}
	public:
		node<T>* _head;
		node<T>* _tail;
		queue() : _head(nullptr), _tail(nullptr) {}
		~queue() {

			node<T>* temp = nullptr;
			while (_head != nullptr) {
				temp = _head;
				_head = _head->next;
				delete temp;
#ifdef JELDEBUG
				//std::cout << "Removing: " << temp->info << '\n';
#endif
			}
			if (_tail != nullptr) {
				_tail = nullptr;
				//delete _tail;
			}
		}
		virtual void insert(const T& n) {
			node<T>* new_node = new node<T>(n);
			if (_head == nullptr) {
				_head = new_node;
				//_tail = new_node;
				//_head->next = _tail;
			} else if (_tail == nullptr) {
				_tail = new_node;
				_head->next = _tail;
			} else {
				_tail->next = new_node;
				_tail = new_node;
			}
		}

		virtual T pop() {
			if (_head != nullptr) {
				T ret = _head->info;
				node<T>* temp = _head;
				_head = _head->next;
				delete temp;
				return ret;
			}
		}
		virtual T& peek() {
			if (_head != nullptr) {
				return _head->info;
			}
		}
		bool isempty() { return (_head == nullptr && _tail == nullptr); }
		friend std::ostream& operator<<(std::ostream& s, const queue& q) {
			q._out(s);
			return s;
		}
	};
}

#endif


