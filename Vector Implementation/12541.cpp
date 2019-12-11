#include "12541.h"
#include <iostream>
#include <string>
using namespace std;

int n;
string op;
vector<int> v;

int main()
{
	cin >> n;
	int t1;
	while(n--) {
		cin >> op;
		if(op == "push_back") {
			cin >> t1;
			v.push_back(t1);
		}
		else if(op == "pop_back") {
			v.pop_back();
		}
		else if(op == "access") {
			cin >> t1;
			cout << v[t1] << endl;
		}
		else if(op == "size") {
			cout << v.size() << endl;
		}
		else if(op == "capacity") {
			cout << v.capacity() << endl;
		}
		else if(op == "reserve") {
			cin >> t1;
			v.reserve(t1);
		}
		else if(op == "clear") {
			v.clear();
		}
	}
	return 0;
}
