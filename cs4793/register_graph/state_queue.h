#if !defined(__JEL_STATE_QUEUE_HEADER__)
#define __JEL_STATE_QUEUE_HEADER__

#include"..\..\tools\queue.h"
#include "state.h"
namespace jel {
	class state_queue : public jel::queue<jel::state> {
	public:
		jel::queue<jel::state> _garbage;
		void insert(long regval, long cost, jel::op oper, jel::state* parent) {
			jel::node<jel::state>* temp = new jel::node<jel::state>(jel::state(regval, cost, oper, parent));
			if (_head == nullptr) {
				_head = temp;
				//_tail = temp;
				//_head->next = _tail;
				_tail = temp;
				delete temp;	
			} else {
				_tail->next = temp;
				_tail = temp;
			}
		}
		jel::state& pop_ref() {
			if (_head != nullptr) {
				jel::state* ret = &_head->info;
				_garbage.insert(_head->info);
				_head = _head->next;
				return *ret;
			}
		}
	};
}

#endif
