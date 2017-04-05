#pragma once
class State;
class Transition
{
private:
	State* fromState;
	GP guardFunction;
	Bulb* guardLocation;
	State* toState;
public:
	Transition* next;
public:
	Transition(State* from, State* to, GP guardFunction, Bulb* guardLocation);
	State* GetToState();
	bool InvokeGuard();
	~Transition();
};

