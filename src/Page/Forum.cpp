#include <src/Page/Forum.hpp>
#include <Wt/WText>

#include <src/Widget/PostEditor.hpp>

namespace toutatis
{
    namespace Page
    {
        Forum::Forum()
        {
            this->addWidget(new toutatis::Widget::PostEditor());
        }
    }
}
