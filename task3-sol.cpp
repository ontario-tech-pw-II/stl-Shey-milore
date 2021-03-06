// Student class is implemented based on string and do not need any change

#include <iostream>
#include <fstream>

#include <string>
#include <map>

using namespace std;

// ----------------------------- Base class

class Person{
	protected:
		string name;
	    
	public:
		void setname(char const *);
		string getname();


		Person(); 				// default constructor
		Person(const char *);
		Person(const Person &); 		// copy constructor

		Person(const string &);

		virtual ~Person();

};

void Person::setname(char const *n)
{
	name = n;
}

string Person::getname()
{
	return name;
}


Person::Person()
{
	name = "";
}

Person::Person(char const *n)
{
	setname(n);
}

Person::Person(const string & n)
{
	name = n;
}

Person::~Person()
{
}

Person::Person(const Person &t):name(t.name)
{
}

// -----------------------------  Student class

class Student : public Person{
	private:
		double grade;

	public:
      	
      	void setgrade(double);
      	double getgrade();

      	Student();    // default constructor
		Student(char const *, double);
		Student(const Student &);  // copy constructor

		~Student();

	friend ostream & operator<<(ostream &, const Student &);

};

void Student::setgrade(double g)
{
	grade =g;
}

double Student::getgrade()
{
	return grade;
}

ostream & operator<<(ostream & out, const Student & s)
{
		out << s.name << "," << s.grade;
		return out;

}

Student::Student(): grade(0)
{
}

Student::Student(char const *n, double g): Person(n)
{
	setgrade(g);
}

Student::Student(const Student &t):Person(t.name)
{
	grade = t.grade;
}

Student::~Student()
{
}

int main()
{  
	string name;
	double grade;

	map<string, int> student_names;
    map<string, int>::iterator p;

	ifstream fin("input_file.txt");

	if (fin.fail()) // check if it is successful 
 	{
 		cerr << " Cannot open the input file!" << endl;
 		return 1;
 	}
 	
	while (fin >> name && fin >> grade){
			p = student_names.find(name);
			if(p == student_names.end())  // does not exist
				if (grade < 50)
					student_names[name] = 1  ; // set the count to 1
				else 
					student_names[name] = 0  ; // set the count to 0
			else
				if (grade < 50)
					p -> second += 1; 
	}

	for(p = student_names.begin(); p != student_names.end(); p++)
		cout << p->first << " "<< p->second << endl;

	return 0;
		
}



