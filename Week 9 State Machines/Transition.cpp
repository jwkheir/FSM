#include "stdafx.h"
#include "Transition.h"


Transition::Transition(State * from, State * to, GP guardFunction, Bulb *guardLocation){
	this->fromState = from;
	this->toState = to;
	this->guardFunction = guardFunction;
	this->guardLocation = guardLocation;
}

bool Transition::InvokeGuard(){
	if (guardFunction != 0 && guardLocation != 0){
		return (guardLocation->*guardFunction)();
	}
	return false;
}

State* Transition::GetToState(){
	return toState;
}


Transition::~Transition()
{
}
