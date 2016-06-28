#include <src/Model/Object.hpp>
#include <boost/uuid/uuid_io.hpp>

namespace model = toutatis::Model;

int main()
{
    model::Object object;
    std::cout <<  object.uuid();
    return 0;
}
