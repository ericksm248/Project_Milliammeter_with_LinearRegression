#include <12F683.h>
#device adc=10
 
#FUSES NOWDT                    //No Watch Dog Timer
#FUSES INTRC_IO
#FUSES NOCPD                    //No EE protection
#FUSES NOPROTECT                //Code not protected from reading
#FUSES NOMCLR                     //Master Clear pin enabled
#FUSES PUT                    //No Power Up Timer
#FUSES BROWNOUT                 //Reset when brownout detected
#FUSES IESO                     //Internal External Switch Over mode enabled
#FUSES FCMEN
 
#use delay(internal=8M)
 
#use spi(BAUD=57600, DO=PIN_A1, CLK=PIN_A2,SAMPLE_RISE, BITS=8,MSB_FIRST)
#use fast_io(A)
 
Int dato=0b01110111;
 
void SPI_Max7219(int8 address,int8 dato)
{
   OUTPUT_LOW(PIN_A5);
   spi_xfer(address);
   spi_xfer(dato);
   OUTPUT_HIGH(PIN_A5);
} 
 
void imprimir_4digit(int16 numero)
{
 
   int8 millares = 0;//numero/100;
   int8 centenas = 0;
   int8 decenas = 0;
   int8 unidades = 0;
   if(numero>999)
   {
      millares = (int8)(numero/1000);
      SPI_Max7219(0x04,millares);
   }
   else
   {
      SPI_Max7219(0x04,0x0f);//borrar digito
   }
   if(numero>99)
   {
      centenas = (int8)((numero-(millares*1000))/100);
      SPI_Max7219(0x03,centenas);
   }
   else
   {
      SPI_Max7219(0x03,0x0f);//borrar digito
   }
   if(numero>9)
   {
      decenas = (int8)((numero/10 - (millares*100 + centenas*10)));
      SPI_Max7219(0x02,decenas);
   }
   else
   {
      SPI_Max7219(0x02,0x0f);//borrar digito
   }
   unidades=(int8)(numero-(millares*1000 + centenas*100 + decenas*10 ));
   SPI_Max7219(0x01,unidades);
 
}
 
void main()
{
   int8 count = 0;
   int32 digits;
   int32 aux;
   int16 raw=0;//old_data=0;
   setup_adc_ports(sAN0);
   setup_comparator(NC_NC_NC_NC);
   setup_vref(FALSE);
   setup_oscillator(OSC_8MHZ);
 
 
   //setup_adc_ports(NO_ANALOGS);
   set_tris_a(0b00001001);
   set_adc_channel(0);
   setup_adc(ADC_CLOCK_DIV_8);
   delay_us(50);
 
 
   //test displays Leds ON
   SPI_Max7219(0x0F,0x01);
   delay_ms(1000);
   //Modo normal Activo
   SPI_Max7219(0x0F,0x00);
   //Activar modo no-decode (Caracteres personalizados)
   SPI_Max7219(0x09,0xff);
   //Configuracion Intensidad Luz
   SPI_Max7219(0x0A,0x03);
   //Numero de digitos escaneados
   SPI_Max7219(0x0B,0x07);  // de 0 a 7
   //Empezar operacion normal de deco
   SPI_Max7219(0x0C,0x01);
 
   for (count=1;count<=8;count++)
   {
      SPI_Max7219(count,0x0f);
   }
   while(1)
   { 
      raw = read_adc();
      aux =(int32)raw;
      digits = ((aux*11835)+19419)/10000;
      imprimir_4digit(digits);
      delay_ms(200);
   }
}
