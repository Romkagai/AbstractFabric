#ifndef PRINT_OPERATOR_UNIT_C_SHARP_H
#define PRINT_OPERATOR_UNIT_C_SHARP_H

#include "print_operator_unit.h"

class PrintOperatorUnitCSharp : public PrintOperatorUnit {
public:
    explicit PrintOperatorUnitCSharp(const std::string& text) : PrintOperatorUnit(text) { }
    // В С# используем Console.WriteLine
    std::string compile( unsigned int level = 0 ) const {
        return generateShift(level) + "Console.WriteLine(\"" + m_text + "\");\n";
    }
};

#endif // PRINT_OPERATOR_UNIT_C_SHARP_H
