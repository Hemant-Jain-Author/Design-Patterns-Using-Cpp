#include <iostream>

class Animal {
    std::string name;
public:
    Animal(const std::string& name) : name(name) {}
};

class Bird : public Animal {
protected:
    int flightHeight;
public:
    Bird(const std::string& name) : Animal(name), flightHeight(0) {}
    int getHeight() { return flightHeight; }
    virtual void fly() = 0;
};

class Sparrow : public Bird {
public:
    Sparrow(const std::string& name) : Bird(name) {}
    void fly() override {
        std::cout << "The sparrow is fluttering its wings." << std::endl;
        flightHeight = 100;
    }
};

class Penguin : public Bird {
public:
    Penguin(const std::string& name) : Bird(name) {}

    void fly() override {
        std::cout << "The penguin cannot fly." << std::endl;
    }

    void slide() {
        std::cout << "The penguin is sliding on its belly!" << std::endl;
    }

    void swim() {
        std::cout << "The penguin is swimming in the water!" << std::endl;
    }
};

class Dodo : public Bird {
public:
    Dodo(const std::string& name) : Bird(name) {}

    void fly() override {
        std::cout << "The dodo is extinct and cannot fly." << std::endl;
    }
};

void test(Bird* bird) {
    bird->fly();
    if (bird->getHeight() > 0) {
        std::cout << "Bird is flying at a positive height." << std::endl;
    } else {
        std::cout << "Error: fly() method called; flight height is still zero." << std::endl;
    }
}

int main() {
    Sparrow sparrow("Sparrow");
    test(&sparrow);

    Penguin penguin("Penguin");
    test(&penguin);
    penguin.slide();
    penguin.swim();

    Dodo dodo("Dodo");
    test(&dodo);

    return 0;
}

/*
The sparrow is fluttering its wings.
Bird is flying at a positive height.
The penguin cannot fly.
Error: fly() method called; flight height is still zero.
The penguin is sliding on its belly!
The penguin is swimming in the water!
The dodo is extinct and cannot fly.
Error: fly() method called; flight height is still zero.
*/