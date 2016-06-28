#ifndef MODEL__VERSION_HPP
#define MODEL__VERSION_HPP

#include <boost/date_time/posix_time/ptime.hpp>
#include <boost/date_time/microsec_time_clock.hpp>

#include <Wt/Dbo/ptr>
#include <Wt/Dbo/collection>

#include <src/Model/VersionedObject.hpp>

namespace toutatis
{
    namespace Model
    {
        class Version
        {
        public:
            typedef boost::posix_time::ptime TimeStamp; 
            typedef boost::uuids::uuid Uuid;
        protected:
            const Wt::Dbo::ptr<User> _creator
            Uuid _uuid;
            TimeStamp _timeStamp;
            Wt::Dbo::collection<VersionedObject> _objects;

        public:
            Version(Wt::Dbo::ptr<User> creator) : _uuid(boost::uuids::random_generator()()),  _timeStamp(boost::date_time::microsec_clock::local_time()),  _creator(creator)
            {
            }
            
            template<class Action>
            void persist(Action& a)
            {
                Wt::Dbo::hasMany(a, objects, Wt::Dbo::ManyToOne, "objects");
                Wt::Dbo::belongsTo(a, _creator, "creator");
                Wt::Dbo::field(a, _uuid, "uuid");
                Wt::Dbo::field(a, _timeStamp, "timeStamp");
            }
            
            const Uuid& uuid() const
            {
                return _uuid;
            }
            
            const TimeStamp& timeStamp()
            {
                return _timeStamp;
            }
            
            const Wt::Dbo::ptr<User>& creator()
            {
                return _creator;
            }
            
            
        };
        
    }
}

#endif
