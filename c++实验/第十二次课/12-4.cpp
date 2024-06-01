#include <iostream>
#include <string>
using namespace std;

class Student {
protected:
	int No;
	string Name;
	char Gender;
	string ProClass;
	
public:
	Student(int no, const string& name, char gender, const string& proClass)
	: No(no), Name(name), Gender(gender), ProClass(proClass) {}
	
	void SelectCourse() {
		cout << "Student " << Name << " is selecting courses." << endl;
	}
	
	void Study() {
		cout << "Student " << Name << " is studying." << endl;
	}
	
	void TakeAnExam() {
		cout << "Student " << Name << " is taking an exam." << endl;
	}
	
	void Training() {
		cout << "Student " << Name << " is doing sports training." << endl;
	}
	
	void Rest() {
		cout << "Student " << Name << " is taking a rest." << endl;
	}
};

class Master : virtual public Student {
protected:
	int ExperimentNum;
	
public:
	Master(int no, const string& name, char gender, const string& proClass, int experimentNum)
	: Student(no, name, gender, proClass), ExperimentNum(experimentNum) {}
	
	void ShowExperimentNum() {
		cout << "Master " << Name << " has conducted " << ExperimentNum << " experiments." << endl;
	}
};

class Doctor : public Master {
protected:
	int PaperNum;
	
public:
	Doctor(int no, const string& name, char gender, const string& proClass, int experimentNum, int paperNum)
	: Student(no, name, gender, proClass), Master(no, name, gender, proClass, experimentNum), PaperNum(paperNum) {}
	
	void ShowPaperNum() {
		cout << "Doctor " << Name << " has written " << PaperNum << " papers." << endl;
	}
};

class DoctorWithoutMaster : virtual public Student {
protected:
	int ExperimentNum;
	int PaperNum;
	
public:
	DoctorWithoutMaster(int no, const string& name, char gender, const string& proClass, int experimentNum, int paperNum)
	: Student(no, name, gender, proClass), ExperimentNum(experimentNum), PaperNum(paperNum){}
	
	void ShowExperimentNum() {
		cout << "DoctorWithoutMaster " << Name << " has conducted " << ExperimentNum << " experiments." << endl;
	}
	
	void ShowPaperNum() {
		cout << "DoctorWithoutMaster " << Name << " has written " << PaperNum << " papers." << endl;
	}
};

int main() {
	Master m(123, "John", 'M', "CS101", 5);
	Doctor d(456, "Alice", 'F', "CS201", 8, 10);
	DoctorWithoutMaster dm(789, "Tom", 'M', "CS202", 10, 12);
	
	m.SelectCourse();
	m.Study();
	m.TakeAnExam();
	m.Training();
	m.Rest();
	m.ShowExperimentNum();
	
	cout << endl;
	
	d.SelectCourse();
	d.Study();
	d.TakeAnExam();
	d.Training();
	d.Rest();
	d.ShowExperimentNum();  // Note: Doctor has access to Master's member functions.
	d.ShowPaperNum();
	
	cout << endl;
	
	dm.SelectCourse();
	dm.Study();
	dm.TakeAnExam();
	dm.Training();
	dm.Rest();
	dm.ShowExperimentNum(); 
	dm.ShowPaperNum();
	
	return 0;
}

