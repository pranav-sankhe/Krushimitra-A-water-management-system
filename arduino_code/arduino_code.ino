#include <LiquidCrystal.h>
/*                                                  LCD circuit 
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
* LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 8
 * LCD D5 pin to digital pin 7
 * LCD D6 pin to digital pin 6
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/

//LiquidCrystal lcd(12, 11, 8, 7, 6, 2);

int moisture_sensor1 = A0;
int moisture_sensor2 = A1;
int enable1 = 10;
int enable2 = 11;
int temperature_sensor1 = A2;
int temperature_sensor2 = A3;
int temperature_sensor3 = A4;
int temperature_sensor4 = A5;
int pump = 3;
int speaker = 4;
int warning_noted = 5;

int growth_stage = 0; 
double soil_infiltration = 25.4;   //per hour
double wilting_point = 4.9;
double field_capacity = 1.53;

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
                0 = germination
                1 = flowering stage
                2 = fruit stage
 ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/

/*                                                calibaration parameters
------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
double area_plot = 2213.75;
double delay_1_litre = 0;
double calibrated_value = 0;
*/

double moisture_val = 0;
double temperature = 0 ;
double scale = 1000;
int moisture_in_mm = 0;
/*                                                                                  crop values
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//these are the average values over whole growing period. need to consider water requirement at each growth step  
double rice_water = 4.79; 
double bean_water = 4.84;
double pea_water = 4.47;
double cotton_water = 5.86;
double maize_water = 4.26;
double sugarcane_water = 6.29;
double tomato_water = 3.80;
double banana_water = 5.11;
/*                                              water requirement: 
   -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
    Rice (paddy) :450-700 mm/growing period     90-150 days   
    Bean         :300-500 mm/growing period     75-90 days 
    Pea          :350-500 mm/growing period     90-100 days 
    Cotton       :700-1300 mm/growing period    180-195 days 
    Maize        :500-800 mm/growing period     125-180 days  
    Sugarcane    :1500-2500 mm/growing period   270-365 days 
    Tomato       :400-800 mm/growing period     135-180 days 
    Banana       :1200-2200 mm/growing period   300-365 days 
*/



/*                                                                                  **  setup  **
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
void setup()
{
    pinMode(moisture_sensor1,INPUT);
    pinMode(moisture_sensor2,INPUT);
    pinMode(temperature_sensor1,INPUT);
    pinMode(temperature_sensor2,INPUT);
    pinMode(temperature_sensor3,INPUT);
    pinMode(temperature_sensor4,INPUT);
    pinMode(pump,OUTPUT);
    pinMode(warning_noted,INPUT);
    pinMode(speaker,OUTPUT);
    pinMode(enable1,OUTPUT);
    pinMode(enable2,OUTPUT);

    //lcd.begin(16, 2);
    
    Serial.begin(9600);
    //calibrated_value =  initial_calibaration();
}



/*                                                                                  ** loop **
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

void loop()
{
/*                                                                          ** Getting the sensor values **
-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

    digitalWrite(enable1,HIGH);
    digitalWrite(enable2,HIGH);
    moisture_val = (analogRead(moisture_sensor1) + analogRead(moisture_sensor2))/2;
    double temperature_val = (analogRead(temperature_sensor1) + analogRead(temperature_sensor2) + analogRead(temperature_sensor3) + analogRead(temperature_sensor4))/4;
    temperature = temperature_val/ 9.31;
    
    moisture_in_mm = (1.8*moisture_val)/329 ;
    
    digitalWrite(enable1,LOW);
    digitalWrite(enable1,LOW);
    
    Serial.print("Moisture:  ");
    Serial.print(moisture_val);
    Serial.print("   Moisture in mm:  ");
    Serial.print(moisture_in_mm);
    Serial.print("   temperature:   "); 
    Serial.println(temperature);
    
    //lcd.setCursor(0,1);
    //lcd.print(temperature);
    
      


	/*                                                                             select the crop 
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

   
Serial.print("select the crop");
Serial.println("type r for rice ");
Serial.println("type c for cotton ");
Serial.println("type p for pea ");
Serial.println("type s for sugarcane");
Serial.println("type b for banana ");
Serial.println("type m for maize ");
Serial.println("type t for tomato ");
/*                                                                    Warning signals for extreme values of soil moisture content
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

//                                               Wilting point 
if(moisture_in_mm > wilting_point) 
{
        Serial.println("Warning !!! : Below wilting point. Crops will die within 2-3 days ");
        Serial.println("push the button to stop the warning signal");
        //lcd.print("at wilting point");
        run_pump(5000); 
        while(warning_noted == HIGH)
        {
          digitalWrite(speaker,HIGH);
          delay(500);
          digitalWrite(speaker,LOW);
          delay(500);
       
        }
}

//                                             filed capacity

if(moisture_in_mm < field_capacity)
{
    Serial.println("Warning !! : Too much water");
    //lcd.print("at field_capacity");
    for(int i =0;i<1000;i++)
    {
        digitalWrite(speaker,HIGH);
        delay(5);
        digitalWrite(speaker,LOW);
        delay(5);
    }
}

/*                                                                  selecting the crop
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

    if(Serial.available()>0)
    {
    	char c = Serial.read();

    	if(c == 'r')
    	{
    		// crop is rice
            Serial.println("rice selected");
            int rice = (rice_water - (field_capacity - moisture_in_mm))*scale;    
    	    run_pump(rice) ; 
    	}

    	if(c == 'c')
    	{
    		// crop is cotton
            Serial.println("cotton selected");
            int cotton = (cotton_water - (field_capacity - moisture_in_mm))*scale;
    	    run_pump(cotton) ; 
    	}

    	if(c == 'p')
    	{
    		// crop is pea
            Serial.println("pea selected");
            int pea = (pea_water - (field_capacity - moisture_in_mm))*scale;
    	    run_pump(pea) ; 
    	}

    	if(c == 's')
    	{
    		// crop is sugarcane
            Serial.println("sugarane selected");
            int sugarcane = (sugarcane_water - (field_capacity - moisture_in_mm))*scale;
    	    run_pump(sugarcane) ; 
    	}

    	if(c == 'b')
    	{
    		// crop is banana
            Serial.println("banana selected");
            int banana = (banana_water - (field_capacity - moisture_in_mm))*scale;
    	    run_pump(banana) ; 
    	}

    	if(c == 'm')
    	{
    		// crop is maize
                Serial.println("maize selected");
    		int maize = (maize_water - (field_capacity - moisture_in_mm))*scale;
                run_pump(maize) ; 
    	}

    	if(c == 't')
    	{
    		// crop is tomato
            Serial.println("Tomato Selected");
            if(growth_stage == 0) tomato_water = 1;             //germination
            else if(growth_stage == 1) tomato_water = 2.5;      //flowering season 
            else if(growth_stage == 2) tomato_water = 4.5;      //fruit season
            else tomato_water = 3.8;                            //average value averaged over total growth period 
            
            int tomato = (tomato_water - (field_capacity - moisture_in_mm))*scale;  
            run_pump(tomato);
            Serial.println("pump running");
            
        }



    }
    delay(20000);
}




	
	/*                          controlling the time for which water pump will work 
	--------------------------------------------------------------------------------------------------------------------*/
void run_pump(double crop)
    {
        digitalWrite(pump,HIGH);
        delay(crop);
        digitalWrite(pump,LOW);
    }

/*double initial_calibaration()
    {   
        int sum = 0;
        digitalWrite(enable1,HIGH);
        digitalWrite(enable1,HIGH);
        for(int i=0;i<10;i++)
        {
        int initial_reading = (analogRead(moisture_sensor1) + analogRead(moisture_sensor2))/2;
        sum = sum + initial_reading;
        }
        digitalWrite(enable1,LOW);
        digitalWrite(enable1,LOW);
        int reading1 = sum/10;
        
        run_pump(delay_1_litre);
        
         sum = 0;
        digitalWrite(enable1,HIGH);
        digitalWrite(enable1,HIGH);
        for(int i=0;i<10;i++)
        {
        int final_reading = (analogRead(moisture_sensor1) + analogRead(moisture_sensor2))/2;
        sum = sum + final_reading;
        }
        digitalWrite(enable1,LOW);
        digitalWrite(enable1,LOW);
        int reading2 = sum/10;

        
        Serial.print("sensor value for 1 litre :  ");
        int val_per_litre = reading2 - reading1;  
        Serial.println(val_per_litre);
        return val_per_litre ; 
    }



    */
