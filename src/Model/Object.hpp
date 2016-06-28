#ifndef MODEL__OBJECT_HPP
#define MODEL__OBJECT_HPP

#include <sstream>
#include <string>
#include <Wt/Dbo/Dbo>

# include <src/Model/Attribute.hpp>
# include <src/Model/Link.hpp>
# include <src/Model/Uuid.hpp>

namespace dbo = Wt::Dbo;

namespace toutatis
{
    namespace Model 
    {
        class Link;
        
        class Attribute;
         
        class Object
        {
            protected:
                dbo::collection< dbo::ptr<Attribute> > _attributes;
                dbo::collection< dbo::ptr<Link> > _links;
                Uuid _uuid;

            public:
                
                template <class Action> void persist(Action& a);
                
                dbo::collection< dbo::ptr<Link> >& links();
                
                dbo::collection< dbo::ptr<Attribute> >& attributes();
                
                Uuid& uuid();
            
        };
    }
}

#endif
