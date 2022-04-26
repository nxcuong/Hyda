//LIBRARIES
//=================================================================
#include <hydaFunc.h>   //hyda funcs
#include <hydraulic.h> //hydraulic
#include <hydaTimer.h> //hyda timer as PLCs timer
//=================================================================
//KHAI BAO BIEN TOAN CUC
float dong5 = 0;    //khai bao 2 bien dong5 va dong9
float dong9 = 0;

//=================================================================
void setup() {
  // put your setup code here, to run once:
  // chu y: MAINSWITCH da duoc dinh nghia truoc, ko can dinh ngia lai!!!
  digitalWrite(MAINSWITCH, HIGH);   //bat cong tac nguon chinh, ham nguyen ban cua arduino
  
  PWM3_SETUP(1000); //cai dat timer3 pwm 1000Hz
  PWM5_SETUP(5000); //cai dat timer5 pwm 5000Hz
}

void loop() {
  // put your main code here, to run repeatedly:
  PWMOUT(9, 45.0);   //pwm out kenh 9, do rong xung 45%, luu y tan so f = 5000Hz
  // kich dau ra 5
  DOUT(5, DIN(1));        //ghi gia tri kenh ra 5 = kenh vao 1

  //doc dong dien ra tai kenh 5 va 9
  // gia tri dong5 va dong9 mang kieu du lieu float, CUR(i) mang kieu int do do can chuyen sang float
  dong5 = float(CUR(5)) * 23.46;        //I = gia_trị_hàm * 23.46 (mA) kenh tu 1 >> 8
  dong9 = float(CUR(9)) * 4.8876;        //I = gia_trị_hàm * 4.8876 (mA) kenh tu 9 >> 10
  
}
