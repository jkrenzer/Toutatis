#ifndef MODEL__PARAGRAPH_HPP
#define MODEL__PARAGRAPH_HPP

#include "Wt/WString"
#include "Wt/Dbo/Dbo"

# include <src/Model/SubParagraph.hpp>

namespace toutatis
{
    namespace Model
    {
        class Section
        {
        protected:
            Wt::WString _title;
            int _orderNumber;
            Wt::Dbo::collection<Paragraph> _paragraphs;
            Wt::Dbo::collection<Section> _subSections;
            Wt::Dbo::ptr<Section>   _parentSection;
        public:
            
            template <class Action>
            void persist(Action& a)
            {
                Wt::Dbo::field(a, _title, "title");
                Wt::Dbo::field(a, _orderNumber, "orderNumber");
                Wt::Dbo::hasMany(a, _paragraphs,  Wt::Dbo::ManyToOne, "paragraphs");
                Wt::Dbo::hasMany(a, _subSections,  Wt::Dbo::ManyToOne, "subsections");
                Wt::Dbo::belongsTo(a, _parentSection, "parent");
            }
            
            Wt::Dbo::collection<Paragraph>& paragraphs()
            {
                return _paragraphs;
            }
            
            Wt::Dbo::collection<Section>& subSections()
            {
                return _subSections;
            }
            
            Wt::Dbo::ptr<Section>& parent()
            {
                return _parentSection;
            }
            
            int& orderinNumber()
            {
                return _orderNumber;
            }
            
            Wt::WString title()
            {
                return _title;
            }
            
        };
    }
}

#endif
