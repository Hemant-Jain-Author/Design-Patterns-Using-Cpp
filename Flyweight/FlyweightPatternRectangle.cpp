#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdlib>

// Shape interface
class Shape {
public:
    virtual void draw(int x1, int y1, int x2, int y2) const = 0;
};

// Rectangle class implementing Shape
class Rectangle : public Shape {
private:
    std::string colour;

public:
    Rectangle(const std::string& colour) : colour(colour) {}

    void draw(int x1, int y1, int x2, int y2) const override {
        std::cout << "Draw rectangle colour: " << colour
                  << " topleft: (" << x1 << "," << y1 << ") rightBottom: (" << x2 << "," << y2 << ")\n";
    }
};

// RectangleFactory class
class RectangleFactory {
private:
    std::unordered_map<std::string, Shape*> shapes;

public:
    Shape* getRectangle(const std::string& colour) {
        if (shapes.find(colour) == shapes.end()) {
            shapes[colour] = new Rectangle(colour);
        }
        return shapes[colour];
    }

    int getCount() const {
        return shapes.size();
    }

    ~RectangleFactory() {
        for (const auto& entry : shapes) {
            delete entry.second;
        }
    }
};

// Client code
int main() {
    RectangleFactory factory;
    srand(time(nullptr));

    for (int i = 0; i < 100; i++) {
        Shape* rectangle = factory.getRectangle(std::to_string(rand() % 1000));
        rectangle->draw(rand() % 100, rand() % 100, rand() % 100, rand() % 100);
    }

    std::cout << factory.getCount() << std::endl;

    return 0;
}
