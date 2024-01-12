#include <iostream>
#include <unordered_map>

// Flyweight interface
class Flyweight {
public:
    virtual void operation(const std::string& extrinsicState) = 0;
};

// Concrete Flyweight class
class ConcreteFlyweight : public Flyweight {
private:
    std::string intrinsicState;

public:
    ConcreteFlyweight(const std::string& intrinsicState) : intrinsicState(intrinsicState) {}

    void operation(const std::string& extrinsicState) override {
        std::cout << "Operation inside concrete flyweight: " << this << std::endl;
    }
};

// FlyweightFactory class
class FlyweightFactory {
private:
    std::unordered_map<std::string, Flyweight*> flyweights;

public:
    Flyweight* getFlyweight(const std::string& intrinsicState) {
        if (flyweights.find(intrinsicState) == flyweights.end()) {
            flyweights[intrinsicState] = new ConcreteFlyweight(intrinsicState);
        }
        return flyweights[intrinsicState];
    }
};

// ClientClass
class ClientClass {
public:
    Flyweight* flyweight;
    std::string extrinsicState;

    ClientClass(FlyweightFactory& factory, const std::string& intrinsicState, const std::string& extrinsicState)
        : flyweight(factory.getFlyweight(intrinsicState)), extrinsicState(extrinsicState) {}

    void operation() {
        std::cout << "Operation inside context: " << this << std::endl;
        flyweight->operation(extrinsicState);
    }
};

// Main function
int main() {
    FlyweightFactory factory;
    ClientClass c(factory, "common", "separate1");
    c.operation();

    ClientClass c2(factory, "common", "separate2");
    c2.operation();

    return 0;
}

/*
Operation inside context: 0x7ffe91e62070
Operation inside concrete flyweight: 0x559ff0559eb0
Operation inside context: 0x7ffe91e620a0
Operation inside concrete flyweight: 0x559ff0559eb0
*/