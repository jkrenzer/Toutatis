#ifndef MODEL__UUID_HPP
# define MODEL__UUID_HPP

# include <boost/uuid/uuid.hpp>
# include <boost/uuid/uuid_generators.hpp>

namespace toutatis
{
    namespace Model
    {
        typedef boost::uuids::uuid Uuid;
    }
}

# endif
