/*
    ZEsarUX  ZX Second-Emulator And Released for UniX
    Copyright (C) 2013 Cesar Hernandez Bano

    This file is part of ZEsarUX.

    ZEsarUX is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/



#include <stdio.h>
#include <stdlib.h>

#include "msx.h"
#include "vdp_9918a.h"
#include "cpu.h"
#include "debug.h"

z80_byte *msx_vram_memory=NULL;


void msx_out_port_vdp_data(z80_byte value)
{
    vdp_9918a_out_vram_data(msx_vram_memory,value);
}


z80_byte msx_in_port_vdp_data(void)
{
    return vdp_9918a_in_vram_data(msx_vram_memory);
}



z80_byte msx_in_port_vdp_status(void)
{
    return vdp_9918a_in_vdp_status();
}

void msx_out_port_vdp_command_status(z80_byte value)
{
    vdp_9918a_out_command_status(msx_vram_memory,value);
}


void msx_out_port_ppi(z80_byte puerto_l,z80_byte value)
{
    printf ("Out port ppi. Port %02XH value %02XH\n",puerto_l,value);
}

z80_byte msx_in_port_ppi(z80_byte puerto_l)
{
    printf ("In port ppi. Port %02XH\n",puerto_l);

    return 255; //temp
}


void msx_alloc_vram_memory(void)
{
    if (msx_vram_memory==NULL) {
        msx_vram_memory=malloc(16384);
        if (msx_vram_memory==NULL) cpu_panic("Cannot allocate memory for msx vram");
    }
}