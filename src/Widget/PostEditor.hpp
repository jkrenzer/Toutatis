#ifndef WIDGET__POST_EDITOR_HPP
#define WIDGET__POST_EDITOR_HPP

#include <Wt/WStackedWidget>
#include <src/Model/Paragraph>

namespace toutatis
{
    namespace Widget
    {
        class PostEditor : public Wt::WContainerWidget
        {
        public:
                       
            PostEditor();
            
            class ParagraphWidget :  public toutatis::Model::Paragraph, public Wt::WStackedWidget
            {
            public:
                ParagraphWidget();
            };
        };
    }
}

#endif
