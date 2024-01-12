#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <sstream>
#include <algorithm>

// Observer interface
class Observer {
public:
    virtual void update() = 0;
};

// Model class
class Model {
private:
    std::string data;
    std::vector<Observer*> observers;

public:
    void setData(const std::string& newData) {
        std::cout << "Model : Set data." << std::endl;
        data = newData;
        notifyObservers();
    }

    const std::string& getData() const {
        std::cout << "Model : Get data." << std::endl;
        return data;
    }

    void addObserver(Observer* observer) {
        observers.push_back(observer);
    }

    void removeObserver(Observer* observer) {
        observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
    }

    void notifyObservers() {
        std::cout << "Model : Notify observers." << std::endl;
        for (Observer* observer : observers) {
            observer->update();
        }
    }
};

// View class
class View : public Observer {
private:
    class Controller* controller;
    Model* model;

public:
    View(Model* model, class Controller* controller) : model(model), controller(controller) {
        model->addObserver(this);
    }

    void update() override {
        std::cout << "View : Update." << std::endl;
        const std::string& data = model->getData();
        std::cout << "Data: " << data << std::endl;
    }

    void getUserInput() ;
};

// Controller class
class Controller {
private:
    Model* model;
    View* view;

public:
    Controller(Model* model) : model(model) {}

    void handleUserInput(const std::string& userInput) {
        std::cout << "Controller : Handle user input." << std::endl;
        model->setData(userInput);
    }

    void setView(View* v) {
        view = v;
    }
};


    void View::getUserInput() {
        std::string userInput;
        std::cout << "View : Enter user input: ";
        std::getline(std::cin, userInput);
        controller->handleUserInput(userInput);
    }

int main() {
    Model model;
    Controller controller(&model);
    View view(&model, &controller);
    controller.setView(&view);
    view.getUserInput();

    return 0;
}

/*
View : Enter user input: hello, world!
Controller : Handle user input.
Model : Set data.
Model : Notify observers.
View : Update.
Model : Get data.
Data: hello, world!
*/
