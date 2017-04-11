#include <LiquidCrystal.h>

int mSensor1 = A0;
int mSensor2 = A1;
int tempSensor1 = A2;
int tempSensor2 = A3;
int pump = 2;
int speaker = 4; 

bool InputsReceived = false 

void setup()
{
	pinMode(mSensor1,INPUT);
	pinMode(mSensor2,INPUT);
	pinMode(tempSensor1,INPUT);
	pinMode(tempSensor2,INPUT);
	pinMode(pump,OUTPUT);
	pinMode(speaker,OUTPUT); //can use python pystsx to give audio output

}

void loop()
{
	if (InputsReceived == false)
	{
		;		
	}

	if (InputsReceived == true)
	{
		InputsReceived = false 




	}

}

int runTime(int crop,int cropStage)
{
	/*
	------------------------------------------------------------
	1 = rice 
	2 = wheat 
	3 = maize 
	4 = cotton 
	5 = beans	
	*/	
	int k=0; 
	int t=0;
	int p = 0.40

	if (crop == 1); 
	{
		if (cropStage == 1);
		{
			k = 1.05;        		 	
		}

		if (cropStage == 2);
		{
			k = 1.20;
		}

		if (cropStage == 3);
		{
			k = 0.7;
		}

	int ETo = p*(0.46*temp() + 8) ; 
	ETc = ETo*k
	moisture_in_mm = (1.8*moisture)/329 ;
	
	int t = (ETc - (field_capacity - moisture_in_mm))*scale;
	return t
	
	}
}

int temp()
{
	t1 = analogRead(tempSensor1);
	t2 = analogRead(tempSensor2);

	t = (t1 + t2)/2

	return t
}

int moisture()
{
	val1 = analogRead(mSensor1)
	val2 = analogRead(mSensor2)

}