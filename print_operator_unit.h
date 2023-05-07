#ifndef PRINT_OPERATOR_UNIT_H
#define PRINT_OPERATOR_UNIT_H

#include "unit.h"

class PrintOperatorUnit : public Unit {
public:
    explicit PrintOperatorUnit(const std::string& text) : m_text( text ) { }    // Конструктор - принимает текст

protected:
    std::string m_text; // Текст, выводимый на экран
};

#endif // PRINT_OPERATOR_UNIT_H
