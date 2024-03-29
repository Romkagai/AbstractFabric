#include <QCoreApplication>
#include <iostream>
#include "abstract_factory.h"
using namespace std;

// Для полного соответствия поставленной задаче создадим функцию, которая будет генерировать код по шаблону из задачи
// В функцию будем передавать абстрактуную фабрику, но при её вызове будем пользоваться конкретной
// Не знаю, как корректно это сделать, поэтому использую шаблон, чтобы компилятор сам разобрался
template <typename T>
std::string generateProgramFromTask(std::shared_ptr<T> ProgrammFactory) {
    auto myClass = ProgrammFactory->MakeClass("MyClass");
    auto func1 = ProgrammFactory->MakeMethod("testFunc1", "void", 0);
    auto func2 = ProgrammFactory->MakeMethod("testFunc2", "void", MethodUnit::STATIC);
    auto func3 = ProgrammFactory->MakeMethod("testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST);
    auto func4 = ProgrammFactory->MakeMethod("testFunc4", "void", MethodUnit::VIRTUAL | MethodUnit::CONST);
    auto print = ProgrammFactory->MakePrintOperatorUnit("Hello World!");

    func4->add(print);
    myClass->add(func1, ClassUnit::PUBLIC);
    myClass->add(func2, ClassUnit::PRIVATE);
    myClass->add(func3, ClassUnit::PUBLIC);
    myClass->add(func4, ClassUnit::PROTECTED);
    return myClass->compile();
}

template <typename T>
std::string generateProgramTest(std::shared_ptr<T> ProgrammFactory) {
    // Создаем класс
    auto myClass = ProgrammFactory->MakeClass("TestClass");

    // Создаем функции
    // Абстрактной финальной функции не может существовать (JAVA), а в С++ и С# таких определений нет.
    auto func1 = ProgrammFactory->MakeMethod("FunctionOne", "void", MethodUnit::FINAL | MethodUnit::ABSTRACT);

    // В JAVA нет VIRTUAL, а в С++ и C# не бывает STATIC и VIRTUAL метода одновременно
    auto func2 = ProgrammFactory->MakeMethod("FunctionTwo", "int", MethodUnit::VIRTUAL | MethodUnit::STATIC);

    // Создадим оператор вывода
    auto print = ProgrammFactory->MakePrintOperatorUnit("I am function one!");
    auto print2 = ProgrammFactory->MakePrintOperatorUnit("I am function two!");

    // Тест различных вложений
    // Просто вкладываем функции как положено
    myClass->add(func1, ClassUnit::PRIVATE_PROTECTED);
    myClass->add(func2, ClassUnit::PRIVATE);
    func1->add(print);
    func2->add(print2);


    // Вкладываем класс в класс (создадим еще один)                 // Вложился, языки позволяют вкладывать класс в класс
    //auto myClass2 = ProgrammFactory->MakeClass("TestClass2");       // Но нужна ли точная реализация под задачу?
    //myClass->add(myClass2, ClassUnit::PUBLIC);

    // Вкладываем оператор печати в класс
    //myClass->add(print, ClassUnit::PUBLIC);                         // Вложился (не баг, а фича)

    //Вкладываем класс в метод                                      // Программа ломается
    //func2->add(myClass);

    //Вкладываем метод в метод                                      // Вложился (не баг, а фича)
    //func2->add(func1);

    //Вкладываем класс в оператор печати                            // Ловим error определенный в unit
    //print->add(myClass, 0);

    //Вкладываем оператор печати в оператор печати                  // Ловим error определенный в unit
    //print -> add(print,0);

    return myClass->compile();
}


int main()
{

//    cout << "Programm from task on C++" << endl;
//    cout << generateProgramFromTask(std::make_shared<ProgrammFactoryCpp>());    // Код корректно генерируется, как из условия задачи
//    cout << endl << "Press enter to continue";
//    getchar(); system("cls");

//    cout << "Programm from task on C#" << endl;
//    cout << generateProgramFromTask(std::make_shared<ProgrammFactoryCSharp>());  // Код корректно генерируется, как из условия задачи
//    cout << endl << "Press enter to continue";
//    getchar(); system("cls");

//    cout << "Programm from task on Java" << endl;
//    cout << generateProgramFromTask(std::make_shared<ProgrammFactoryJava>());    // Код корректно генерируется, как из условия задачи
//    cout << endl << "Press enter to continue";
//    getchar(); system("cls");


    cout << "Programm from task on C++" << endl;
    cout << generateProgramTest(std::make_shared<ProgrammFactoryCpp>());    // Код корректно генерируется, в соответствии с С++
    cout << endl << "Press enter to continue";
    getchar(); system("cls");

    cout << "Programm from task on C#" << endl;
    cout << generateProgramTest(std::make_shared<ProgrammFactoryCSharp>());  // Код корректно генерируется, в соответствии с С#
    cout << endl << "Press enter to continue";
    getchar(); system("cls");

    cout << "Programm from task on Java" << endl;
    cout << generateProgramTest(std::make_shared<ProgrammFactoryJava>());    // Код корректно генерируется, в соответствии с Java
    cout << endl << "Press enter to continue";
    getchar(); system("cls");

    return 0;
}



