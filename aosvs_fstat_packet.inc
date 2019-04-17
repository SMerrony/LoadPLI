/*******
  AOS/VS ?FSTAT Packet Record

  Based on info from System Call Dictionary 093-000241 p.2-162

  This file is part of adfl.

  adfl is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  adfl is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with adfl.  If not, see <http://www.gnu.org/licenses/>.

  Copyright 2014 Steve Merrony
******/

/* on-disk/tape size of FSTAT packet is 50 bytes */
%REPLACE SLTH_W by 25;
%REPLACE SLTH_B by 50;

%REPLACE FLNK by 0;
%REPLACE FDIR by 12;
%REPLACE FDMP by 64; /* guessed symbol */
%REPLACE FSTF by 67;
%REPLACE FTXT by 68;
%REPLACE FPRV by 74;
%REPLACE FPRG by 87;

dcl 1 FSTAT_PKT,
       3 record_format  character, /* ?STYP */
       3 entry_type     fixed binary(7),
       3 stim 		fixed binary(15),
       3 sacp		fixed binary(15),
       3 shfs		fixed binary(15),
       3 slau		fixed binary(15),
       3 smsh		fixed binary(15),
       3 smsl		fixed binary(15),
       3 smil		fixed binary(15),
       3 stch		fixed binary(15),
       3 stcl		fixed binary(15),
       3 stah		fixed binary(15),
       3 stal		fixed binary(15),
       3 stmh		fixed binary(15),
       3 stml		fixed binary(15),
       3 stss		fixed binary(15),
       3 sefw		fixed binary(15),
       3 sefl		fixed binary(15),
       3 sfah		fixed binary(15),
       3 sfal		fixed binary(15),
       3 sidx		fixed binary(15),
       3 sopn		fixed binary(15),
       3 scsh		fixed binary(15),
       3 scsl		fixed binary(15);


