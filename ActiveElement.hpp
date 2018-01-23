#ifndef ACTIVEELEMENT_HPP
#define ACTIVEELEMENT_HPP

#include "nodes.hpp"

class ActiveElement : public Nodes
{

    protected:
    std::vector<Receiver> _receivers ;
    int _iterationsPerTask;//Co tyle iteracji bedzie wykonywana praca przez węzeł (wysłanie produktu );

    public:                              //( zwiększy iterationCnt o 1, porówna z IterationPerTask i zwróci 1 albo 0 ). Bez tej metody też by
    void addReceiver(ProductReceiver & prodReceiver);     //się obeszło, ale to chyba będzie ładniej wyglądało w kodzie :).
    void deleteReceiver(int Id);
    void normalizePreferences();
    void setPreferences();
    virtual void doNextIteration(int iterationNumber)=0;
    //virtual void getStatusToReport()=0: struct Status

};

#endif //ACTIVEELEMENT_HPP
