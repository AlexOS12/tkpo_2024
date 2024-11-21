#include <iostream>
#include <string>

// Базовый класс для субтитров
class BaseSubtitle {
protected:
	std::string text;

public:
	std::string read() {
		return text;
	}

	BaseSubtitle() {
		text = "Базовый текст базовых субтитров";
	}
};

// Субтитры на русском языке
class RuSubtitle : public BaseSubtitle {
public:
	RuSubtitle() {
		text = "Субтитры на русском языке";
	}
};

// Субтитры на английском языке
class EnSubtitle : public BaseSubtitle {
public:
	EnSubtitle() {
		this->text = "Subtitles in English";
	}
};

// Субтитры на немецком языке
class DeSubtitle : public BaseSubtitle {
public:
	DeSubtitle() {
		this->text = "Untertitel auf Deutsch";
	}
};


// Базовый класс звуковой дорожки
class BaseSoundtrack {
protected:
	std::string language;
	BaseSubtitle* subtitle;

public:
	BaseSoundtrack() {
		this->language = "NoLang";
		this->subtitle = nullptr;
	}

	// Воспроизведение звуковой дорожки
	void play() {
		std::cout << "Язык звуковой дорожки: " << language << "\n";
		std::cout << "Текст субтитров:\n";
		std::cout << subtitle->read() << "\n";
	}
};


// Звуковая дорожка на русском языке
class RuSoundtrack : public BaseSoundtrack {
public:
	RuSoundtrack(RuSubtitle* subtitle) {
		this->language = "Русский";
		this->subtitle = subtitle;
	};
};

// Звуковая дорожка на английском языке
class EnSoundtrack : public BaseSoundtrack {
public:
	EnSoundtrack(EnSubtitle* subtitle) {
		this->language = "English";
		this->subtitle = subtitle;
	};
};

// Звуковая дорожка на английском языке
class DeSoundtrack : public BaseSoundtrack {
public:
	DeSoundtrack(DeSubtitle* subtitle) {
		this->language = "Deutsch";
		this->subtitle = subtitle;
	};
};

// Базовый класс фильма
class BaseMovie {
protected:
	std::string language;
	BaseSoundtrack* soundtrack;

public:
	BaseMovie() {
		language = "NoLang";
		soundtrack = nullptr;
	}

	void play() {
		std::cout << "Язык фильма: " << language << "\n";
		std::cout << "Звуковая дорожка:\n";
		soundtrack->play();
	}
};

// Класс фильма на русском языке
class RuMovie : public BaseMovie {
public:
	RuMovie(RuSoundtrack* soundtrack) {
		this->language = "Русский";
		this->soundtrack = soundtrack;
	}
};

// Класс фильма на английском языке
class EnMovie : public BaseMovie {
public:
	EnMovie(EnSoundtrack* soundtrack) {
		this->language = "English";
		this->soundtrack = soundtrack;
	}
};

// Класс фильма на немецокм языке
class DeMovie : public BaseMovie {
public:
	DeMovie(DeSoundtrack* soundtrack) {
		this->language = "Deutsch";
		this->soundtrack = soundtrack;
	}
};


// Абстрактная фабрика фильмов
class AbstractMovieFactory {
public:
	virtual BaseMovie* createMovie() = 0;
};

// Фабрика фильмов на русском языке
class RuMovieFactory : public AbstractMovieFactory {
public:
	BaseMovie* createMovie() {
		RuSubtitle* subtitle = new RuSubtitle();
		RuSoundtrack* soundtrack = new RuSoundtrack(subtitle);
		RuMovie* movie = new RuMovie(soundtrack);
		return movie;
	}
};

// Фабрика фильмов на английском
class EnMovieFactory : public AbstractMovieFactory {
public:
	BaseMovie* createMovie() {
		EnSubtitle* subtitle = new EnSubtitle;
		EnSoundtrack* soundtrack = new EnSoundtrack(subtitle);
		EnMovie* movie = new EnMovie(soundtrack);
		return movie;
	}
};
// Фабрика фильмов на немецком
class DeMovieFactory : public AbstractMovieFactory {
public:
	BaseMovie* createMovie() {
		DeSubtitle* subtitle = new DeSubtitle;
		DeSoundtrack* soundtrack = new DeSoundtrack(subtitle);
		DeMovie* movie = new DeMovie(soundtrack);
		return movie;
	}
};