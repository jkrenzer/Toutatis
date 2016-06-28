#include <src/Widget/PostEditor.hpp>
#include <Wt/Utils>
#include <Wt/WContainerWidget>
#include <Wt/WFormWidget>
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WTextEdit>
#include <Wt/WValidator>
#include <Wt/WLengthValidator>
#include <Wt/WButtonGroup>
#include <Wt/WRadioButton>
#include <Wt/WComboBox>
#include <Wt/WStringListModel>
#include <Wt/WStackedWidget>
#include <Wt/WGroupBox>

toutatis::Widget::PostEditor::ParagraphWidget::ParagraphWidget() : Wt::WContainerWidget(),  edit(new Wt::WTextEdit(this))
{
    edit->setHeight(300);
}

toutatis::Widget::PostEditor::PostEditor() : Wt::WContainerWidget()
{
//     Wt::WContainerWidget * containerWidget = new Wt::WContainerWidget(this);
//     Wt::WGroupBox *groupBox = new Wt::WGroupBox(Wt::WString("1. Choose Topic"),  containerWidget);
//     Wt::WText *text = new Wt::WText(Wt::WString("This paragraph is..."),  groupBox);
//     Wt::WButtonGroup *group = new Wt::WButtonGroup(groupBox);
//     Wt::WRadioButton *radioButton;
//     Wt::WStackedWidget *stackedWidget;
//     // Find out if we are on or off topic
//     
//     radioButton = new Wt::WRadioButton(Wt::WString("Off topic"), groupBox);
//     group->addButton(radioButton);
//     radioButton = new Wt::WRadioButton("On topic", groupBox);
//     group->addButton(radioButton);
//     stackedWidget = new Wt::WStackedWidget(groupBox);
//     
//     // Warning for off-topic-paragraphs
//     containerWidget = new Wt::WContainerWidget(stackedWidget);
//     text = new Wt::WText(Wt::WString("Please note: Off-Topic-Paragraphs may be deleted or hidden when this thread is archived or purged."), containerWidget);
//     text->setStyleClass("bg-info");
//     // Asking if old or new topic
//     containerWidget = new Wt::WContainerWidget(stackedWidget);
// 
//     text = new Wt::WText(Wt::WString("To which topic will you write?"),  containerWidget);
//     Wt::WComboBox *cb = new Wt::WComboBox(containerWidget);
//     cb->setMargin(10, Wt::Right);
// 
//     Wt::WStringListModel *model = new Wt::WStringListModel(cb);
// 
//     model->addString("Belgium");
//     model->setData(0, 0, std::string("BE"), Wt::UserRole);
//     model->addString("Netherlands");
//     model->setData(1, 0, std::string("NL"), Wt::UserRole);
//     model->addString("United Kingdom");
//     model->setData(2, 0, std::string("UK"), Wt::UserRole);
//     model->addString("United States");
//     model->setData(3, 0, std::string("US"), Wt::UserRole);
//     model->setFlags(3, 0);
// 
//     cb->setNoSelectionEnabled(true);
//     cb->setModel(model);
//     
// 
//     group->setSelectedButtonIndex(0); // Select the first button by default.
//     
//     group->checkedChanged().connect(std::bind([=] () {
//             stackedWidget->setCurrentIndex(group->checkedId());
//     }));
//     containerWidget = new Wt::WContainerWidget(this);
//     groupBox = new Wt::WGroupBox(Wt::WString("2. Write a Paragraph"),  containerWidget);
    
    ParagraphWidget* paragraph
    
    Wt::WLengthValidator * validator = new Wt::WLengthValidator();
    validator->setInvalidBlankText(Wt::WString("Please enter a message before proceeding!"));
    validator->setMandatory(true);
    edit->setValidator(validator);
    Wt::WPushButton *button = new Wt::WPushButton("Save and Quit", this);
    button->setStyleClass("btn btn-primary");
    button->setMargin(10, Wt::Top | Wt::Bottom);

    button->clicked().connect(std::bind([=] () {
        Wt::WValidator::Result result = validator->validate(edit->text());
        if (result.state() == Wt::WValidator::Valid)
        {
            out->setText("<pre>" + Wt::Utils::htmlEncode(edit->text()) + "</pre>");
        }
        else
        {
            edit->setFocus(true);
            out->setText(result.message());
            out->setStyleClass("alert alert-danger");
        }
            
    }));
    
    Wt::WPushButton *button = new Wt::WPushButton("Add Paragraph", this);
    button->setStyleClass("btn btn-primary");
    button->setMargin(10, Wt::Top | Wt::Bottom);

    button->clicked().connect(std::bind([=] () {
        Wt::WValidator::Result result = validator->validate(edit->text());
        if (result.state() == Wt::WValidator::Valid)
        {
            out->setText("<pre>" + Wt::Utils::htmlEncode(edit->text()) + "</pre>");
        }
        else
        {
            edit->setFocus(true);
            out->setText(result.message());
            out->setStyleClass("alert alert-danger");
        }
            
    }));
}
