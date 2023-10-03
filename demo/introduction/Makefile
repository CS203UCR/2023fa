all: arraySort bitonic quicksort mm

perfstats.o: perfstats.c
	gcc -O3 -c perfstats.c


mm: mm.c 
	gcc -O3 mm.c perfstats.o -o mm 


arraySort: arraySort.cpp calculate_sum.c
	gcc calculate_sum.c -c 
	g++ -O0 arraySort.cpp calculate_sum.o -o arraySort

bitonic: bitonic.cu
	/usr/local/cuda/bin/nvcc -O3 bitonic.cu -o bitonic
        
quicksort: quicksort.cu 
	/usr/local/cuda/bin/nvcc -O3 quicksort.cu -o quicksort
        
clean:
		rm -f arraySort bitonic quicksort mm
