#ifndef METHODUNIT_H
#define METHODUNIT_H

#include "unit.h"

class MethodUnit : public Unit {
public:
    MethodUnit( const std::string& name, const std::string& returnType, Flags
                                                                           flags ) :
        m_name( name ), m_returnType( returnType ), m_flags( flags ) { }

    virtual void add( const std::shared_ptr< Unit >&, Flags) override = 0;
    virtual std::string compile( unsigned int level = 0 ) const override = 0;
protected:
    std::string m_name;
    std::string m_returnType;
    Flags m_flags;
    std::vector< std::shared_ptr< Unit > > m_body;
};

#endif // METHODUNIT_H
