set autoscale fix
set title "backlog and nbtasks variable"
set xlabel "backlogvalue"
set ylabel "nbtasks"
set logscale z
set term png
set output "fig3.png"
set key on top left vertical inside
splot "data3.dat" using 1:2:3 title "prod",\
      "data3.dat" using 1:2:4 title "comb"
