#ifndef NODES_HPP
#define NODES_HPP

#include <vector>



typedef int IDnumber;

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
    //virtual void getStatusToReport()=0: struct Status

};

class Ramp : public ActiveElement
{

public:
    Ramp(IDnumber ID, int iterationsPerTask);
    void doNextIteration(int externalIterationCounter) override;
    IDnumber getID() { return _ID; }
    //structStatus getStatusToReport()
};


class Worker : public ActiveElement, ProductReceiver
{
    enum qType{LIFO, FIFO};
    qType _queueType;
    std::vector<Product> _productsQueue ;

  public:
    Worker(int, int) ;//ID, IterationPerTask
    void doNextIteration(int externalIterationCounter) override;
    void addProductToQueue(Product product) override;
    IDnumber getID() {return _ID;}
    //struct Status getStatusToReport() ;

};

class Store : public Nodes, ProductReceiver
{
    std::vector<Product> _products;

public:
    Store(IDnumber ID);
    //Status getStatusToReport();
    IDnumber getID() { return _ID; }
    void addProductToQueue(Product product) override;
};


#endif // NODES_HPP
