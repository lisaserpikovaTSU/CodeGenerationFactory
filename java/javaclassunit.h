#ifndef JAVACLASSUNIT_H
#define JAVACLASSUNIT_H

#include "classunit.h"

class JavaClassUnit : public ClassUnit
{
public:
    enum class ClassModifier : unsigned int {
        NONE = 0,
        PUBLIC = 1,
        FINAL = 1 << 1,
        ABSTRACT = 1<< 2
    };

    enum AccessModifier{
        PUBLIC,
        PROTECTED,
        PRIVATE,
        PACKAGE_PRIVATE
    };

    static const std::vector< std::string > ACCESS_MODIFIERS;

    explicit JavaClassUnit( const std::string& name, ClassModifier modifier = ClassModifier::NONE ) : ClassUnit( name ), m_modifier(modifier) {
        m_fields.resize( ACCESS_MODIFIERS.size() );
    }

    void add( const std::shared_ptr< Unit >& unit, Flags flags) override {
        int accessModifier = PACKAGE_PRIVATE;
        if( flags < ACCESS_MODIFIERS.size() ) {
            accessModifier = flags;
        }
        m_fields[ accessModifier ].push_back( unit );
    }

    std::string compile( unsigned int level = 0 ) const override
    {
        std::string classModifier = "";
        if (static_cast<unsigned int>(m_modifier) & static_cast<unsigned int>(ClassModifier::PUBLIC)){
            classModifier += "public ";
        }
        if (static_cast<unsigned int>(m_modifier) & static_cast<unsigned int>(ClassModifier::FINAL)){
            classModifier += "final ";
        }
        else if (static_cast<unsigned int>(m_modifier) & static_cast<unsigned int>(ClassModifier::ABSTRACT)){
            classModifier += "abstract ";
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
const std::vector< std::string > JavaClassUnit::ACCESS_MODIFIERS = { "public",
                                                                  "protected", "private", "" };

#endif // JAVACLASSUNIT_H
