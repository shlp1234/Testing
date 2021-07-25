// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

class MyObject
{   // build copy constructor, overload assignment operator, build default constructor,
    // need default constructor
    private:
        int age;
        std::string name;

    public:
        // default constructor
        MyObject() {}

        // assignment constructor
        MyObject(int cAge, std::string cName) : age(cAge), name(cName)
        {
            std::cout << "Assignment constructor running" << std::endl;
        }

        // copy constructor
        MyObject(MyObject& arg)
        {
            std::cout << "Copy constructor running" << std::endl;
            age = arg.age;
            name = arg.name;
        }

        // overloaded assignment operator
        const MyObject operator=(const MyObject& other)
        {
            std::cout << "overloaded assignment operator running" << std::endl;
            age = other.age;
            name = other.name;

            return *this;
        }

        // destructor
        ~MyObject()
        {
            std::cout << "Destructor running." << std::endl;
        }

        // setter function
        void setAge(int sAge) 
        { age = sAge; }

        // getter function
        int getAge()
        { return age; }

        // setter function
        void setName(std::string sName)
        { name = sName; }

        // getter function
        std::string getName()
        { return name; }

        void print()
        {
            std::cout << "Age: " << age << std::endl;
            std::cout << "Name: " << name << std::endl;
        }
};

int main()
{
    std::cout << "Hello World!\n";
    MyObject obj1;

    obj1.setAge(33);
    obj1.setName("Mike");

    std::cout << "----------" << std::endl;
    obj1.print();
    std::cout << "----------" << std::endl;

    MyObject obj2;
    // std::cout << "----------" << std::endl;
    obj2 = obj1;
    std::cout << "----------" << std::endl;

    std::cout << "----------" << std::endl;
    obj2.print();
    std::cout << "----------" << std::endl;

    MyObject obj3 = obj1;
    std::cout << "----------" << std::endl;
    obj3.print();
    std::cout << "----------" << std::endl;

    // "obj4" and "obj2" runs copy constructor and assignment operator
    // "obj3" runs only the copy constructor
    MyObject obj4;
    obj4 = obj1;
    obj4.print();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
