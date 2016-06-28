#include <src/Model/Object.hpp>

template <class Action>
void toutatis::Model::Object::persist(Action& a)
{
    dbo::hasMany(a, _attributes,  dbo::ManyToOne,  "attributes");
    dbo::hasMany(a, _links,  dbo::ManyToOne,  "links");
    dbo::field(a, _uuid, "uuid");
}

dbo::collection<dbo::ptr<toutatis::Model::Attribute> > & toutatis::Model::Object::attributes()
{
    return this->_attributes;
}

dbo::collection<dbo::ptr<toutatis::Model::Link> > & toutatis::Model::Object::links()
{
    return this->_links;
}

toutatis::Model::Uuid& toutatis::Model::Object::uuid()
{
    return this->_uuid;
}
