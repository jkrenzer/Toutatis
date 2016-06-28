#include <src/Menu/Main.hpp>
#include <Wt/WLineEdit>
#include <Wt/WMenu>

#include <Wt/WNavigationBar>
#include <Wt/WPopupMenu>
#include <Wt/WPopupMenuItem>
#include <Wt/WStackedWidget>
#include <Wt/WText>

# include <src/Page/Login.hpp>
# include <src/Page/Forum.hpp>
#include <src/Menu/Help.hpp>

namespace toutatis
{
    namespace Menu
    {
        Main::Main()
        {
            Wt::WNavigationBar * navigation = new Wt::WNavigationBar(this);
            navigation->setTitle("Toutatis");
            navigation->setResponsive(true);

            Wt::WStackedWidget *contentsStack = new Wt::WStackedWidget();
            contentsStack->addStyleClass("contents");

            // Setup a Left-aligned menu.
            Wt::WMenu *leftMenu = new Wt::WMenu(contentsStack);
            navigation->addMenu(leftMenu);

            Wt::WText *searchResult = new Wt::WText("Buy or Sell... Bye!");

            leftMenu->addItem("Forum", new Page::Forum);
            leftMenu->addItem("Login", new Page::Login);
    //         leftMenu->addItem("Layout", new Wt::WText("Layout contents"))
    //             ->setLink(Wt::WLink(Wt::WLink::InternalPath, "/layout"));
    //         leftMenu->addItem("Sales", searchResult);

            // Setup a Right-aligned menu.
            Wt::WMenu *rightMenu = new Wt::WMenu();
            navigation->addMenu(rightMenu, Wt::AlignRight);

            rightMenu->addItem(new Help());

            // Add a Search control.
            Wt::WLineEdit *edit = new Wt::WLineEdit();
            edit->setEmptyText("Enter a search item");

            edit->enterPressed().connect(std::bind([=] () {
                leftMenu->select(2); // is the index of the "Sales"
                searchResult->setText(Wt::WString("Nothing found for {1}.")
                                    .arg(edit->text()));
            }));

            navigation->addSearch(edit, Wt::AlignRight);

            this->addWidget(contentsStack);
            
        }
    }
}
