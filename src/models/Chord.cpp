#include "Chord.h"
#include <cstdlib>

Chord::Chord()
{
	int max = rand()%(NOTE_MAX-NOTE_MIN)+NOTE_MIN;

	for(numberOfNotes=0;numberOfNotes<max;++numberOfNotes)
	{
		notes[numberOfNotes] = new Note();
	}
}

void Chord::setNumberOfNotes(int _numberOfNotes)
{
	numberOfNotes = _numberOfNotes;
}

int Chord::getNumberOfNotes()
{
	return numberOfNotes;
}

Note* Chord::getNote(int _i)
{
	return notes[_i];
}

int Chord::getMark()
{
	return mark;
}

void Chord::setMark(int _mark)
{
	mark = _mark;
}