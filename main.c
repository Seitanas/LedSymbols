#include <htc.h>
__CONFIG(FOSC_INTOSCIO & WDTE_OFF & PWRTE_OFF & MCLRE_OFF & BOREN_OFF & LVP_OFF & CPD_OFF & CP_OFF);
#define _XTAL_FREQ 4000000

#define LEDnr1 RB4
#define LEDnr2 RB5
#define LEDnr3 RB6
#define LEDnr4 RB7

#define Stb RA0
#define On  RA1
#define OnH RA7
#define Ant RA6

#define a RA2 
#define b RA4 
#define c RB1
#define d RB2
#define e RB3
#define f RA3
#define g RB0

void reset_led(void){
   LEDnr1=1;
   LEDnr2=1;
   LEDnr3=1; 
   LEDnr4=1; 
   a=1;
   b=1;
   c=1;
   d=1;
   e=1;
   f=1;
   g=1;    
}

void letter_A(void){
    a=0;
    b=0;
    c=0;
    e=0;
    f=0;
    g=0;
}

void letter_b(void){
   c=0;
   d=0;
   e=0;
   f=0;
   g=0;  
}

void letter_H(void){
    b=0;
    c=0;
    e=0;
    f=0;
    g=0;
}

void letter_n(void){
    a=1;
    b=1;
    c=0;
    d=1;
    e=0;
    f=1;
    g=0;
}

void letter_O(void){
    a=0;
    b=0;
    c=0;
    d=0;
    e=0;
    f=0;
}

void letter_S(void){
    a=0;
    c=0;
    d=0;
    f=0;
    g=0;
}

void letter_t(void){
    a=1;
    b=1;
    c=1;
    d=0;
    e=0;
    f=0;
    g=0;
}

void letter_space(void){
    a=1;
    b=1;
    c=1;
    d=1;
    e=1;
    f=1;
    g=1;
}

void draw_symbols(char symbols[4]){
    unsigned int i;
    for (i = 0; i < 4; i++){
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
            case 3:
                LEDnr4=0;
                break;
        }
        switch (symbols[i]){
            case 'A':
               letter_A(); 
               break;
            case 'b':
               letter_b(); 
               break;
            case 'H':
               letter_H();
               break;
            case 'n':
               letter_n();
               break;
            case 'O':
               letter_O();
               break;
            case 'S':
               letter_S();
               break;
            case 't':
               letter_t();
               break;
            case ' ':
               letter_space();
               break;
            default:
               letter_space();
        }
        __delay_ms(1);        
    }  
    reset_led();
}
void main(void) {
    TMR1ON = 0; //disabling timer for RB6-RB7 to be able to go outputs
    CMCON = 0x07;
    
    TRISA0=1;
    TRISA1=1;
    TRISA2=0;
    TRISA3=0;
    TRISA4=0;
    TRISA5=0;
    TRISA6=1;
    TRISA7=1;
    
    TRISB0=0;
    TRISB1=0;
    TRISB2=0;
    TRISB3=0;
    TRISB4=0;
    TRISB5=0;
    TRISB6=0;
    TRISB7=0;
    reset_led();
    __delay_ms(1);
    while (1){
        if (On)
            draw_symbols("On  ");
        else if (Stb&&!On&&!OnH&&!Ant)
            draw_symbols("Stb ");
        else if (OnH)
            draw_symbols("On H"); 
        else if (Ant)
            draw_symbols("Ant ");
        reset_led();
    }
}
