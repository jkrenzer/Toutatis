#include <src/Core.hpp>

namespace toutatis
{
    MainApplication::MainApplication (const Wt::WEnvironment& env)
            : Wt::WApplication(env),
            session_(appRoot() + "auth.db")
        {
            session_.login().changed().connect(this, &MainApplication::authEvent);

            root()->addStyleClass("container");
            Wt::WBootstrapTheme* theme = new Wt::WBootstrapTheme();
            theme->setVersion(Wt::WBootstrapTheme::Version3);
            setTheme(theme);

            useStyleSheet("./Wt/resources/style.css");
            root()->addWidget(new Page::Main());

        }
        
        void MainApplication::authEvent() {
            if (session_.login().loggedIn()) {
            const Wt::Auth::User& u = session_.login().user();
            Wt::log("notice")
                << "User " << u.id()
                << " (" << u.identity(Wt::Auth::Identity::LoginName) << ")"
                << " logged in.";
            } else
            Wt::log("notice") << "User logged out.";
        }
        
        Session& MainApplication::session()
        {
            return this->session_;
        }
        
        Wt::WApplication *createApplication(const Wt::WEnvironment& env)
    {
    return new MainApplication (env);
    }
    
    MainApplication* application()
    {
        return static_cast<MainApplication*>(Wt::WApplication::instance());
    }
}
