#include "aduc812.h"


#define MAXBASE 0x8 //для доступа к регистрам ПЛИС нужно переключить страничный регистр DPP на 8 страницу памяти

/**----------------------------------------------------------------------------
                            write_max
-------------------------------------------------------------------------------
write_max - запись байта в регистр ПЛИС 
regnum - адрес регистра ПЛИС
val - записываемое значение 
результат- нет
-----------------------------------------------------------------------------*/
void write_max( XDATA(unsigned char) *regnum, unsigned char val )
{
unsigned char oldDPP = DPP;

    DPP     = MAXBASE;
    *regnum = val;
    DPP     = oldDPP;
}

/**----------------------------------------------------------------------------
                            read_max
-------------------------------------------------------------------------------
read_max -чтение байта из регистра ПЛИС
regnum - адрес регистра ПЛИС
результат- прочитанное значение
-----------------------------------------------------------------------------*/
unsigned char read_max( XDATA(unsigned char) *regnum )
{
unsigned char oldDPP=DPP;
unsigned char val;

    DPP = MAXBASE;
    val = *regnum;
    DPP = oldDPP;

    return val;
}

