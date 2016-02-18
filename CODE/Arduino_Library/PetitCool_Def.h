/*	LACOOL_CO's GENERAL LIBRARY
	TYPE : DEFINITION	-	MODEL : Le Petit Cool
	ROLE : Le Petit Cool General Definitions
	@author Maximilien Daman	16/02/2016
	Mail : max@lacool.co	Web : www.lacool.co
 */
 
#ifndef PetitCool_Def_h
#define PetitCool_Def_h
//Definitions Capteurs
	#define SENSOR_TYPE 10
	#define TIMERS_TYPE 5
	#define MODES_TYPE 	8
	#define NB_CONS		12
	//DHT
	#define DHTMaxFreq	2000
	//SD
	/*	//	Specifications:
		//		Slave Select = Connect Slave	<=> SS = CS
		//		Slave Out = Device Out		<=>	MISO = DO
		//		Slave In = Device In			<=>	MOSI = DI
		//		Clk
	*/
	#define CS_Pin		53		//	SS
	#define MISO_Pin 	50		//	MISO
	#define MOSI_Pin 	51		//	MOSI
	#define CLK_Pin		52		//	CLK
	//BlueTooth
	/*	// Materiel BlueTooth:
		// 		- Grove Bluetooth Low Energy 3.0 : 
		//			-> STMode
		//			-> BTBaudRate = 38400
		//		- HC-06:
		//			-> ATMode
		//			-> BTBaudRate = 9600
	*/
	/*	Uncomment these lines if using HC-06:	*/
		// #define	_ATMode
		// #define BTBaudRate	9600
		// #define ATBaudRate	4
	/*	*/
	/*	Uncomment these lines if Using Grove BLE 3.0: */
		#define _STMode
		#define BTBaudRate	38400
		#define ATBaudRate	6
	/*	*/
	#define BTCodeLength	4
	//Camera
		//#define	CoolCam 	softwareSerial(A8, A9)
		//#define CCBaudRate	115200
	//RTC
	#define CLOCK_ADDRESS 0x68
	#ifdef __AVR__
		#include <avr/pgmspace.h>
		#define WIRE Wire
	#else
		#define pgm_read_byte(addr) (*(const unsigned char *)(addr))
		#define WIRE Wire1
	#endif
	//4 Digits Display
	#define COMM1	0x40
	#define COMM2	0x44
	#define START	0xc0
	#define CMDDS	0x88
	#define DisplaySpeed	150
	#define DataDisplayTime 1750
	#define DisplayTimerOff	5000
	#define PushPicture		500
	#define PushDispInfo	20
	#define PushDispPic		100
	//LedBar
	#define CMDMODE     0x0000
	#define ON          0x00ff
	#define SHUT        0x0000
//Communication
	#define SEND_MAX_LENGTH 48
	#define SD_MAX_SEND		256
//Templates
	#include "Arduino.h"
	#include <SoftwareSerial.h>
	template<class T> void CoolPrint(const T Data, SoftwareSerial& BlueTooth)
	{
		Serial.print(Data);
		if(!BlueTooth.available()) BlueTooth.print(Data);
		return;
	}
	
	template<class T> void CoolPrintln(const T Data, SoftwareSerial& BlueTooth)
	{
		Serial.println(Data);
		if(!BlueTooth.available()) BlueTooth.println(Data);
		return;
	}
	
	template<class T>	void CoolFlush(T& BlueTooth)
	{
		Serial.flush();
		if(!BlueTooth.available()) BlueTooth.flush();
		return;
	}
#endif