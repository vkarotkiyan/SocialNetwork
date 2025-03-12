#include <iostream>
#include <string>
#include "classes.h"
using namespace  std;

// Human //////////////////////////////////////////////////////////////////////
void Human::setId(int hid) {
	_hid = hid;
}

const int Human::getId() {
	return _hid;
}

const std::string Human::getName() {
	return _name;
}


// SocialNet //////////////////////////////////////////////////////////////////
SocialNet::SocialNet() {
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			_matrix[i][j] = 0;
	_hCount = 0;
}

void SocialNet::addHuman(Human* human) {
	human->setId(_hCount);
	_humans[_hCount++] = human;
}

void SocialNet::delHuman(Human* human) {
	for (int i = 0; i < SIZE; i++) {
		_matrix[human->getId()][i] = 0;
		_matrix[i][human->getId()] = 0;
	}
	int foundIndex = -1;
	for (int i = 0; i < _hCount; i++)
		if (_humans[i] == human) {
			foundIndex = i;
			break;
		}
	for (int i = foundIndex; i < _hCount; i++) {
		_humans[i]->setId(i - 1);
		_humans[i] = _humans[i + 1];
	}
	_hCount--;
	human->setId(-1);
}

void SocialNet::addConnection(Human* h1, Human* h2) {
	if (h1->getId() >= 0 && h2->getId() >= 0) {
		_matrix[h1->getId()][h2->getId()] = 1;
		_matrix[h2->getId()][h1->getId()] = 1;
	}
}

void SocialNet::delConnection(Human* h1, Human* h2) {
	_matrix[h1->getId()][h2->getId()] = 0;
	_matrix[h2->getId()][h1->getId()] = 0;
}

bool SocialNet::isHuman(Human* human) {
	for (int i = 0; i < _hCount; i++)
		if (_humans[i]->getId() == human->getId())
			return true;
	return false;
}

bool SocialNet::areFriends(Human* h1, Human* h2) {
		return _matrix[h1->getId()][h2->getId()] == 1;
}

void SocialNet::showThreeHandshakes() {
	int wavesLevels[SIZE]; // массив глубин относительно начального узла (человека)
	for (int i = 0; i < SIZE; i++)
		wavesLevels[i] = -1;
	wavesLevels[0] = 0; // глубина начального узла
	Human* queue[SIZE]; // очередь людей для обхода
	int queueCount = 0;
	queue[queueCount++] = _humans[queueCount]; // кладем в очередь начальный узел
	while (queueCount > 0) {
		Human* current = queue[0];
		queueCount--;
		for (int i = 0; i < queueCount; i++) {
			queue[i] = queue[i + 1];
		}
		for (int i = 0; i < _hCount; i++) {
			bool alreadyAdded = false;
			for (int j = 0; j < queueCount; j++)
				if (queue[j] == _humans[i]) {
					alreadyAdded = true;
					break;
				}
			if (areFriends(current, _humans[i]) && wavesLevels[_humans[i]->getId()] == -1 && !alreadyAdded) {
				wavesLevels[i] = wavesLevels[current->getId()] + 1;
				queue[queueCount++] = _humans[i];
			}
		}
	}
	for (int i = 0; i < _hCount; i++) { // Вывод пар, связанных рукопожатиями не меньше трех
		for (int j = i + 1; j < _hCount; j++) {
			if (abs(wavesLevels[i] - wavesLevels[j]) <= 3) {
				cout << _humans[i]->getName() << " - " << _humans[j]->getName() << endl;
			}
		}
	}
}
