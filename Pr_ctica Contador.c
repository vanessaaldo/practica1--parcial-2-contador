#pragma config FOSC = HS
#pragma config WDTE = OFF
#pragma config PWRTE = OFF
#pragma config BOREN = ON
#pragma config LVP = OFF
#pragma config CPD = OFF
#pragma config WRT = OFF
#pragma config CP = OFF

const unsigned char hexDigits[16] = {
    0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07,
    0x7F, 0x6F, 0x77, 0x7C, 0x39, 0x5E, 0x79, 0x71
};

#define UP_BUTTON PORTC.F0
#define DOWN_BUTTON PORTC.F1

unsigned int counter = 0;

void mostrarNumero(unsigned int num) {
    PORTB = hexDigits[num];
}

void main() {
    TRISB = 0x00;
    TRISC = 0xFF;
    ADCON1 = 0x06;

    while (1) {
        while (UP_BUTTON == 0) {
            mostrarNumero(counter);
            counter = (counter < 15) ? counter + 1 : 0;
            delay_ms(300);
        }

        while (DOWN_BUTTON == 0) {
            mostrarNumero(counter);
            counter = (counter > 0) ? counter - 1 : 15;
            delay_ms(300);
        }
    }
}