#include "nodes.hpp"


//WORKER---------------------------------------//
Worker::Worker(IDnumber ID, int iterationsPerTask)
    {
        _ID = ID;
        _iterationsPerTask = iterationsPerTask;
    }

void Worker::addProductToQueue(Product product)
{
    _productsQueue.push_back(product);
}

void Worker::doNextIteration(int iterationNumber)
{
    if(iterationNumber % _iterationsPerTask != 0)//Sprawdzanie, czy w danej iteracji ma zosta� wykonana praca;
    {
        return;
    }

    //TU PRACA//
    /*
    -wylosowa� adresata,
    -pobra� produkt z kolejki ( LIFO/FIFO ),
    -wys�a� produkt do adresata,
    -skasowa� produkt z kolejki.
    */

}


//---------------------------------------------//

//RAMP-----------------------------------------//

Ramp::Ramp(IDnumber ID, int iterationsPerProduct)
    {
        _ID = ID;
        _iterationsPerTask = iterationsPerProduct;
    }

void Ramp::doNextIteration(int iterationNumber)
{
    if(iterationNumber % _iterationsPerTask != 0)//Sprawdzanie, czy w danej iteracji ma zosta� wykonana praca;
    {
        return;
    }

    //TU PRACA//
    /*
    -wylosowa� adresata,
    -stworzy� produkt,
    -wys�a� produkt do adresata,
    */

}

//---------------------------------------------//

//STORE----------------------------------------//

Store::Store(IDnumber ID)
{
    _ID = ID;
}

void Store::addProductToQueue(Product product)
{
    _products.push_back(product);
}
//---------------------------------------------//
