set terminal wxt enhanced

#maxrange = 2e11
#maxrange = 6e12
maxrange = 8e11

set xrange [-maxrange/4:maxrange]
set yrange [-maxrange/4:maxrange*4]

set xlabel "x [m]"
set ylabel "y [m]"

set size ratio 4

set grid

set key outside left

plot "out.dat" using 1:2 pointsize 0 title "Sonne" with lines, \
     "out.dat" using 3:4 pointsize 0 title "Erde" with lines, \
     "out.dat" using 5:6 pointsize 0 title "Venus" with lines, \
     "out.dat" using 7:8 pointsize 0 title "Merkur" with lines, \
     "out.dat" using 9:10 pointsize 0 title "Mond" with lines, \
     "out.dat" using 11:12 pointsize 0 title "Mars" with lines, \
     "out.dat" using 13:14 pointsize 0 title "Sonne 2" with lines
     #"out.dat" using 15:16 pointsize 0 title "Saturn", \
     #"out.dat" using 17:18 pointsize 0 title "Uranus", \
     #"out.dat" using 19:20 pointsize 0 title "Neptun", \
     #"out.dat" using 21:22 pointsize 0 title "Pluto"


#plot "out.dat" using 3:4 every ::4298:::1 # pointsize 0 title "Erde" with lines

pause -1
