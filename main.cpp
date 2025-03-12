#include "classes.h"
using namespace  std;

int main(int argc, char* argv[])
{
    Human* Lena = new Human("Lena"); // Создание людей
    Human* Vitaliy = new Human("Vitaliy");
    Human* Vasya = new Human("Vasya");
    Human* Nastya = new Human("Nastya");
    Human* Kolya = new Human("Kolya");
    Human* Olya = new Human("Olya");
    Human* Vanya = new Human("Vanya");
    Human* Katya = new Human("Katya");

    SocialNet* sn = new SocialNet(); // Создание сети социальных связей и добавление туда людей

    sn->addHuman(Lena);
    sn->addHuman(Vitaliy);
    sn->addHuman(Vasya);
    sn->addHuman(Nastya);
    sn->addHuman(Kolya);
    sn->addHuman(Olya);
    sn->addHuman(Vanya);

    sn->delHuman(Nastya); // Пример удаления человека из соцсети
    sn->addHuman(Katya);

    sn->addConnection(Lena, Vitaliy); // Добавление связей между людьми
    sn->addConnection(Vitaliy,Vasya);
    sn->addConnection(Vasya, Katya);
    sn->addConnection(Katya, Kolya);
    sn->addConnection(Kolya, Olya);
    sn->addConnection(Olya, Vanya);

    sn->showThreeHandshakes(); // Отображение пар знакомств через три рукопожатия

    delete sn;
    
    delete Lena;
    delete Vitaliy;
    delete Vasya;
    delete Nastya;
    delete Kolya;
    delete Olya;
    delete Vanya;
    delete Katya;

    return 0;
}
