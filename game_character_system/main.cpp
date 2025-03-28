#include <iostream>
#include <string>
using namespace std;

// Interface for abilities
class IAttack {
public:
    virtual void attack() = 0;
    virtual ~IAttack() = default;
};

class IDefend {
public:
    virtual void defend() = 0;
    virtual ~IDefend() = default;
};

class IHealing {
public:
    virtual void heal() = 0;
    virtual ~IHealing() = default;
};

// Base class for all characters or Abstract class for GameCharacter
class GameCharacter {
protected:
    string name;
    int health;

public:
    GameCharacter(const string& name, int health) : name(name), health(health) {}
    virtual void displayInfo() const {
        cout << "Name: " << name << ", Health: " << health << endl;
    }
    virtual ~GameCharacter() = default;
};

// Player class
class Player : public GameCharacter, public IAttack, public IHealing {
public:
    Player(const string& name, int health) : GameCharacter(name, health) {}

    void attack() override {
        cout << name << " attacks the enemy!" << endl;
    }

    void heal() override {
        cout << name << " heals themselves!" << endl;
        health += 10; // Example healing logic
    }
};

// Enemy class
class Enemy : public GameCharacter, public IAttack, public IDefend {
public:
    Enemy(const string& name, int health) : GameCharacter(name, health) {}

    void attack() override {
        cout << name << " attacks the player!" << endl;
    }

    void defend() override {
        cout << name << " defends against the attack!" << endl;
    }
};

// NPC class
class NPC : public GameCharacter {
public:
    NPC(const string& name, int health) : GameCharacter(name, health) {}

    void displayInfo() const override {
        cout << "NPC ";
        GameCharacter::displayInfo();
    }
};

int main() {
    // Create characters
    Player player("Hero", 100);
    Enemy enemy("Goblin", 50);
    NPC npc("Villager", 30);

    // Display character info
    player.displayInfo();
    enemy.displayInfo();
    npc.displayInfo();

    // Perform actions
    player.attack();
    player.heal();
    enemy.attack();
    enemy.defend();

    return 0;
}