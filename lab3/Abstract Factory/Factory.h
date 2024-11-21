#include <iostream>
#include <string>

// ������� ����� ��� ���������
class BaseSubtitle {
protected:
	std::string text;

public:
	std::string read() {
		return text;
	}

	BaseSubtitle() {
		text = "������� ����� ������� ���������";
	}
};

// �������� �� ������� �����
class RuSubtitle : public BaseSubtitle {
public:
	RuSubtitle() {
		text = "�������� �� ������� �����";
	}
};

// �������� �� ���������� �����
class EnSubtitle : public BaseSubtitle {
public:
	EnSubtitle() {
		this->text = "Subtitles in English";
	}
};

// �������� �� �������� �����
class DeSubtitle : public BaseSubtitle {
public:
	DeSubtitle() {
		this->text = "Untertitel auf Deutsch";
	}
};


// ������� ����� �������� �������
class BaseSoundtrack {
protected:
	std::string language;
	BaseSubtitle* subtitle;

public:
	BaseSoundtrack() {
		this->language = "NoLang";
		this->subtitle = nullptr;
	}

	// ��������������� �������� �������
	void play() {
		std::cout << "���� �������� �������: " << language << "\n";
		std::cout << "����� ���������:\n";
		std::cout << subtitle->read() << "\n";
	}
};


// �������� ������� �� ������� �����
class RuSoundtrack : public BaseSoundtrack {
public:
	RuSoundtrack(RuSubtitle* subtitle) {
		this->language = "�������";
		this->subtitle = subtitle;
	};
};

// �������� ������� �� ���������� �����
class EnSoundtrack : public BaseSoundtrack {
public:
	EnSoundtrack(EnSubtitle* subtitle) {
		this->language = "English";
		this->subtitle = subtitle;
	};
};

// �������� ������� �� ���������� �����
class DeSoundtrack : public BaseSoundtrack {
public:
	DeSoundtrack(DeSubtitle* subtitle) {
		this->language = "Deutsch";
		this->subtitle = subtitle;
	};
};

// ������� ����� ������
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
		std::cout << "���� ������: " << language << "\n";
		std::cout << "�������� �������:\n";
		soundtrack->play();
	}
};

// ����� ������ �� ������� �����
class RuMovie : public BaseMovie {
public:
	RuMovie(RuSoundtrack* soundtrack) {
		this->language = "�������";
		this->soundtrack = soundtrack;
	}
};

// ����� ������ �� ���������� �����
class EnMovie : public BaseMovie {
public:
	EnMovie(EnSoundtrack* soundtrack) {
		this->language = "English";
		this->soundtrack = soundtrack;
	}
};

// ����� ������ �� �������� �����
class DeMovie : public BaseMovie {
public:
	DeMovie(DeSoundtrack* soundtrack) {
		this->language = "Deutsch";
		this->soundtrack = soundtrack;
	}
};


// ����������� ������� �������
class AbstractMovieFactory {
public:
	virtual BaseMovie* createMovie() = 0;
};

// ������� ������� �� ������� �����
class RuMovieFactory : public AbstractMovieFactory {
public:
	BaseMovie* createMovie() {
		RuSubtitle* subtitle = new RuSubtitle();
		RuSoundtrack* soundtrack = new RuSoundtrack(subtitle);
		RuMovie* movie = new RuMovie(soundtrack);
		return movie;
	}
};

// ������� ������� �� ����������
class EnMovieFactory : public AbstractMovieFactory {
public:
	BaseMovie* createMovie() {
		EnSubtitle* subtitle = new EnSubtitle;
		EnSoundtrack* soundtrack = new EnSoundtrack(subtitle);
		EnMovie* movie = new EnMovie(soundtrack);
		return movie;
	}
};
// ������� ������� �� ��������
class DeMovieFactory : public AbstractMovieFactory {
public:
	BaseMovie* createMovie() {
		DeSubtitle* subtitle = new DeSubtitle;
		DeSoundtrack* soundtrack = new DeSoundtrack(subtitle);
		DeMovie* movie = new DeMovie(soundtrack);
		return movie;
	}
};