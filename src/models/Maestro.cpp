#include "Maestro.h"
#include <cstdlib>
#include <iostream>
#include <random>

Maestro::Maestro()
{
    numberOfPieces = 0;
    tabPiece = (Piece**)malloc(sizeof(Piece*)*numberOfPieces);
}

Maestro::Maestro(int _numberOfPieces)
{
    numberOfPieces = _numberOfPieces;
    tabPiece = (Piece**)malloc(sizeof(Piece*)*numberOfPieces);
    
    for(int i=0;i<numberOfPieces;++i)
    {
		cout << "Iterate Piece " << i << endl;
		tabPiece[i] = new Piece();
	}
}

Maestro::Maestro(Piece** _tabPiece, int _numberOfPieces)
{
    tabPiece = (Piece**)malloc(sizeof(int)*_numberOfPieces);
    for(int i=0;i<_numberOfPieces;++i)
    {
        tabPiece[i] = _tabPiece[i];
    }
    numberOfPieces = _numberOfPieces;

}

Piece* Maestro::process()
{
	int i, bestMark;
	cout << "Init\n";
	while(numberOfPieces > 2)
	{
		cout << "iterate " << numberOfPieces << endl;
		bestMark = 0;
		for(i=0;i<numberOfPieces;++i)
		{
			cout << "test1\n";
			tabPiece[i]->grade();
			cout << "test2\n";
			if(bestMark < tabPiece[i]->getMark())
			{
				bestMark = tabPiece[i]->getMark();
			}
		}
		
		biasedWheel(bestMark);
		cout << "end iterate\n";
	}
	
	return tabPiece[0];
}

void Maestro::biasedWheel(int _bestMark)
{
	std::random_device rd;
    int i=0;
    int j=0;
    Piece** tabTemp = (Piece**)malloc(sizeof(Piece*)*numberOfPieces/2);
    
    while(j<floor(numberOfPieces/2))
    {
        i = rd() % (numberOfPieces);
        if(_bestMark==0 || (rd()%_bestMark) < tabPiece[i]->getMark())
        {
            tabTemp[j] = tabPiece[i];
            tabPiece[i]->setMark(0);
            ++j;
        }
    }

    numberOfPieces = numberOfPieces/2;

	tabPiece = (Piece**)realloc(tabPiece,sizeof(Piece*)*numberOfPieces);
    for(i=0;i<numberOfPieces;++i)
    {
        tabPiece[i] = tabTemp[i];
    }

}

void Maestro::addPiece(Piece* _piece)
{
    tabPiece = (Piece**)realloc(tabPiece, sizeof(Piece*)*(numberOfPieces+1));
    tabPiece[numberOfPieces] = _piece;
}

Piece* Maestro::getPiece(int i)
{
    return tabPiece[i];
}

void Maestro::setPiece(int i, Piece* _piece)
{
    tabPiece[i] = _piece;
}

void Maestro::setNumberOfPieces(int i)
{
    numberOfPieces = i;
}

int Maestro::getNumberOfPieces()
{
    return numberOfPieces;
}
