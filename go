make distclean;sleep 1;make ariane_generic_rv64_defconfig;sleep 1;make 
make distclean;sleep 1;make ariane_generic_rv64_defconfig;sleep 1;make 
echo Hit return to write to SD card
read x
source make_sd
echo
echo Making ctags file...
ctags -R
