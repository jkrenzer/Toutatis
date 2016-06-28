#include <src/Menu/Help.hpp>

#include <Wt/WPopupMenu>

namespace toutatis
{
    namespace Menu
    {
        Help::Help::Help() : Wt::WMenuItem("Help")
        {
            // Create a popup submenu for the Help menu.
        Wt::WPopupMenu *popup = new Wt::WPopupMenu();
        popup->addItem("Contents");
        popup->addItem("Index");
        popup->addSeparator();
        popup->addItem("About");

        popup->itemSelected().connect(std::bind([=] (Wt::WMenuItem *item) {
            Wt::WMessageBox *messageBox = new Wt::WMessageBox
                ("Help",
                Wt::WString::fromUTF8("<p>Showing Help: {1}</p>").arg(item->text()),
                Wt::Information, Wt::Ok);

            messageBox->buttonClicked().connect(std::bind([=] () {
                delete messageBox;
            }));

            messageBox->show();
        }, std::placeholders::_1));

        this->setMenu(popup);
        this->removeStyleClass("dropdown");
        }

    }
}
