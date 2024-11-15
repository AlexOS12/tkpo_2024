#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>

// Базовый класс продукта
class Product {
public:
	Product() {};
	// Методы преобразования продукта в строку
	virtual std::string toString() = 0;
	virtual bool checkHash() = 0;
};

// Класс XML
class XML : public Product {
public:
	std::string title;                // Заголовок
	std::string authors;              // Авторы
	std::string content;              // Содержание
	std::string hash;                 // Хеш-код статьи
	unsigned long originalHash = 0;   // Хеш, полученный из файла
	unsigned long calculatedHash = 0; // Хеш, полученный из строителя

	XML() {};

	// Преобразование XML в строку
	std::string toString() override {
		std::string result;
		result += "<?xml version=\"1.0\"?>\n";
		result += "<ARTICLE>\n";
		result += title + "\n";
		result += authors + "\n";
		result += content + "\n";
		result += hash + "\n";
		result += "</ARTICLE>\n";

		return result;
	}

	bool checkHash() override {
		return originalHash == calculatedHash;
	}
};

// Базовый класс строителя
class Builder {
public:
	Builder() {};

	virtual void buildTitle() = 0;
	virtual void buildAuthors() = 0;
	virtual void buildContent() = 0;
	virtual void buildHash() = 0;
	virtual Product* getResult() = 0;
};

// Класс строителя XML
class XMLBuilder : public Builder {
	// Исходный текст, из которого формируется XML
protected:
	std::vector<std::string> lines;
	XML* product;
public:
	void buildTitle() override {
		product->title = "<TITLE>" + lines[0] + "</TITLE>";
	};

	void buildAuthors() override {
		product->authors = "<AUTHORS>" + lines[1] + "</AUTHORS>";
	};

	void buildContent() override {
		product->content = "<CONTENT>\n";
		for (int i = 2; i < lines.size() - 1; i++)
			product->content += lines[i] + "\n";
		product->content += "</CONTENT>";
	};
	
	void buildHash() override {
		std::hash<std::string> hasher;
		std::string fileContent;

		for (int i = 0; i < lines.size() - 1; i++)
			fileContent += lines[i];

		unsigned int calculatedHash = hasher(fileContent);
		std::cout << calculatedHash << "\n\n";
		product->hash = "<HASH>" + lines[lines.size() - 1] + "</HASH>";
		product->originalHash = atol(lines[lines.size() - 1].c_str());
		product->calculatedHash = calculatedHash;
	};

	Product* getResult() override {
		return product;
	}

	XMLBuilder(std::string source) {
		product = new XML();
		std::stringstream ss(source);
		std::string line;
		while (std::getline(ss, line)) {
			if (!line.empty())
				lines.push_back(line);
		}
	}
};

// Класс директора
class Director {
protected:
	Builder* builder;

public:
	Director(Builder* builder) {
		this->builder = builder;
	}

	void construct() {
		builder->buildTitle();
		builder->buildAuthors();
		builder->buildContent();
		builder->buildHash();
	}
};

