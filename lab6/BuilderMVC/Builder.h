#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>
#include <iostream>

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
	unsigned long long originalHash = 0;   // Хеш, полученный из файла
	unsigned long long calculatedHash = 0; // Хеш, полученный из строителя

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

// Класс HTML
class HTML : public Product {
public:
    std::string title;                // Заголовок
    std::string authors;              // Авторы
    std::string content;              // Содержание
    std::string hash;                 // Хеш-код статьи
    unsigned long long originalHash = 0;   // Хеш, полученный из файла
    unsigned long long calculatedHash = 0; // Хеш, полученный из строителя

    HTML() {};

    // Преобразование HTML в строку
    std::string toString() override {
        std::string result;
        result += "<!DOCTYPE html>\n";
        result += "<html>\n";

        result += "<body>\n";
        result += title + "\n";
        result += authors + "\n";
        result += content + "\n";
        result += hash + "\n";
        result += "</body>\n";
        result += "</html>\n";

        result += "original hash:" + std::to_string(originalHash) + "\n";
        result += "original hash:" + std::to_string(calculatedHash);
        return result;
    }

    bool checkHash() override {
        return originalHash == calculatedHash;
    }
};

// Класс JSON
class JSON : public Product {
public:
    std::string title;                // Заголовок
    std::string authors;              // Авторы
    std::string content;              // Содержание
    std::string hash;                 // Хеш-код статьи
    unsigned long long originalHash = 0;   // Хеш, полученный из файла
    unsigned long long calculatedHash = 0; // Хеш, полученный из строителя

    JSON() {};

    // Преобразование HTML в строку
    std::string toString() override {
        std::string result;

        result += "{\n";

        result += title + "\",\n";
        result += authors + "\",\n";
        result += content + ",\n";
        result += hash + "\n";

        result += "}";

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

        unsigned long long calculatedHash = hasher(fileContent);
        product->hash = "<HASH>" + lines[lines.size() - 1] + "</HASH>";
        product->originalHash = std::stoull(lines[lines.size() - 1]);
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

// Класс строителя HTML
class HTMLBuilder : public Builder {
    // Исходный текст, из которого формируется XML
protected:
    std::vector<std::string> lines;
    HTML* product;
public:
    void buildTitle() override {
        product->title = "<h1>" + lines[0] + "</h1>";
    };

    void buildAuthors() override {
        product->authors = "<h5>" + lines[1] + "</h5>";
    };

    void buildContent() override {
        product->content = "<p>\n";
        for (int i = 2; i < lines.size() - 1; i++)
            product->content += lines[i] + "\n";
        product->content += "</p>";
    };


    void buildHash() override {
        std::hash<std::string> hasher;
        std::string fileContent;


        for (int i = 0; i < lines.size() - 1; i++)
            fileContent += lines[i];

        qDebug() << fileContent << "\n\n";

        unsigned long long calculatedHash = hasher(fileContent);
        product->hash = "<i> Hashum:" + lines[lines.size() - 1] + "</i>";
        product->originalHash = std::stoull(lines[lines.size() - 1]);
        product->calculatedHash = calculatedHash;
    };

    Product* getResult() override {
        return product;
    }

    HTMLBuilder(std::string source) {
        product = new HTML();
        qDebug() << source << "\n";
        std::stringstream ss(source);
        std::string line;
        while (std::getline(ss, line)) {
            if (!line.empty())
                lines.push_back(line);
        }
    }
};

// Класс строителя JSON
class JSONBuilder : public Builder {
    // Исходный текст, из которого формируется XML
protected:
    std::vector<std::string> lines;
    JSON* product;
public:
    void buildTitle() override {
        product->title = "\"title\" : " + lines[0];
    };

    void buildAuthors() override {
        product->authors = "\"authors\" : " + lines[1];
    };

    void buildContent() override {
        product->content = "\"content\" : \"";
        for (int i = 2; i < lines.size() - 1; i++)
            product->content += "\n" + lines[i];
        product->content += "\"";
    };


    void buildHash() override {
        std::hash<std::string> hasher;
        std::string fileContent;

        for (int i = 0; i < lines.size() - 1; i++)
            fileContent += lines[i];

        unsigned long long calculatedHash = hasher(fileContent);
        product->hash = "\"hash\" : " + lines[lines.size() - 1];
        product->originalHash = std::stoull(lines[lines.size() - 1]);
        product->calculatedHash = calculatedHash;
    };

    Product* getResult() override {
        return product;
    }

    JSONBuilder(std::string source) {
        product = new JSON();
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
