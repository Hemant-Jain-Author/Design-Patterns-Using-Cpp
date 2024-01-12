#include <iostream>
#include <unordered_map>

// Flyweight interface
class Flyweight {
public:
    virtual void operation(const void* extrinsicState) = 0;
};

// Concrete Flyweight class
class ConcreteFlyweight : public Flyweight {
private:
    std::string intrinsicState;

public:
    ConcreteFlyweight(const std::string& intrinsicState) : intrinsicState(intrinsicState) {}

    void operation(const void* extrinsicState) override {
        std::cout << "Operation inside concrete flyweight" << std::endl;
    }
};

// FlyweightFactory class
class FlyweightFactory {
private:
    std::unordered_map<std::string, Flyweight*> flyweights;

public:
    Flyweight* getFlyweight(const std::string& key) {
        if (flyweights.find(key) == flyweights.end()) {
            flyweights[key] = new ConcreteFlyweight(key);
        }
        return flyweights[key];
    }

    int getCount() const {
        return flyweights.size();
    }

    ~FlyweightFactory() {
        for (const auto& entry : flyweights) {
            delete entry.second;
        }
    }
};

// Client code
int main() {
    FlyweightFactory factory;
    Flyweight* flyweight1 = factory.getFlyweight("key");
    Flyweight* flyweight2 = factory.getFlyweight("key");

    flyweight1->operation(nullptr);

    std::cout << flyweight1 << " " << flyweight2 << std::endl;
    std::cout << "Object count: " << factory.getCount() << std::endl;

    return 0;
}

/*
Operation inside concrete flyweight
0x55990ff3beb0 0x55990ff3beb0
Object count: 1
*/