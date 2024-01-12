#include <iostream>
#include <string>

class Student {
private:
    std::string name;
    int id;

public:
    Student(const std::string& name, int id) : name(name), id(id) {}

    const std::string& getName() const {
        return name;
    }

    int getId() const {
        return id;
    }
};

class Model {
private:
    Student student;

public:
    Model() : student("Harry", 1) {}

    void setData(const std::string& name, int id) {
        std::cout << "Model: Set data : " << name << " " << id << std::endl;
        this->student = Student(name, id);
    }

    const Student& getData() const {
        std::cout << "Model: Get data." << std::endl;
        return student;
    }
};

class View {
public:
    void update(const std::string& name, int id) const {
        std::cout << "View: Student Info : " << name << " " << id << std::endl;
    }
};

class Presenter {
private:
    Model model;
    View view;

public:
    Presenter() : model(), view() {}

    void setData(const std::string& name, int id) {
        std::cout << "Presenter: Receive data from client." << std::endl;
        model.setData(name, id);
    }

    void updateView() {
        std::cout << "Presenter: Receive update from client." << std::endl;
        const Student& data = model.getData();
        view.update(data.getName(), data.getId());
    }
};

int main() {
    Presenter presenter;
    presenter.updateView();

    presenter.setData("jack", 2);
    presenter.updateView();

    return 0;
}

/*
Presenter: Receive update from client.
Model: Get data.
View: Student Info : Harry 1
Presenter: Receive data from client.
Model: Set data : jack 2
Presenter: Receive update from client.
Model: Get data.
View: Student Info : jack 2
*/