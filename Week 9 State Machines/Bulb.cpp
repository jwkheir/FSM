#include "stdafx.h"
#include "Bulb.h"


Bulb::Bulb(){
	voltage = 240;
	fsm = new FSM();
	fsm->AddState(new State(On, &Bulb::OnOn, this));
	fsm->AddState(new State(Off, &Bulb::OnOff, this));
	fsm->AddState(new State(Broken, &Bulb::OnBroken, this));

	fsm->AddTransition(On, Off, &Bulb::GuardOnToOff, this);
	fsm->AddTransition(On, Broken, &Bulb::GuardOnToBroken, this);
	fsm->AddTransition(Off, Broken, &Bulb::GuardOffToBroken, this);
	fsm->AddTransition(Off, On, &Bulb::GuardOffToOn, this);
}

void Bulb::OnOn(){
	cout << "OnOn" << endl;
}

void Bulb::OnOff(){
	cout << "OnOff" << endl;
}

void Bulb::OnBroken(){
	cout << "OnBroken" << endl;
}

bool Bulb::GuardOnToOff(){
	return voltage == 0;
}

bool Bulb::GuardOnToBroken(){
	return voltage > 300;
}

bool Bulb::GuardOffToBroken(){
	return voltage > 300;
}

bool Bulb::GuardOffToOn(){
	return voltage == 240;
}

void Bulb::Update(){
	fsm->Check();
}


Bulb::~Bulb()
{
}
