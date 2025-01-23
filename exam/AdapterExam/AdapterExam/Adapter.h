#pragma once
#include <string>
#include <fstream>
#include <vector>


// Класс сервиса, который пишет по блочно
class Service 
{
private:
	std::ofstream file;

public:
	Service() {}

	// Функция для открытия файла
	void OpenFile(std::string path) {
		file.open(path);
	}

	// Функция закрытия файла
	void CloseFile() {
		file.close();
	}

	// Функция для записи блока
	// На конце обязательно \0
	void WriteBlockToFile(char block[6]) {
		file << block;
	}
};

// Интерфейс для Адаптера
class AdapterInterface {
public:
	virtual void Open(std::string path) = 0;
	virtual void Close() = 0;
	virtual void WriteCharToFile(char c) = 0;
};

// Класс адаптера, который позволяет писать клиенту по символьно
class Adapter  : protected Service, protected AdapterInterface {
private:
	// Временный блок для формирования блока
	std::vector<char> tempBlock;

public:
	// Делегируем конструктор
	Adapter() : Service() {}

	// Для открытия файла
	void Open(std::string path) override {
		OpenFile(path);
	}

	// Для закрытия файла
	void Close() override {
		// Если есть еще незаписанные символы
		if (tempBlock.size() != 0) {
			// Дополняем блок нулями в конце
			for (int i = tempBlock.size() - 1; i < 5; i++)
				tempBlock.push_back(0);

			char block[5];
			for (int i = 0; i < 5; i++)
				block[i] = tempBlock[i];

			// Записываем оставшиеся символы в файл
			WriteBlockToFile(block);
		}

		CloseFile();
	}

	// Для посимвольной записи в файл
	void WriteCharToFile(char c) override {
		tempBlock.push_back(c);

		if (tempBlock.size() == 5) {
			char block[6];
			for (int i = 0; i < 5; i++) {
				block[i] = tempBlock[i];
			}
			block[5] = '\0';
			WriteBlockToFile(block);
			tempBlock.clear();
		}
	}
};

