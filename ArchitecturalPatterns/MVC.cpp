#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <sstream>

// Forward declarations
class Controller;

// Model
class Model {
private:
    std::string data;
    std::vector<Controller*> observers;

public:
    void setData(std::string data) {
        std::cout << "Model : Set data." << std::endl;
        this->data = data;
        notifyObservers();
    }

    std::string getData() {
        std::cout << "Model : Get data." << std::endl;
        return this->data;
    }

    void addObserver(Controller* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Controller* observer) {
        // Not implemented
    }

    void notifyObservers() {
        std::cout << "Model : Notify observers." << std::endl;
        for (auto observer : observers) {
            observer->update();
        }
    }
};

// View
class View {
private:
    Controller* controller;
    Model* model;

public:
    View(Model* model, Controller* controller) : model(model), controller(controller) {
        model->addObserver(controller);
    }

    void update() {
        std::cout << "View : Update." << std::endl;
        std::string data = model->getData();
        std::cout << "Data: " << data << std::endl;
    }

    void getUserInput() {
        std::cout << "View : Enter user input: ";
        std::string userInput;
        std::getline(std::cin, userInput);
        controller->handleUserInput(userInput);
    }
};

// Controller
class Controller {
private:
    Model* model;
    View* view;

public:
    Controller(Model* model) : model(model) {}

    void handleUserInput(std::string userInput) {
        std::cout << "Controller : Handle user input." << std::endl;
        model->setData(userInput);
    }

    void setView(View* v) {
        this->view = v;
    }

    void update() {
        view->update();
    }
};

// Main function
int main() {
    Model model;
    Controller controller(&model);
    View view(&model, &controller);
    controller.setView(&view);
    view.getUserInput();
    return 0;
}
