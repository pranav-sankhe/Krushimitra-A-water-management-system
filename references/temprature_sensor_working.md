# **LM35 Temperature Sensor**

**Key Points>>>**

**Supply Voltage(Vcc): (4-20)V**

**Output Voltage(Vout) proportional to temperature (in degree celcius)**

**Sensor has a sensibility of 10mV/degree  celcius.**

**For getting the temperature in  celcius use this  simple relation>>>  Temperature (in degree    celcius) =Vout * (100 degree celcius/Volts)**

**i.e if Vout is 1V => temperature =100 degree  celcius.**

# **Introduction>>> ![LM35.jpg](https://lh5.googleusercontent.com/6X9hQuX_zJaj4f68eQIjCewEkldG5HOXPRlVf6jwEOXJ_GCBUqMu-7ah6r0b1qfSDPFlx7S24oz6F3Tx-AQBuVIWtbJPuOpGYXxTWiY9hwkZ2qqikMgM09BwpfuxWqGvVjKOE3VU)**

LM35 is a well used temperature sensor which can be used in any environment to get the temperature of the medium surrounding it.It is a 3 pin IC

whose pins are such that when looking from the flat end of IC,the left pin is Vcc ,middle one is for taking the analog value Vout (which gives the measure of

temperature) ,and right one is for ground.

## **Internal Working>>>![main-qimg-83a37836d50225058c92ad81fd26e729-c.jpg](https://lh3.googleusercontent.com/8pglgZlE5cCiwqadprKo9BkqIIb7UmtMpzOTGG8xNDzx3RKNF0MyRR6EfbGkZvh_bKeiMjBdS7FI03U_uIUsGn29CsrkLj2q7CSYYWIhAYwg2RkXalaYEftl5dqEM-kyKVVZTKW5)**

Briefly there are two transistors of which one has ten times emitter area of the other.This means it has one tenth of the current density ,since the same current

is going through both transistors.This causes a voltage across resistor R1 that is proportional to the absolute temperature and is almost linear about the temperature range we care about.The amplifier at the top ensures that the voltage at the base of left transistor (Q1) is proportional to absolute temperature by comparing the output of the two transistors.The amplifier at the right converts absolute temperature (in Kelvin) into celcius.The little circled i is a constant current supply source.

The two resistors are calibrated in the factory to produce a highly accurate temperature sensor.

## **Precautions>>>**

### When using the sensor  in moisture environments ,for protection of the IC ,the three pins and all electrical connections should be properly insulated.
