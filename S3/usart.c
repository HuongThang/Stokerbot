/*----------------------------------------------------------------------------
 Copyright:      Radig Ulrich  mailto: mail@ulrichradig.de
 Author:         Radig Ulrich
 Remarks:        
 known Problems: none
 Version:        24.10.2007
 Description:    RS232 Routinen

 Dieses Programm ist freie Software. Sie k�nnen es unter den Bedingungen der 
 GNU General Public License, wie von der Free Software Foundation ver�ffentlicht, 
 weitergeben und/oder modifizieren, entweder gem�� Version 2 der Lizenz oder 
 (nach Ihrer Option) jeder sp�teren Version. 

 Die Ver�ffentlichung dieses Programms erfolgt in der Hoffnung, 
 da� es Ihnen von Nutzen sein wird, aber OHNE IRGENDEINE GARANTIE, 
 sogar ohne die implizite Garantie der MARKTREIFE oder der VERWENDBARKEIT 
 F�R EINEN BESTIMMTEN ZWECK. Details finden Sie in der GNU General Public License. 

 Sie sollten eine Kopie der GNU General Public License zusammen mit diesem 
 Programm erhalten haben. 
 Falls nicht, schreiben Sie an die Free Software Foundation, 
 Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307, USA. 
------------------------------------------------------------------------------*/
#include "config.h"
#include "usart.h"

#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <stdlib.h>
#include <stdarg.h>
#include <ctype.h>
#include <string.h>
#include <avr/io.h>

//----------------------------------------------------------------------------
//Init serielle Schnittstelle
void usart_init(unsigned long baudrate) 
{ 
	//Serielle Schnittstelle 1
  	//Enable TXEN im Register UCR TX-Data Enable
	UCSR0B =(1 << TXEN0);
	// 0 = Parity Mode Disabled
	// 1 = Parity Mode Enabled, Even Parity
	// 2 = Parity Mode Enabled, Odd Parity
	//UCSRC = 0x06 + ((parity+1)<<4);
	//UCSRC |= (1<<USBS);
	//Teiler wird gesetzt 
	
	UBRR0=(F_CPU / (baudrate * 16L) - 1);
}

int uart_putchar(char c, FILE *stream)
{
    while(!(UCSR0A & (1<<UDRE0)));
    UDR0 = c;
	return 0;
}

