#ifndef ABSTRACT_FACTORY_H
#define ABSTRACT_FACTORY_H

#include "class_unit_cpp.h"
#include "method_unit_cpp.h"
#include "print_operator_unit_cpp.h"

#include "class_unit_c_sharp.h"
#include "method_unit_c_sharp.h"
#include "print_operator_unit_c_sharp.h"

#include "class_unit_java.h"
#include "method_unit_java.h"
#include "print_operator_unit_java.h"

// Для решения задачи реализуем фабрику таким образом, чтобы на вызов функций возвращался указатель на объект "созданный" фабрикой
// Создаем абстрактную фабрику с необходимыми методами
class ProgrammFactory{
public:
    virtual std::shared_ptr<ClassUnit> MakeClass(const std::string &name) const = 0;
    virtual std::shared_ptr<MethodUnit> MakeMethod(const std::string & name, const std::string & returnType, Unit::Flags flags) const = 0;
    virtual std::shared_ptr<PrintOperatorUnit> MakePrintOperatorUnit(const std::string& text) const = 0;
    virtual ~ProgrammFactory() = default;
};

// Создаем конкретные реализации фабрик
// Фабрика генерирующая объект с языком С++
class ProgrammFactoryCpp : ProgrammFactory
{
public:
    std::shared_ptr<ClassUnit> MakeClass(const std::string &name) const
    {
        return std::make_shared<ClassUnitCpp>(name);
    }
    std::shared_ptr<MethodUnit> MakeMethod(const std::string & name, const std::string & returnType, Unit::Flags flags) const
    {
        return std::make_shared<MethodUnitCpp>(name, returnType, flags);
    }
    std::shared_ptr<PrintOperatorUnit> MakePrintOperatorUnit(const std::string& text) const
    {
        return std::make_shared<PrintOperatorUnitCpp>(text);
    };
};

// Фабрика генерирующая объект с языком С#
class ProgrammFactoryCSharp : ProgrammFactory
{
public:
    std::shared_ptr<ClassUnit> MakeClass(const std::string &name) const
    {
        return std::make_shared<ClassUnitCSharp>(name);
    }
    std::shared_ptr<MethodUnit> MakeMethod(const std::string & name, const std::string & returnType, Unit::Flags flags) const
    {
        return std::make_shared<MethodUnitCSharp>(name, returnType, flags);
    }
    std::shared_ptr<PrintOperatorUnit> MakePrintOperatorUnit(const std::string& text) const
    {
        return std::make_shared<PrintOperatorUnitCSharp>(text);
    };
};

// Фабрика генерирующая объект с языком Java
class ProgrammFactoryJava : ProgrammFactory
{
public:
    std::shared_ptr<ClassUnit> MakeClass(const std::string &name) const
    {
        return std::make_shared<ClassUnitJava>(name);
    }
    std::shared_ptr<MethodUnit> MakeMethod(const std::string & name, const std::string & returnType, Unit::Flags flags) const
    {
        return std::make_shared<MethodUnitJava>(name, returnType, flags);
    }
    std::shared_ptr<PrintOperatorUnit> MakePrintOperatorUnit(const std::string& text) const
    {
        return std::make_shared<PrintOperatorUnitJava>(text);
    };
};



#endif // ABSTRACT_FACTORY_H
