#include <src/Model/Attribute.hpp>

std::string toutatis::Model::Attribute::name()
{
    return _name;
}

void toutatis::Model::Attribute::name(std::string _name)
{
    this->_name = _name;
}

dbo::ptr<toutatis::Model::Object>& toutatis::Model::Attribute::object()
{
    return this->_object;
}

template <class Type>
void toutatis::Model::AttributeAs<Type>::value(Type value)
{
    this->_value = value;
}


std::string toutatis::Model::Attribute::value()
{
    std::stringstream ss;
    ss << _valueString;
    return ss.str();
}


void toutatis::Model::Attribute::value(std::string value)
{
    std::stringstream ss;
    ss <<  value;
    ss >> this->_valueString;
}

template <class Type>
Type& toutatis::Model::AttributeAs<Type>::value()
{
    return this->_value;
}


template <class Action>
void toutatis::Model::Attribute::persist(Action& a)
{
    dbo::field(a,  _name, "name");
    dbo::field(a, _valueString, "value");
    dbo::belongsTo(a, _object, "object");
}
