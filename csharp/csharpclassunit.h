#ifndef CSHARPCLASSUNIT_H
#define CSHARPCLASSUNIT_H

#include "classunit.h"

class CSharpClassUnit : public ClassUnit
{
public:
    enum class ClassModifier {
        INTERNAL,
        PUBLIC,
        FILE
    };

    enum AccessModifier{
        PUBLIC,
        PROTECTED,
        PRIVATE,
        PRIVATE_PROTECTED,
        INTERNAL,
        PROTECTED_INTERNAL
    };

    static const std::vector< std::string > ACCESS_MODIFIERS;

    explicit CSharpClassUnit( const std::string& name, ClassModifier modifier ) : ClassUnit( name ), m_modifier(modifier) {
        m_fields.resize( ACCESS_MODIFIERS.size() );
    }

    void add( const std::shared_ptr< Unit >& unit, Flags flags) override {
        int accessModifier = PRIVATE;
        if( flags < ACCESS_MODIFIERS.size() ) {
            accessModifier = flags;
        }
        m_fields[ accessModifier ].push_back( unit );
    }

    std::string compile( unsigned int level = 0 ) const override
    {
        std::string classModifier;
        switch (m_modifier) {
        case ClassModifier::INTERNAL:
            classModifier = "internal ";
            break;
        case ClassModifier::PUBLIC:
            classModifier = "public ";
            break;
        case ClassModifier::FILE:
            classModifier = "file ";
            break;
        }

        std::string result = generateShift( level ) + classModifier + "class " + m_name + "\n{\n";
        for( size_t i = 0; i < m_fields.size(); ++i ) {
            if( m_fields[ i ].empty() ) {
                continue;
            }
            for( const auto& f : m_fields[ i ] ) {
                result += generateShift( level + 1)
                + ACCESS_MODIFIERS[ i ]
                    + f->compile( level + 1 );
            }
            result += "\n";
        }
        result += generateShift( level ) + "}\n";
        return result;
    }
private:
    ClassModifier m_modifier;

};
const std::vector< std::string > CSharpClassUnit::ACCESS_MODIFIERS = { "public",
                                                                    "protected", "private", "private protected",
                                                                    "internal", "protected internal"};

#endif // CSHARPCLASSUNIT_H
