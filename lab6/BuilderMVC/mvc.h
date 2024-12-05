#ifndef MVC_H
#define MVC_H

#include <vector>
#include "Builder.h"

class Observer {
public:
    virtual void update() = 0;
};

class Observable {
protected:
    int observersCount = 0;
    std::vector<Observer*> observers;

public:
    void signObserver(Observer* observer) {
        observers.push_back(observer);
        observersCount++;
    }

    void notifyUpdate() {
        for (int i = 0; i < observersCount; i++) {
            observers[i]->update();
        }
    }
};

class Model : public Observable {
    friend class Controller;
private:
    Product* product;
    void update(Product* product);

public:
    std::string getContent();
    bool chechHash();
    Model();
};

class Controller {
private:
    Product* product;
    Model* model;

public:
    Controller(Model* model);
    void CreateXML(std::string text);
    void CreateHTML(std::string text);
    void CreateJSON(std::string text);
};

#endif // MVC_H
