# ifndef MODEL__ATTRIBUTE_HPP
# define MODEL__ATTRIBUTE_HPP

#include <Wt/Dbo/ptr>

#include <src/Model/Object.hpp>

namespace dbo = Wt::Dbo;

namespace toutatis
{
    namespace Model
    {
        class Object;
        
        class Attribute
        {
        protected:
            std::string _name;
            dbo::ptr<Object> _object;
            std::string _valueString;

        public:
            std::string name();
            
            void name(std::string _name);
            
            dbo::ptr<Object>& object();
            
            virtual void value(std::string);
            
            virtual std::string value();
            
            template <class Action>
            void persist(Action& a);

        };
        
        template <class Type>
        class AttributeAs :  public Attribute
        {
        protected:
            Type _value;
        public:
            
            Type& value();
            
            void value(Type _value);
 
        };
    }
}

# endif
