#include <htc.h>
__CONFIG(FOSC_INTOSCIO & WDTE_OFF & PWRTE_OFF & MCLRE_OFF & BOREN_OFF & LVP_OFF & CPD_OFF & CP_OFF);

# define _XTAL_FREQ 4000000
#define LEDnr1 RA0
#define LEDnr2 RA1
#define LEDnr3 RA2
//           GFEDCBA
//        0b01111111
#define o 0b00100011
#define n 0b00101011
#define f 0b00001110
#define h 0b00001011
#define d 0b00100001
#define s 0b00010010
#define t 0b00000111
#define b 0b00000011
void reset_led(void){
   LEDnr1=1;
   LEDnr2=1;
   LEDnr3=1; 
   PORTB=0b011111111;   
}
void print_on(void){
    reset_led();
    LEDnr1=0;
    PORTB=o;
    __delay_ms(1);
    reset_led();
    LEDnr2=0;
    PORTB=n;  
     __delay_ms(1);    
}
void print_hdd(void){
    reset_led();
    LEDnr1=0;
    PORTB=h;
    __delay_ms(1);
    reset_led();
    LEDnr2=0;
    PORTB=d;  
     __delay_ms(1); 
    reset_led();
    LEDnr3=0;
    PORTB=d;  
     __delay_ms(1); 
}
void print_off(void){
    reset_led();
    LEDnr1=0;
    PORTB=o;
    __delay_ms(1);
    reset_led();
    LEDnr2=0;
    PORTB=f;  
     __delay_ms(1); 
    reset_led();
    LEDnr3=0;
    PORTB=f;  
     __delay_ms(1); 
}
void print_stb(void){
    reset_led();
    LEDnr1=0;
    PORTB=s;
    __delay_ms(1);
    reset_led();
    LEDnr2=0;
    PORTB=t;  
     __delay_ms(1); 
    reset_led();
    LEDnr3=0;
    PORTB=b;  
     __delay_ms(1); 
}
void main(void) {
    TMR1ON = 0;
    CMCON = 0x07;
    TRISA0=0;
    TRISA1=0;
    TRISA2=0;
    TRISA3=1;
    TRISA4=1;
    TRISA6=1;
    TRISA7=1;
    TRISB0=0;
    TRISB1=0;
    TRISB2=0;
    TRISB3=0;
    TRISB4=0;
    TRISB5=0;
    TRISB6=0;
    __delay_ms(1);
    while (1){
        if (!RA3)
            print_on();
        if (!RA4)
            print_off();
        if (!RA6)
            print_hdd(); 
        if (!RA7)
            print_stb(); 
    reset_led();
    }
    return;
}
