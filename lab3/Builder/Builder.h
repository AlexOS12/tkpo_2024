#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <cstdlib>

// ������� ����� ��������
class Product {
public:
	Product() {};
	// ������ �������������� �������� � ������
	virtual std::string toString() = 0;
	virtual bool checkHash() = 0;
};

// ����� XML
class XML : public Product {
public:
	std::string title;                // ���������
	std::string authors;              // ������
	std::string content;              // ����������
	std::string hash;                 // ���-��� ������
	unsigned long originalHash = 0;   // ���, ���������� �� �����
	unsigned long calculatedHash = 0; // ���, ���������� �� ���������

	XML() {};

	// �������������� XML � ������
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

// ������� ����� ���������
class Builder {
public:
	Builder() {};

	virtual void buildTitle() = 0;
	virtual void buildAuthors() = 0;
	virtual void buildContent() = 0;
	virtual void buildHash() = 0;
	virtual Product* getResult() = 0;
};

// ����� ��������� XML
class XMLBuilder : public Builder {
	// �������� �����, �� �������� ����������� XML
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

// ����� ���������
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

