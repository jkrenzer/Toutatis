#include <src/Model/Link.hpp>

toutatis::Model::Link::Type::Type()
{
    this->_name = this->name();
}

template <class Action>
void toutatis::Model::Link::Type::persist(Action& a)
{
    dbo::id(a, _name, "name", 128);
}

const std::string toutatis::Model::Link::Type::name() const
{
    return std::string("default");
}

bool toutatis::Model::Link::Type::operator == (Type& other)
{
    return this->name() == other.name();
}

toutatis::Model::Link::Type::operator std::string() const
{
    return this->name();
}

// 128

const std::string toutatis::Model::Link::Default::name()
{
    return std::string("default");
}

// 

template <class T>
toutatis::Model::Link::Link(dbo::ptr<Object>& object,  dbo::ptr<Object>& otherObject,  T& type) : _object(object),  _otherObject(otherObject)
{
    if (object = otherObject)
    this->_otherObject = dbo::ptr<Object>();                  // We do not want loops
    _type = static_cast<Type>(type).name();
}

template <class Action>
void toutatis::Model::Link::persist(Action& a)
{
    dbo::field(a, _strength,  "strength");
    dbo::field(a, _type, "type");
    dbo::belongsTo(a, _object, "object");
    dbo::belongsTo(a, _otherObject, "otherObject");
    dbo::belongsTo(a, _type, "type");
}

bool toutatis::Model::Link::operator == (Link& other)
{
    return (this->_object ==  other._object) && (this->_otherObject ==  other._otherObject) && (this->_type == other._type);
}

bool toutatis::Model::Link::linking(dbo::ptr<toutatis::Model::Object>& object)
{
    return (object == this->_object) || (object == _otherObject);
}

dbo::ptr<toutatis::Model::Object> toutatis::Model::Link::partnerOf(dbo::ptr<toutatis::Model::Object>& object)
{
    if (linking(object))
    {
        return (object ==  this->_object)  ?  this->_otherObject : this->_object;
    }
    else
    return dbo::ptr<toutatis::Model::Object>();
}

bool toutatis::Model::Link::dangle()
{
    return !(this->_object && this->_otherObject) ;
}

dbo::ptr<toutatis::Model::Link::Type>& toutatis::Model::Link::type()
{
    return this->_type;
}
