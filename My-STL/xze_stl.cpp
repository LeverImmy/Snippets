#include <bits/stdc++.h>
#define LL long long

template <typename T, int _size_> class deque {
	private:
		static const int MAXSIZE = _size_;
		int _head_, _tail_; T _q[MAXSIZE + 5];
	public:
		inline void push_front(T _val_) { (--_head_ < 1) ? (_q[_head_ = MAXSIZE] = _val_) : (_q[_head_] = _val_); }
		inline void pop_front() { (++_head_ > MAXSIZE) ? (_head_ = 1) : (1); }
		inline void push_back(T _val_) { (++_tail_ > MAXSIZE) ? (_q[_tail_ = 1] = _val_) : (_q[_tail_] = _val_); }
		inline void pop_back() { _tail_ ? (--_tail_) : (_tail_ = MAXSIZE); }
		inline T front() { return _q[(_head_ + 1 > MAXSIZE) ? 1 : (_head_ + 1)]; }
		inline T back() { return _q[_tail_]; }
		inline int size() { return (_tail_ - _head_ <= 0) ? (_tail_ - _head_ + MAXSIZE) : (_tail_ - _head_); }
		inline void empty() { return !(_tail_ - _head_); }
		inline void clear() { _head_ = _tail_ = 0; }
};

int main() {

	return 0;
}

