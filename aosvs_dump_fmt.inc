/*******
  AOS/VS Dump Format structures

  Based on info from AOS/VS Systems Internals Reference Manual (AOS/VS Rev. 5.00)

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

%INCLUDE "aosvs_fstat_packet.inc";

%REPLACE START_DUMP_TYPE  by 0;
%REPLACE FSB_TYPE 	  by 1;
%REPLACE NB_TYPE 	  by 2;
%REPLACE UDA_TYPE	  by 3;
%REPLACE ACL_TYPE	  by 4;
%REPLACE LINK_TYPE	  by 5;
%REPLACE START_BLOCK_TYPE by 6;
%REPLACE DATA_BLOCK_TYPE  by 7;
%REPLACE END_BLOCK_TYPE	  by 8;
%REPLACE END_DUMP_TYPE	  by 9;

%REPLACE MAX_BLOCK_SIZE   by 16384;
%REPLACE MAX_ALIGNMENT_OFFSET by 256;

dcl 1 RECORD_HEADER,
       3 record_type   fixed binary(15),
       3 record_length fixed binary(15);

dcl 1 START_OF_DUMP,
       3 sod_header             like RECORD_HEADER,
       3 dump_format_revision	fixed binary(15),
       3 dump_time_secs		fixed binary(15),
       3 dump_time_mins		fixed binary(15),
       3 dump_time_hours	fixed binary(15),
       3 dump_time_day		fixed binary(15),
       3 dump_time_month	fixed binary(15),
       3 dump_time_year		fixed binary(15);

dcl 1 FILE_STATUS_BLOCK,
       3 fsb_header	like RECORD_HEADER,
       3 fstat		like FSTAT_PKT;

dcl 1 NAME_BLOCK,
       3 nb_header	like RECORD_HEADER,
       3 file_name	char(512) varying; 

dcl 1 UDA_BLOCK,
       3 uda_header	like RECORD_HEADER,
       3 uda		char(256);

dcl 1 ACL_BLOCK,
       3 acl_header	like RECORD_HEADER,
       3 acl		char(512) varying;

dcl 1 LINK_BLOCK,
       3 link_header	like RECORD_HEADER,
       3 link_resolution_name char(512) varying;

dcl 1 START_BLOCK,
       3 start_block_header	like RECORD_HEADER;

dcl 1 DATA_HEADER_BLOCK,
       3 data_header	 like RECORD_HEADER,
       3 byte_address	 fixed binary(31),
       3 byte_length	 fixed binary(31),
       3 alignment_count fixed binary(15);

dcl 1 END_BLOCK,
       3 end_block_header	like RECORD_HEADER;

dcl 1 END_OF_DUMP,
       3 end_dump_header	like RECORD_HEADER;


