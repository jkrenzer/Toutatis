#ifndef USER_HPP
#define USER_HPP

#include <Wt/Dbo/Dbo>
#include <Wt/WGlobal>
#include <string>

namespace toutatis
{
namespace dbo = Wt::Dbo;

class User;
class Group;

/**
* @brief ...
*
*/
class Profile
{

private:
  dbo::collection< dbo::ptr<Group> > _groups;
  std::string _name;

public:
  dbo::collection< dbo::ptr<Group> > groups()
  {
    return this->_groups;
  }
  std::string name()
  {
    return this->_name;
  }
  template<class Action>
  void persist ( Action& a )
  {
    dbo::field ( a, _name,     "name" );
    dbo::hasMany ( a, _groups, dbo::ManyToOne,    "groups" );
  }
};

class Group
{
private:
    dbo::collection< dbo::ptr<Profile> > _members;
    std::string _name;
public:
    dbo::collection< dbo::ptr<Profile> >& members()
    {
        return _members;
    }
    std::string name()
    {
        return this->_name;
    }
    template<class Action>
    void persist ( Action& a )
    {
        dbo::field( a, _name,     "name" );
        dbo::hasMany( a, _members, dbo::ManyToOne,    "members" );
    }
};

/**
* @brief Class-description of an user
*
*/
class User
{

private:
  dbo::collection< dbo::ptr<Profile> > _profiles;
  std::string _name;
  std::string _password;
public:
  dbo::collection< dbo::ptr<Profile> > profiles()
  {
    return this->_profiles;
  }
  std::string name()
  {
    return this->_name;
  }

  template<class Action>
  void persist ( Action& a )
  {
    dbo::field ( a, _name,     "name" );
    dbo::field ( a, _password, "password" );
    dbo::hasMany ( a, _profiles, dbo::ManyToOne,    "profiles" );
  }
};

    typedef Wt::Auth::Dbo::AuthInfo<User> AuthInfo;

}
#endif
