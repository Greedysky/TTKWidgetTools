#!/bin/bash
#Greedysky 2016.2.25 monitor the interface's network traffic.

if [ $# -ne 2 ];then
   echo Useage : $0 interface interval count
   echo Example: $0 eth0 2
   exit
fi
eth=$1
interval=$2
inbytesfirst=$(cat /proc/net/dev |tr ':' ' '|awk  '/'$eth'/{print $2}')
if [ -z "$inbytesfirst" ];then
    echo The network interface $eth is not exits!
    exit 1;
fi
outbytesfirst=$(cat /proc/net/dev |tr ':' ' '|awk  '/'$eth'/{print $10}')
inpacketsfirst=$(cat /proc/net/dev |tr ':' ' '|awk  '/'$eth'/{print $3}')
outpacketsfirst=$(cat /proc/net/dev |tr ':' ' '|awk  '/'$eth'/{print $11}')
sleep $interval"s"
i=0
while true
do
   inbytesend=$(cat /proc/net/dev |tr ':' ' '|awk  '/'$eth'/{print $2}')
   outbytesend=$(cat /proc/net/dev |tr ':' ' '|awk  '/'$eth'/{print $10}')
   inpacketsend=$(cat /proc/net/dev |tr ':' ' '|awk  '/'$eth'/{print $3}')
   outpacketsend=$(cat /proc/net/dev |tr ':' ' '|awk  '/'$eth'/{print $11}')
   bytesin=$(($inbytesend-$inbytesfirst))
   bytesout=$(($outbytesend-$outbytesfirst))
   packetsin=$(($inpacketsend-$inpacketsfirst))
   packetsout=$(($outpacketsend-$outpacketsfirst))
   if [ "$bytesin" -lt "0" ];then
      bytesin=$((4294967295-$inbytesfirst+$inbytesend))
      #echo bytesin $bytesin $inbytesfirst $inbytesend
   fi
   if [ "$bytesout" -lt "0" ];then
      bytesout=$((4294967295-$outbytesfirst+$outbytesend))
      #echo bytesout $bytesout $outbytesfirst $outbytesend
   fi
   if [ "$packetsin" -lt "0" ];then
      packetsin=$((4294967295-$inpacketsfirst+$inpacketsend))
      #echo packetsin $packetsin $inpacketsfirst $inpacketsend
   fi
   if [ "$packetsout" -lt "0" ];then
      packetsout=$((4294967295-$outpacketsfirst+$outpacketsend))
      #echo packetsout $packetsout $outpacketsfirst $outpacketsend
   fi
   bytesin=$(($bytesin/$interval))
   bytesout=$(($bytesout/$interval))
   packetsin=$(($packetsin/$interval))
   packetsout=$(($packetsout/$interval))
   sumbytesin=$(($sumbytesin+$bytesin))
   sumbytesout=$(($sumbytesout+$bytesout))
   sumpacketsin=$(($sumpacketsin+$packetsin))
   sumpacketsout=$(($sumpacketsout+$packetsout))
   
   echo $eth $bytesin $bytesout |awk '{printf("%9s|%11d|%12d\n",$1,$2,$3)}'
   inbytesfirst=$inbytesend
   outbytesfirst=$outbytesend
   inpacketsfirst=$inpacketsend
   outpacketsfirst=$outpacketsend
  
   i=$(($i+1))
   sleep $interval"s"
done
