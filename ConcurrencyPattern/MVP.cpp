#include <iostream>
#include <string>

// Forward declarations
class Presenter;
class Model;

class View {
private:
    Presenter* presenter;

public:
    void update(const std::string& data);

    void setPresenter(Presenter* newPresenter);

    void getUserInput();
};

class Model {
private:
    std::string data;
    Presenter* presenter;

public:
    void setData(const std::string& newData);

    const std::string& getData() const;

    void setPresenter(Presenter* newPresenter);
};

class Presenter {
private:
    Model* model;
    View* view;

public:
    Presenter(Model* newModel, View* newView);

    void handleUserInput(const std::string& userInput);

    void modelUpdateEvent();
};

// View member function definitions
void View::update(const std::string& data) {
    std::cout << "View: Update UI." << std::endl;
    std::cout << "Data: " << data << std::endl;
}

void View::setPresenter(Presenter* newPresenter) {
    presenter = newPresenter;
}

void View::getUserInput() {
    std::cout << "View: Enter user input: ";
    std::string userInput = "hello, world!"; // Simulating user input
    std::cout << userInput << std::endl;
    presenter->handleUserInput(userInput);
}

// Model member function definitions
void Model::setData(const std::string& newData) {
    std::cout << "Model: Set data." << std::endl;
    data = newData;
    presenter->modelUpdateEvent();
}

const std::string& Model::getData() const {
    std::cout << "Model: Get data." << std::endl;
    return data;
}

void Model::setPresenter(Presenter* newPresenter) {
    presenter = newPresenter;
}

// Presenter member function definitions
Presenter::Presenter(Model* newModel, View* newView) : model(newModel), view(newView) {}

void Presenter::handleUserInput(const std::string& userInput) {
    std::cout << "Presenter: Handle user input." << std::endl;
    model->setData(userInput);
}

void Presenter::modelUpdateEvent() {
    std::cout << "Presenter: Model update event." << std::endl;
    view->update(model->getData());
}

int main() {
    Model model;
    View view;
    Presenter presenter(&model, &view);

    model.setPresenter(&presenter);
    view.setPresenter(&presenter);

    view.getUserInput();

    return 0;
}

/*
View: Enter user input: hello, world!
Presenter: Handle user input.
Model: Set data.
Presenter: Model update event.
Model: Get data.
View: Update UI.
Data: hello, world!
*/