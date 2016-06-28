#ifndef MODEL__LINK_HPP
#define MODEL__LINK_HPP

# include <Wt/Dbo/ptr>
# include <Wt/Dbo/collection>

# include <src/Model/Object.hpp>

namespace dbo = Wt::Dbo;

namespace toutatis
{
    namespace Model
    {
        class Object;
        
        class Link
        {
        public:
            class Type
            {
            protected:
                std::string _name;
            public:
                
                Type();
                
                template <class Action>
                void persist(Action& a);
                
                virtual const std::string name() const;
                
                bool operator == (Type& other);
                
                operator std::string() const;
                
            };
            
            class Default
            {
            public:
                virtual const std::string name();
            };
            
            
            
        protected:
                dbo::ptr<Object> _object;
                dbo::ptr<Object> _otherObject;
                double _strength;
                dbo::ptr<Type> _type;
        public:
            
            template <class T>
            Link(dbo::ptr<Object>& object,  dbo::ptr<Object>& otherObject,  T& type = Default() );
            
            template <class Action>
            void persist(Action& a);
            
            bool operator == (Link& other);
            
            bool linking(dbo::ptr<Object>& object);
            
            dbo::ptr<Object> partnerOf(dbo::ptr<Object>& object);
            
            bool dangle();
            
            dbo::ptr<Type>& type();
            
        };
    }
}

# endif
