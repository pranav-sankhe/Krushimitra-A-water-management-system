# **Relays-ElectroMagnetic Switches**

## **Introduction>>>**

Relays are , in simple, ElectroMagnetic switches  which are operated by very small currents(or voltage) that can turn on or off very large currents.These are used such that when the thresholding voltage goes above a particular value(specific for each relay) ,relay switches from on to off or vice-versa depending on whether it is used in normally open or normally closed mode which will be discussed later.

## **Basic Working>>>**

Basically the heart of the relay consists of an electromagnet which becomes a temporary magnet when current flows through it. In the adjacent circuit when current flows through the coil 1 it becomes a temporary magnet(electromagnet) attracting the switch connected to a spring.When the small current exceeds the threshold value for that particular relay the switch gets closed making the circuit 2 in operation.When current falls below the threshold value the spring force pulls the switch towards its original position making the circuit non -operative.These type of relays are used in Normally Open(NO) mode since these are open all the time except when the current(or voltage)across the relay exceeds that  specific value.

**                                      ![how-relay-works2.gif](https://lh3.googleusercontent.com/5oW2xOhOjmUaiZifFwUtzDFLYYHArYX36I8PdS1vtSTZfBFetzjPAmjdJS9e75ykzGFo6PVAjj_3qKzd7POn8e1-fHHeb00XvGVlOWR5XOWSy53zTZl8IWVIFa6C3t9BwaR3mYrW)**

The other mode of using relays is Normally Closed(NC) mode in which ,as clear from the name,the circuit 2 is normally closed and when  current flows through the coil 1 ,it becomes an electromagnet and attracts or repels the switch(both way possible) making the circuit non-operative.

**![how-a-relay-works.gif](https://lh3.googleusercontent.com/CtFoWvqg_KbkAia12J-CXYAfwmt3V5redMFg1R2yXjTRnDcCfOTAr7ShWDTWW3jqat3M2vJnqvZqnTWjtF6h4nQ8rZdNehXzBmYWHYHlDFFAV31RPTxcyD9yUoC7GspBOgF4lKDQ)**

The relatively small current in the input circuit (circuit 1)thus activates the larger current in the output circuit(circuit 2).

Thus you can see with a very small current in coil 1 we can control a very large curent appliance(say any household appliance like TV,refrigerator or in industries a transformer and many complex systems).

## **Common Relay(5-pin relay)>>>**

**![AFE-Relay-BRD-SS-112L-12V-5pins-Max-switching-current-15A-Power-relay-New-origina-10pcs.jpg](https://lh6.googleusercontent.com/loK7OCEvehuMDP7Itbpm8R6OXdwpAbJ7_Y7J4BAHJc8zbHOkwBqeFdlIB3jC7lf3c8nMol4CT27TRe8_XmGM14nhrJ4FDTQD9A8vDMsk13NNJnG5kb5dx7El4G8hAZPe2lh2k5YF)![8.1.jpg](https://lh4.googleusercontent.com/DCn1pNR9wdJwyW5KgAWGARpFRHTGFabUlgEMqXVns-hOXJz3h0yxGV3lVam69r6r89Pf9ybxKh1aBS7uc2fKBm2uE8kzmlOKwTrhzTK0vpZEiWikx8IoNOyOzvz_5mDQx3fOtC-3)**

## **Pin Configuration for the above relay>>>**

1 ,2 & 3 are three consecutive pins in the above diagram ((B) Physical Relay) .

4 & 5 are two consecutive pins in  the same image(NO and NC).

1 & 2: These two are connected to a coil internally (electromagnet) .Whatever the small input current (from sensor or a microcontroller) which will basically be controlling second circuit .So put it across pin 1 and pin 2.

4  & 5: Connecting these two pins depends on whether you want to operate it in normally open or normally closed mode.Choose the one according to your requirement.

3: Connect the switching terminals of the second circuit across pin 3 and the one selected among pin 4 and pin 5.
