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
    if(iterationNumber % _iterationsPerTask != 0)//Sprawdzanie, czy w danej iteracji ma zostaæ wykonana praca;
    {
        return;
    }

    //TU PRACA//
    /*
    -wylosowaæ adresata,
    -pobraæ produkt z kolejki ( LIFO/FIFO ),
    -wys³aæ produkt do adresata,
    -skasowaæ produkt z kolejki.
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
    if(iterationNumber % _iterationsPerTask != 0)//Sprawdzanie, czy w danej iteracji ma zostaæ wykonana praca;
    {
        return;
    }

    //TU PRACA//
    /*
    -wylosowaæ adresata,
    -stworzyæ produkt,
    -wys³aæ produkt do adresata,
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
