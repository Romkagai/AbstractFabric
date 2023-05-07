#ifndef PRINT_OPERATOR_UNIT_CPP_H
#define PRINT_OPERATOR_UNIT_CPP_H

#include "print_operator_unit.h"

class PrintOperatorUnitCpp : public PrintOperatorUnit {
public:
    explicit PrintOperatorUnitCpp(const std::string& text) : PrintOperatorUnit(text) { }
    // В С++ используем printf
    std::string compile( unsigned int level = 0 ) const {
        return generateShift(level) + "printf(\"" + m_text + "\");\n";
    }
};

#endif // PRINT_OPERATOR_UNIT_CPP_H
