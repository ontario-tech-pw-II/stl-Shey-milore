// Student class is implemented based on string and do not need any change

#include <iostream>
#include <string>
#include <list>

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
	int n;
	double grade;
	char name[200];
	
	list<Student> student_list;
	list<Student>::iterator p; 
	list<Student>::reverse_iterator r; 




	cout << "Enter the number of students: ";
	cin >> n; 

	for (int i = 0; i < n; ++i)
	{
		
		cout << "Enter the name: ";
		cin >> name; 

		cout << "Enter the grade: ";
		cin >> grade; 

		Student x(name,grade);  // creating the student object

		p = student_list.begin();
		
		while (p != student_list.end() && p->getgrade() < grade)
			p++;

		student_list.insert(p,x);	
	}

	// print in ascending order

	cout << "Print list in ascending order:" << endl;

	for(p = student_list.begin(); p != student_list.end(); p++)
		cout << *p << endl;

	// print in descending order

	cout << "Print list in descending order:" << endl;

	for(r = student_list.rbegin(); r != student_list.rend(); r++)
		cout << *r << endl;

	return 0;
		
}



