#ifndef CORE_HPP
#define CORE_HPP

#include <Wt/WApplication>
#include <Wt/WContainerWidget>
#include <Wt/WServer>
#include <Wt/WBootstrapTheme>

# include <src/Page/Main.hpp>
#include <src/Model/Session.hpp>

namespace toutatis
{

    class MainApplication : public Wt::WApplication
    {
    public:
        MainApplication (const Wt::WEnvironment& env);

        void authEvent();
        
        Session& session();

    private:
        Session session_;
    };

    Wt::WApplication *createApplication(const Wt::WEnvironment& env);
    
    MainApplication* application();

}

#endif
