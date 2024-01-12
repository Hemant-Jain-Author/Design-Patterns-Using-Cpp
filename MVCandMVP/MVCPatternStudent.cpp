#include <iostream>
#include <string>

class Student {
public:
    std::string name;
    int id;

    Student(const std::string& name, int id) : name(name), id(id) {}
};

class Model {
private:
    Student student;

public:
    Model() : student("Harry", 1) {}

    void setData(const std::string& name, int id) {
        std::cout << "Model: Set data : " << name << " " << id << std::endl;
        student.name = name;
        student.id = id;
    }

    const Student& getData() const {
        std::cout << "Model: Get data." << std::endl;
        return student;
    }
};

class View {
private:
    const Model& model;

public:
    View(const Model& model) : model(model) {}

    void update() const {
        const Student& student = model.getData();
        std::cout << "View: Student Info, Name: " << student.name << " Id: " << student.id << std::endl;
    }
};

class Controller {
private:
    Model model;
    View view;

public:
    Controller() : view(model) {}

    void setData(const std::string& name, int id) {
        std::cout << "Controller: Receive data from client." << std::endl;
        model.setData(name, id);
    }

    void updateView() const {
        std::cout << "Controller: Receive update view from client." << std::endl;
        view.update();
    }
};

int main() {
    Controller controller;
    controller.updateView();

    controller.setData("Jack", 2);
    controller.updateView();

    return 0;
}

/*
Controller: Receive update view from client.
Model: Get data.
View: Student Info, Name: Harry Id: 1
Controller: Receive data from client.
Model: Set data : Jack 2
Controller: Receive update view from client.
Model: Get data.
View: Student Info, Name: Jack Id: 2
*/