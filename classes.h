#pragma		once
#include <string>
#include <iostream>
using namespace  std;

#define SIZE 50

class Human {
public:
	Human(string name) : _name(name) { _hid = -1; }
	~Human() = default;
	void setId(int);
	const int getId();
	const string getName();
private:
	int _hid;
	string _name;
};

class SocialNet {
public:
	SocialNet();
	void addHuman(Human*); // Добавление человека в соцсеть
	void delHuman(Human*); // Удаление человека из соцсети
	void addConnection(Human*, Human*); // Добавление связи
	void delConnection(Human*, Human*); // Удаление связи
	bool isHuman(Human*); 
	bool areFriends(Human*, Human*); // Являются друьями
	void showThreeHandshakes(); // Определение всех пар знакомств до трех рукопожатий
private:
	int _matrix[SIZE][SIZE]; // Матрица связей
	Human* _humans[SIZE]; // Массив участников соцсети
	int _hCount = 0; // Количество участников соцсети
};
