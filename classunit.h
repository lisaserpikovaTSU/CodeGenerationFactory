#ifndef CLASSUNIT_H
#define CLASSUNIT_H

#include "unit.h"

class ClassUnit : public Unit
{
public:
    explicit ClassUnit( const std::string& name ) : m_name( name ) {}
    virtual ~ClassUnit() = default;

    virtual void add( const std::shared_ptr< Unit >&, Flags) override = 0;
    virtual std::string compile( unsigned int level = 0 ) const override = 0;
protected:
    std::string m_name;
    using Fields = std::vector< std::shared_ptr< Unit > >;
    std::vector< Fields > m_fields;
};

#endif // CLASSUNIT_H
