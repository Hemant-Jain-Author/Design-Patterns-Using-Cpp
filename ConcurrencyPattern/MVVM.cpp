#include <iostream>
#include <string>
#include <sstream>

// Forward declarations
class Model;
class ViewModel;
class View;

// Model
class Model {
private:
    std::string data;

public:
    void setData(const std::string& newData);

    const std::string& getData() const;
};

// ViewModel
class ViewModel {
private:
    Model* model;
    std::string data;

public:
    ViewModel(Model* model);

    void updateModel(const std::string& newData);

    void updateData();

    const std::string& getData() const;
};

// View
class View {
private:
    ViewModel* viewModel;

public:
    View(ViewModel* viewModel);

    void displayData() const;

    void getUserInput();
};

// Model member function definitions
void Model::setData(const std::string& newData) {
    std::cout << "Model: Set data." << std::endl;
    data = newData;
}

const std::string& Model::getData() const {
    std::cout << "Model: Get data." << std::endl;
    return data;
}

// ViewModel member function definitions
ViewModel::ViewModel(Model* model) : model(model) {
    updateData();
}

void ViewModel::updateModel(const std::string& newData) {
    std::cout << "ViewModel: Update data." << std::endl;
    model->setData(newData);
    updateData();
}

void ViewModel::updateData() {
    std::cout << "ViewModel: Fetch data." << std::endl;
    data = model->getData();
}

const std::string& ViewModel::getData() const {
    return data;
}

// View member function definitions
View::View(ViewModel* viewModel) : viewModel(viewModel) {}

void View::displayData() const {
    std::cout << "Display Data: " << viewModel->getData() << std::endl;
}

void View::getUserInput() {
    std::string userInput;
    std::cout << "View: Enter user input: ";
    // std::getline(std::cin, userInput); // Uncomment for user input

    // Simulating user input
    userInput = "hello, world!";
    std::cout << userInput << std::endl;

    viewModel->updateModel(userInput);
}

// Client code
int main() {
    Model model;
    ViewModel viewModel(&model);
    View view(&viewModel);

    // Display initial data
    view.displayData();

    // Get user input and update data
    view.getUserInput();

    // Display updated data
    view.displayData();

    return 0;
}

/*
ViewModel: Fetch data.
Model: Get data.
Display Data: 
View: Enter user input: hello, world!
ViewModel: Update data.
Model: Set data.
ViewModel: Fetch data.
Model: Get data.
Display Data: hello, world!
*/