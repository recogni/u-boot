make distclean;sleep 1;make ariane_generic_rv64_defconfig;sleep 1;make 
make distclean;sleep 1;make ariane_generic_rv64_defconfig;sleep 1;make 
ctags -R
echo Hit return to write to SD card
read x
source make_sd
