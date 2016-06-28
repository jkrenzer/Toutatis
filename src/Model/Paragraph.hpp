#ifndef MODEL__SUB_PARAGRAPH_HPP
#define MODEL__SUB_PARAGRAPH_HPP

# include <Wt/WString>
# include <Wt/Dbo/Dbo>

# include <src/Model/User.hpp>
# include <src/Model/Section.hpp>

namespace toutatis
{
    namespace Model
    {
        class Paragraph
        {
        protected:
            Wt::WString _text;
//             int _orderNumber;
            Wt::Dbo::collection<Section>   _parents;
            Wt::Dbo::collection<Section>   _parents;
        public:
            
            template <class Action>
            void persist(Action& a)
            {
                Wt::Dbo::field(a, _orderNumber, "orderNumber");
                Wt::Dbo::hasMany(a, _parents,  Wt::Dbo::ManyToMany,  "parent");
                Wt::Dbo::field(a, _text, "text");
            }
            
            Wt::WString& text()
            {
                return this->_text;
            }
            
            Wt::Dbo::collection<Section>& parents()
            {
                return _parents;
            }
            
            Wt::Dbo::ptr<Topic>&
            
//             int& orderinNumber()
//             {
//                 return _orderNumber;
//             }
        };
    }
}

#endif
