set autoscale fix
set title "backlogvariable"
set xlabel "backlogvalue"
set ylabel "prod and comb"
set logscale y
set term png
set output "fig2.png"
set key on top left vertical inside
plot "data2.dat" using 1:2 title "prod",\
     "data2.dat" using 1:3 title "comb"

