#include <iostream>
#include <string>
#include"12540.h"
using namespace std;

Dish::~Dish(){
    delete food;
}

istream & operator >> (std::istream &in, Dish &d){
	string str;
	int level;
	cin>>str;
	if(d.food!=nullptr){
		delete d.food;
		d.food = nullptr;
	}
	if(str == "Ramsay"){
		cin>>level;
		d.food = new IdiotSandwich(level);
	}
	else{
		d.food = new NormalSandwich(str);
	}
	return in;

}

void NormalSandwich::print(std::ostream &out){
    out<<this->getName()<<". Masterpiece of sandwiches.";
}

void IdiotSandwich::print(std::ostream &out){
    out<<"An idiot sandwich with intelligence level "<<this->getINT()<<" only.";
}