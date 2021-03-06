#include<16f877.h>

#fuses XT,NOWDT,NOPROTECT,NOBROWNOUT,NOLVP,NOPUT,NOWRT,NODEBUG,NOCPD

#use delay(clock = 4000000)

#use fast_io(a)
#use fast_io(b)

#define use_portb_lcd TRUE
#include<lcd.c>

#use rs232(baud=9600, xmit=pin_c6, rcv=pin_c7, parity=N, stop=1) //Haberle?me ayarlar?n? yap?yoruz.

char alinan[10],verilen[10]; //Al?nan ve ver ad?nda string dizi tan?ml?yoruz.
int verilecek; // a portundan al?nacak say?sal de?eri tutacak olan de?i?ken tan?mlan?yor

void main(){
setup_psp(PSP_DISABLED);
setup_timer_1(T1_DISABLED);
setup_timer_2(T2_DISABLED,0,1);
setup_adc_ports(NO_ANALOGS);
setup_adc(ADC_OFF);
setup_ccp1(CCP_OFF);
setup_ccp2(CCP_OFF);

lcd_init();

while(true){
verilecek=input_a(); // A portundan gelen veri, verilecek adl? de?i?kene atan?yor.
sprintf(verilen,"%d",verilecek); // int tipindeki de?i?kenin de?eri string tipindeki de?i?kene string olarak atan?yor.Sebebi haberle?mede string ve char veri tipinde i?lem yap?lmas?d?r.
puts(verilen); //ver ad?ndaki de?i?ken puts komutuyla kar??ya g?nderiliyor.
printf(lcd_putc,"\fAlinan Deger %s",alinan); //char veri tipinde oldu?u i?in %s dedik.
delay_ms(1000);
gets(alinan); //Kar??dan gelen veri okunarak alinan adl? de?i?kene atan?yor.

}

}

