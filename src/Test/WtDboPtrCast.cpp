#include <Wt/Dbo/Dbo>
#include <Wt/Dbo/backend/Sqlite3>
#include <string>

namespace dbo = Wt::Dbo;

class A
{
public:
    
    std::string albert;
    
    template <class Action>
    void persist(Action& a)
    {
        dbo::field(a,  albert,  "albert");
    }
};

class B
{
public:
    
    int berta;
    
    template <class Action>
    void persist(Action& a)
    {
        dbo::field(a,  berta,  "berta");
    }
};

class AB :  public A,  public B
{
public:
    template <class Action>
    void persist(Action& a)
    {
        A::persist(a);
        B::persist(a);
    }
};

int main()
{
    dbo::backend::Sqlite3 sqlite3(":memory:");
    sqlite3.setProperty("show-queries", "true");
    dbo::Session session;
    session.setConnection(sqlite3);

    session.mapClass<A>("A");
    session.mapClass<B>("B");
    session.mapClass<AB>("AB");
    
    bool tablesExisted = false;

    try 
    {
        session.createTables();
    }
    catch (...)
    {
        tablesExisted = true;
    }
    
    std::cout << "Tables" << (  tablesExisted  ?  "existed" : "did not exist and where created." ) << std::endl;
    
    A* a = new A;
    a->albert = std::string("a");
    B* b = new B;
    b->berta = 6;
    AB* ab = new AB;
    ab->albert = "ab";
    ab->berta = 42;
    {
        dbo::Transaction transaction(session);
        
        session.add(a);
        session.add(b);
        session.add(ab);
        
        transaction.commit();
        
    }
    
    std::cout << "Added all classes to session" <<  std::endl;
    dbo::ptr<A> ab_a;
    
    {
        dbo::Transaction transaction(session);
        ab_a = session.find<A>().where("albert = ?").bind("ab");
    }
    
    std::cout << "ab als A gefunden? " <<  ( ab_a  ? "Ja!" : "Nein") << std::endl;
    
    return 0;
    
}
