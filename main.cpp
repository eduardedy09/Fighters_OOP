#include <iostream>
#include <cstring>
#include <ctime>
#include <cmath>

using namespace std;

class Warrior {
private:
    int AtkMax;
    int BlkMax;
public:
    string name;
    int health;

    Warrior(string name, int health, int AtkMax, int BlkMax) {
        this->name = name;
        this->health = health;
        this->AtkMax = AtkMax;
        this->BlkMax = BlkMax;
    }

    int Attack() {
        return rand() % this->AtkMax;
    }

    int Block() {
        return rand() % this->BlkMax;
    }
};

class Battle {
public:
    static void Start(Warrior &warr1, Warrior &warr2) {
        while (true) {
            if (Battle::GettAttackResult(warr1, warr2).compare("Game OVER") == 0) {
                cout << "Game OVER!\n";
                break;
            }
            if (Battle::GettAttackResult(warr2, warr1).compare("Game OVER") == 0) {
                cout << "Game OVER!\n";
                break;
            }
        }
    }

    static string GettAttackResult(Warrior &warrA, Warrior &warrB) {
        int warrAAtk = warrA.Attack();
        int warrBBlk = warrB.Block();
        int damage2WarrB = ceil(warrAAtk - warrBBlk);
        damage2WarrB = (damage2WarrB <= 0) ? 0 :
                       damage2WarrB;
        warrB.health = warrB.health - damage2WarrB;
        printf("%s attacks %s and deals %d damage.\n",
                warrA.name.c_str(), warrB.name.c_str(), damage2WarrB);
        printf("%s is down to %d health.\n",
                warrB.name.c_str(), warrB.health);
        if (warrB.health <= 0) {
            printf("%s a murit si %s a castigat.\n",
                    warrB.name.c_str(), warrA.name.c_str());
            return "Game OVER";

        } else {
            return "Fight Again!";
        }
    }
};

int main() {
    srand(time(NULL));
    Warrior w1("Adi", 100, 35, 15);
    Warrior w2("Aki", 150, 30, 25);

    Battle::Start(w1, w2);

}
