#ifndef CSHARPMETHODUNIT_H
#define CSHARPMETHODUNIT_H

#include "methodunit.h"

class CSharpMethodUnit : public MethodUnit {
public:
    enum Modifier {
        STATIC = 1,
        VIRTUAL = 1 << 1
    };
public:
    CSharpMethodUnit( const std::string& name, const std::string& returnType, Flags flags = 0)
        :MethodUnit( name, returnType, flags ){ }
    void add( const std::shared_ptr< Unit >& unit, Flags /* flags */ = 0 ) override {
        m_body.push_back( unit );
    }
    std::string compile( unsigned int level = 0 ) const override{
        std::string result = generateShift( level );
        if( m_flags & STATIC ) {
            result += "static ";
        } else if( m_flags & VIRTUAL ) {
            result += "virtual ";
        }
        result += m_returnType + " ";
        result += m_name + "()";
        result += " {\n";
        for( const auto& b : m_body ) {
            result += b->compile( level + 1 );
        }
        result += generateShift( level ) + "}\n";
        return result;
    }
};

#endif // CSHARPMETHODUNIT_H
