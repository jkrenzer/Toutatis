#ifndef PAGE__LOGIN_HPP
# define PAGE__LOGIN_HPP

#include <Wt/Dbo/Dbo>
#include <Wt/Auth/AuthWidget>
#include <Wt/Auth/PasswordService>
#include <Wt/WContainerWidget>

namespace toutatis
{
    namespace Page
    {    
        class Login :  public Wt::WContainerWidget
        {
        public:
            Login();
        };
    }
}

# endif
