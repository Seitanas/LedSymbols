#include <htc.h>
__CONFIG(FOSC_INTOSCIO & WDTE_OFF & PWRTE_OFF & MCLRE_OFF & BOREN_OFF & LVP_OFF & CPD_OFF & CP_OFF);
#define _XTAL_FREQ 4000000
#define LEDnr1 RA0
#define LEDnr2 RA1
#define LEDnr3 RA2
//           GFEDCBA
//        0b01111111
#define b 0b00000011
#define d 0b00100001
#define f 0b00001110
#define h 0b00001011
#define n 0b00101011
#define o 0b00100011
#define s 0b00010010
#define t 0b00000111
unsigned int i;
void reset_led(void){
   LEDnr1=1;
   LEDnr2=1;
   LEDnr3=1; 
   PORTB=0b011111111;   
}
void draw_symbols(char symbols[3]){
    for (i = 0; i < 3; i++){
        reset_led();
        switch (i){
            case 0:
                LEDnr1=0;
                break;
            case 1:
                LEDnr2=0;
                break;
            case 2:
                LEDnr3=0;
                break;
        }
        switch (symbols[i]){
            case 'b':
               PORTB=b; 
               break;
            case 'd':
               PORTB=d;
               break;
            case 'f':
               PORTB=f;
               break;
            case 'h':
               PORTB=h;
               break;
            case 'n':
               PORTB=n;
               break;
            case 'o':
               PORTB=o;
               break;
            case 's':
               PORTB=s;
               break;
            case 't':
               PORTB=t;
               break;
            default:
                reset_led();
        }
        __delay_ms(1);        
    }   
}
void main(void) {
    TMR1ON = 0; //disabling timer for RB6-RB7 to be able to go outputs
    CMCON = 0x07;
    TRISA=0b11111000;
    TRISB=0b00000000;
    __delay_ms(1);
    while (1){
        if (!RA3)
            draw_symbols("on");
        if (!RA4)
            draw_symbols("off");
        if (!RA6)
            draw_symbols("hdd"); 
        if (!RA7)
            draw_symbols("stb"); 
    reset_led();
    }
    return;
}
