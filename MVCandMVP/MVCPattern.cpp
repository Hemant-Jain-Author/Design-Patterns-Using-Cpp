#include <iostream>
#include <string>

// Model class
class Model {
private:
    std::string data;

public:
    Model() : data("Hello, World!") {}

    void setData(const std::string& data) {
        std::cout << "Model: Set data: " << data << std::endl;
        this->data = data;
    }

    const std::string& getData() const {
        std::cout << "Model: Get data: " << data << std::endl;
        return data;
    }
};

// View class
class View {
private:
    const Model& model;

public:
    View(const Model& model) : model(model) {}

    // In classic MVC, the view interacts with the model to get data.
    void update() const {
        std::string data = model.getData();
        std::cout << "View: Updating the view with data: " << data << std::endl;
    }
};

// Controller class
class Controller {
private:
    Model model;
    View view;

public:
    Controller() : view(model) {}

    void setData(const std::string& data) {
        std::cout << "Controller: Receive data from client." << std::endl;
        model.setData(data);
    }

    void updateView() const {
        std::cout << "Controller: Receive update view from client." << std::endl;
        view.update();
    }
};

// Main function (Client code)
int main() {
    Controller controller;
    controller.updateView();

    controller.setData("Hello, Students!");
    controller.updateView();

    return 0;
}

/*
Controller: Receive update view from client.
Model: Get data: Hello, World!
View: Updating the view with data: Hello, World!
Controller: Receive data from client.
Model: Set data: Hello, Students!
Controller: Receive update view from client.
Model: Get data: Hello, Students!
View: Updating the view with data: Hello, Students!
*/