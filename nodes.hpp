#ifndef NODES_HPP
#define NODES_HPP

#include <vector>
#include <sstream>



typedef int IDnumber;

enum qType{LIFO, FIFO};

class Nodes
{
protected:
    IDnumber _ID;          // zmiana typu na typedef IDnumber

  public:
    //struct Status virtual getStatusToReport()=0 ;     // jak zwrócić strukturę ???
    virtual IDnumber getID()=0;

} ;

class Product
{
    IDnumber _ID;

public:
    Product( IDnumber ID );
    IDnumber getID() {return _ID;}
};


class ProductReceiver
{
    public:
    virtual void addProductToQueue(Product product)=0;
};

class Receiver
{
    ProductReceiver& _productReceiver  ;
    double _probability ;

  public:
    Receiver(ProductReceiver&, double);
    void setProbability(double) ;
    ProductReceiver& getReceiver()  {return _productReceiver;}
    double getProbability() {return _probability;}
};



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

};

class Ramp : public ActiveElement
{

public:
    Ramp(IDnumber ID, int iterationsPerTask);
    void doNextIteration(int externalIterationCounter) override;
    IDnumber getID() { return _ID; }

    friend void getStatusToReport(Ramp& ramp,std::stringstream reportStream);
};


class Worker : public ActiveElement, ProductReceiver
{
    qType _queueType;
    std::vector<Product> _productsQueue ;

  public:
    Worker(int, int) ;//ID, IterationPerTask
    void doNextIteration(int externalIterationCounter) override;
    void addProductToQueue(Product product) override;
    IDnumber getID() {return _ID;}

    friend void getStatusToReport(Worker& worker,std::stringstream reportStream);

};

class Store : public Nodes, ProductReceiver
{
    std::vector<Product> _products;

public:
    Store(IDnumber ID);
    IDnumber getID() { return _ID; }
    void addProductToQueue(Product product) override;

    friend void getStatusToReport(Store& store,std::stringstream reportStream);
};


#endif // NODES_HPP
