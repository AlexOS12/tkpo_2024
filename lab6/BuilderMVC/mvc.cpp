#include "mvc.h"

Controller::Controller(Model *model)
{
    this->model = model;
}

void Controller::CreateXML(std::string text)
{
    XMLBuilder* builder = new XMLBuilder(text);
    Director* director = new Director(builder);

    director->construct();

    Product* xml = builder->getResult();
    model->update(xml);
}

void Controller::CreateHTML(std::string text)
{
    HTMLBuilder* builder = new HTMLBuilder(text);
    Director* director = new Director(builder);

    director->construct();

    model->update(builder->getResult());
}

void Controller::CreateJSON(std::string text)
{
    JSONBuilder* builder = new JSONBuilder(text);
    Director* director = new Director(builder);

    director->construct();

    model->update(builder->getResult());
}

Model::Model() {}

void Model::update(Product *product)
{
    this->product = product;
    notifyUpdate();
}

std::string Model::getContent()
{
    return product->toString();
}

bool Model::chechHash()
{
    return product->checkHash();
}
