#include <iostream>
#include <string>

class Model {
private:
    std::string data;

public:
    Model() : data("Hello, World!") {}

    void setData(const std::string& data) {
        std::cout << "Model: Set data : " << data << std::endl;
        this->data = data;
    }

    const std::string& getData() const {
        std::cout << "Model: Get data: " << data << std::endl;
        return data;
    }
};

class View {
public:
    void update(const std::string& data) const {
        std::cout << "View: Updating the view with data: " << data << std::endl;
    }
};

class Presenter {
private:
    Model model;
    View view;

public:
    Presenter() : model(), view() {}

    void setData(const std::string& data) {
        std::cout << "Presenter: Receive data from client." << std::endl;
        model.setData(data);
    }

    void updateView() {
        std::cout << "Presenter: Receive update view from client." << std::endl;
        const std::string& data = model.getData();
        view.update(data);
    }
};

int main() {
    std::cout << "Client: Pass trigger to Presenter." << std::endl;
    Presenter presenter;
    presenter.updateView();

    presenter.setData("Hello, Students!");
    presenter.updateView();

    return 0;
}

/*
Client: Pass trigger to Presenter.
Presenter: Receive update view from client.
Model: Get data: Hello, World!
View: Updating the view with data: Hello, World!
Presenter: Receive data from client.
Model: Set data : Hello, Students!
Presenter: Receive update view from client.
Model: Get data: Hello, Students!
View: Updating the view with data: Hello, Students!
*/