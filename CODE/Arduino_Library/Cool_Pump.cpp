/*	LACOOL_CO's GENERAL LIBRARY
	TYPE : ACTUATOR	-	MODEL : JP - 180
	ROLE : Le Petit Cool Pump
	@author Maximilien Daman	15/11/2015
	Mail : max@lacool.co	Web : www.lacool.co
 */
 
//Inclusion des librairies
	#include "Arduino.h"
	#include "PetitCool.h"

///////////////////////////////////////////////////////////////////////////////
///////////////////////////////CONSTRUCTEURS///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////	
Cool_Pump::Cool_Pump()
{}

void Cool_Pump::begin(uint8_t ConnectPin)
{
	PumpPin = ConnectPin;
	pinMode(PumpPin, OUTPUT);
	setError(0);
	Mode = 1;
	TimerPhase = false;
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////////ERRORLEVEL///////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
uint8_t Cool_Pump::errorlevel()
{//	EN COURS//
//Initialisation:
	ErrorLevel = 0;
	/* pinMode(PumpPin, INPUT);
	if(digitalRead(PumpPin) == 0 ) ErrorLevel = 0;
	pinMode(PumpPin, OUTPUT); */
	return ErrorLevel;
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
//////////////////////////////FONCTIONS POMPE/////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
void Cool_Pump::setVal(uint8_t Power)
{
	if(ErrorLevel == 0)
	{
		IO = Power;
		digitalWrite(PumpPin, IO);
	}
	return;
}

void Cool_Pump::switchVal()
{
	if(ErrorLevel == 0)
	{
		TimerPhase = !TimerPhase;
		uint8_t  TempPow = TimerPhase?255:0;
		digitalWrite(PumpPin, TempPow);
	}
	else	TimerPhase = false;
	return;
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////