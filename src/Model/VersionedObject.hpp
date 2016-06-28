#ifndef MODEL__VERSIONED_OBJECT_HPP
#define MODEL__VERSIONED_OBJECT_HPP

#include <Wt/Dbo/ptr>
#include <Wt/Dbo/collection>

#include <src/Version.hpp>

namespace toutatis
{
    namespace Model
    {
        
        class VersionedObject
        {
        protected:
            Wt::Dbo::ptr<Version> _version
        public:
            
            VersionedObject(Wt::Dbo::ptr<Version> = Wt::Dbo::ptr<Version>(new Version(application()->session()->user())))
            {
            }
            
            template <class Action>
            void persist(Action& a)
            {
                Wt::Dbo::belongsTo(a, _version, "version");
            }
            
            Wt::Dbo::ptr<Version>& version()
            {
                return _version;
            }
            
            
            
            
        };
        
        template <class Object>
        class Versioned :  public VersionedObject,  public Object
        {
        };
    }
}

#endif
