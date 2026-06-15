#ifndef CSHARPPRINTOPERATORUNIT_H
#define CSHARPPRINTOPERATORUNIT_H

#include "printoperatorunit.h"

class CSharpPrintOperatorUnit : public PrintOperatorUnit {
public:
    explicit CSharpPrintOperatorUnit( const std::string& text ) : PrintOperatorUnit( text ) { }
    std::string compile( unsigned int level = 0 ) const override{
        return generateShift( level ) + "Console.WriteLine( \"" + m_text + "\" );\n";
    }
};

#endif // CSHARPPRINTOPERATORUNIT_H
