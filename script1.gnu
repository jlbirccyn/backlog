set autoscale fix
set title "backlogfix"
set xlabel "backlogvalue"
set ylabel "prod and comb"
set logscale y
set term png
set output "fig1.png"
set key on top left vertical inside
plot "data1.dat" using 1:2 title "prod",\
     "data1.dat" using 1:3 title "comb"

