#include <iostream>
#include <string>
#include <vector>


// ����� ��� �������� �����
class Course {
public:
	// �������� �����
	std::string name;
	Course(std::string name) {
		this->name = name;
	}
};


// ����� ��� �������� ��������
class Person {
public:
	// ��� ��������
	std::string name;
	Person() {
		this->name = "NoName";
	};
	Person(std::string name) {
		this->name = name;
	}
};

// ����� ��� �������� ��������
class Student : public Person {
	// �����, �� ������� ������� �������
	std::vector<Course*> assigned_courses;
public:
	Student(std::string name) {
		this->name = name;
	}

	// ������� ������ �� ����
	void applyToCourse(Course* course);
	// ����� ���� ������, �� ������� ������� �������
	void printCourses();

};

// ��������������� ���������� �������
class Mark;
class Archive;

// ����� ��� �������� �������������
class Teacher : public Person {
public:
	Teacher(std::string name) {
		this->name = name;
	}

	// ������� ��� �������� �����
	Course createCourse(std::string name);
	// ������� ��� ������ �������� �� �����
	void rateStudent(Student* student, Course* course, int rate, Archive* archive);
};

// ����� ��� �������� ������
class Mark {
private:
	// �������������, ����������� ������
	Teacher* teacher;
	// �������, ���������� ������
	Student* student;
	// ����, �� �������� ���� ���������� ������
	Course* course;
	// ������
	int rate;
public:
	Mark(Teacher* teacher, Student* student, Course* course, int rate);
	// �������������� ������ � ������
	std::string toString();
};

// ����� ��� �������� ������
class Archive {
private:
	// ������, ���������� � ������
	std::vector<Mark> marks;
public:
	// ���������� ������ � �����
	void append(Mark mark);
	// ��������� ����� ������
	std::vector<Mark> getMarks();
	// ����� ����������� ������
	void printMarks();
};

// ������� ������ �� ����
void Student::applyToCourse(Course* course) {
	assigned_courses.push_back(course);
}

// ������� ������ ������, �� ������� ������� �������
void Student::printCourses() {
	std::cout << "������� " + this->name + " ������� �� ��������� �����:\n";
	for (int i = 0; i < assigned_courses.size(); i++) {
		std::cout << "#" << i << " " + assigned_courses[i]->name << "\n";
	}
}


// ������� �������� �����
Course Teacher::createCourse(std::string name) {
	return Course(name);
}

// ������� ����������� ������ �������� �� �����
void Teacher::rateStudent(Student* student, Course* course, int rate, Archive* archive) {
	Mark mark = Mark(this, student, course, rate);
	archive->append(mark);
}


Mark::Mark(Teacher* teacher, Student* student, Course* course, int rate) {
	this->teacher = teacher;
	this->student = student;
	this->course = course;
	this->rate = rate;
}

// ������� �������������� ������ � ������ ��� �������� ������
std::string Mark::toString() {
	return "������ " + std::to_string(rate) + " �� ����� " + course->name + " ���� ���������� �������� "
		+ student->name + " �������������� " + teacher->name;
}


// ���������� ������ � �����
void Archive::append(Mark mark) {
	marks.push_back(mark);
}

// ��������� ����� ������
std::vector<Mark> Archive::getMarks() {
	return marks;
}

// ����� ����������� ������
void Archive::printMarks() {
	for (int i = 0; i < marks.size(); i++) {
		std::cout << "#" << i << " " + marks[i].toString() << "\n";
	}
}


int main() {
	setlocale(LC_ALL, "Russian");

	// �������� ���������
	Student studentA(std::string("����"));
	Student studentB(std::string("����"));

	// �������� ��������������
	Teacher teacherA(std::string("�������� ������ ����������"));
	Teacher teacherB(std::string("�������� ������� ����������"));

	// ������� ������
	Course courseA = teacherA.createCourse(std::string("�������������� ��"));
	Course courseB = teacherB.createCourse(std::string("���������� ����������� ��"));

	// �������� ������
	Archive archive;

	// ������ ��������� �� �����
	studentA.applyToCourse(&courseA);
	studentA.applyToCourse(&courseB);
	studentB.applyToCourse(&courseB);

	// ����� ������, �� ������� �������� ��������
	studentA.printCourses();
	std::cout << "\n";
	studentB.printCourses();
	std::cout << "\n";

	// ����������� ������ ���������
	teacherA.rateStudent(&studentA, &courseA, 5, &archive);
	teacherA.rateStudent(&studentA, &courseB, 4, &archive);
	teacherA.rateStudent(&studentB, &courseB, 3, &archive);

	// ����� ����������� ������
	archive.printMarks();

	return 0;
}
