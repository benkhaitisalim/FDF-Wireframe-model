export MallocStackLogging=1
./fdf maps/42.fdf & 
pid=$!
sleep 1
leaks $pid