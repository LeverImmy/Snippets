#include <bits/stdc++.h>

namespace PAIR {
	template <typename _tp1, typename _tp2> class pair {
		public:
			_tp1 key;
			_tp2 val;
			bool operator<(const pair &rhs) const {
				if(val == rhs.val)
					return key < rhs.key;
				return val < rhs.val;
			}
			pair(_tp1 aa, _tp1 bb) {
				key = aa, val = bb;
			}
	};
}
/*
* usage: pair <int, int> p;
* 
*/
