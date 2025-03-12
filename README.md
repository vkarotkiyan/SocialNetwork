## SocialNetwork

Реализация учебной задачи поиска в графе социальных связей определенного круга людей всех пар знакомств через три рукопожатия.

Реализованы: 
- класс Human, содержащий поля _hid (идентификатор) и _name (Имя) человека
- граф социальных связей (невзвешенный граф) - класс SocialNet, содержащий матрицу связей _matrix[SIZE][SIZE] и массив участников соцсети _humans[SIZE]
- один из методов класса SocialNet - showThreeHandshakes(), реализующий поиск всех пар знакомств до трех рукопожатий с помощью алгоритма обхода графа в ширину (BFS)

Обьявления классов:
```cpp
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
	bool isHuman(Human*); // Является участником соцсети
	bool areFriends(Human*, Human*); // Являются друзьями
	void showThreeHandshakes(); // Определение всех пар знакомств до трех рукопожатий
private:
	int _matrix[SIZE][SIZE]; // Матрица связей
	Human* _humans[SIZE]; // Массив участников соцсети
	int _hCount = 0; // Количество участников соцсети
};

```
