#include <src/Page/Login.hpp>
#include <src/Model/User.hpp>
#include <src/Model/Session.hpp>
#include <src/Core.hpp>

namespace toutatis
{
    namespace Page
    {

        Login::Login()
        {
            Wt::Auth::AuthWidget* authWidget = new Wt::Auth::AuthWidget(Session::auth(), toutatis::application()->session().users(), application()->session().login());

            authWidget->model()->addPasswordAuth(&Session::passwordAuth());
        //             authWidget->model()->addOAuth(Session::oAuth());
            authWidget->setRegistrationEnabled(true);

            authWidget->processEnvironment();

            this->addWidget(authWidget);
        }
    }
}
