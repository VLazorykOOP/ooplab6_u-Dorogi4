#include "Lab6Example.h"
#include <iostream>
#include <string>
using namespace std;
namespace SpaceExample3 {
    // MultipleiInherance.cpp 
// Ієрархія типів складається з сутностей: 
// машина, пасажирський транспорт і автобус.
//

#include <iostream>
#include <string>

    using namespace std;

    class Entity {
    protected:
        string name;
        int age;
    public:
        Entity(string _name, int _age) : name(_name), age(_age) {}
        virtual ~Entity() {}
        virtual void printInfo() {
            cout << "Name: " << name << endl;
            cout << "Age: " << age << endl;
        }
    };

    class Parent : virtual public Entity {
    protected:
        string occupation;
    public:
        Parent(string _name, int _age, string _occupation) : Entity(_name, _age), occupation(_occupation) {}
        virtual ~Parent() {}
        virtual void printInfo() {
            Entity::printInfo();
            cout << "Occupation: " << occupation << endl;
        }
    };

    class Mother : virtual public Parent {
    protected:
        string maternalLineage;
    public:
        Mother(string _name, int _age, string _occupation, string _maternalLineage) : Entity(_name, _age), Parent(_name, _age, _occupation), maternalLineage(_maternalLineage) {}
        virtual ~Mother() {}
        virtual void printInfo() {
            Parent::printInfo();
            cout << "Maternal Lineage: " << maternalLineage << endl;
        }
    };

    class Father : virtual public Parent {
    protected:
        string paternalLineage;
    public:
        Father(string _name, int _age, string _occupation, string _paternalLineage) : Entity(_name, _age), Parent(_name, _age, _occupation), paternalLineage(_paternalLineage) {}
        virtual ~Father() {}
        virtual void printInfo() {
            Parent::printInfo();
            cout << "Paternal Lineage: " << paternalLineage << endl;
        }
    };

    class Daughter : public Mother, public Father {
    public:
        Daughter(string _name, int _age, string _occupation, string _maternalLineage, string _paternalLineage) : Entity(_name, _age), Parent(_name, _age, _occupation), Mother(_name, _age, _occupation, _maternalLineage), Father(_name, _age, _occupation, _paternalLineage) {}
        virtual ~Daughter() {}
        virtual void printInfo() {
            Mother::printInfo();
            Father::printInfo();
        }
    };

    int mainExample3() {
        Entity entity("John", 40);
        entity.printInfo();
        cout << endl;

        Parent parent("Mary", 35, "Teacher");
        parent.printInfo();
        cout << endl;

        Mother mother("Alice", 60, "Nurse", "Smith");
        mother.printInfo();
        cout << endl;

        Father father("Bob", 65, "Engineer", "Johnson");
        father.printInfo();
        cout << endl;

        Daughter daughter("Lily", 15, "Student", "Smith", "Johnson");
        daughter.printInfo();
        cout << endl;

        return 0;
    }
}