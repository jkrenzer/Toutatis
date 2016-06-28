#ifndef PAGE__MAIN_HPP
#define PAGE__MAIN_HPP
#include <Wt/WContainerWidget>

#include <src/Menu/Main.hpp>

namespace toutatis
{
    namespace Page
    {
        class Main :  public Wt::WContainerWidget
        {
        public:
            Main()
            {
                this->addWidget(new toutatis::Menu::Main);
            }
        };
    }
}


#endif
