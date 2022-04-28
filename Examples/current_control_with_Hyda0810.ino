/* hyda0810 currrent control on DO9
 * Current setpoint by digital input
 * DI1 = 0mA
 * DI2 = 200mA
 * DI3 = 450mA
 * DI4 = 600mA
 * DI5 = 700mA
 * 
 */
//=================================================================
#include <hydaFunc.h>   //hyda funcs
//#include <hydraulic.h> //hydraulic
//#include <hydaTimer.h> //hyda timer as PLCs timer
#include <movingAvg.h>//average lib
#include <PID_v1.h>    //pid lib
//=================================================================
//Variables
int I_avg = 0;  //average current out of DO10
movingAvg Isen(65); //average 65 values
double setPoint, inPut, outPut;
PID PID10(&inPut, &outPut, &setPoint, 2.0, 25.5, 0, P_ON_E, DIRECT);  //pid class

void setup() {
  // put your setup code here, to run once:
  noInterrupts();
  Serial.begin(115200);
  Isen.begin();   //average setup
  
  //PWM5_SETUP(5000); //cai dat timer5 pwm 5000Hz
  t5Config(); //config timer5 ICR5 = 5000
  //================================PID setting
  //PID10.SetOutputLimits(0,ICR5);
  PID10.SetOutputLimits(0,5000);
  PID10.SetSampleTime(30);
  PID10.SetMode(AUTOMATIC);  

  //==========================end of PID setting
  digitalWrite(MAINSWITCH, HIGH);   //bat cong tac nguon chinh
  
   
  interrupts(); //enable interrupt !
}//END OF SETUP

void loop() {
  // put your main code here, to run repeatedly:
  //setPoint selection
  if(DIN(1))  setPoint = 0;
  if(DIN(2))  setPoint = 200.0;
  if(DIN(3))  setPoint = 450.0;
  if(DIN(4))  setPoint = 600.0;
  if(DIN(5))  setPoint = 700.0;

  
  int I_avg = Isen.reading(CUR(10));  //average current reading
  inPut = I_avg * 4.8876; //current calculation
  //PID calculation
  PID10.Compute();
  OCR5B = int(outPut); //also can use PWMOUT
  //OCR5A = outPut; //also can use PWMOUT
  Serial.print(setPoint);
  Serial.print(" ");
  Serial.println(int(inPut));
}
