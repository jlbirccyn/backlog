# System generation and combination computation

## sysgen

Compile the tool:

```
gcc -o sysgen sysgen.c
```

Usage:

```
./sysgen <t> <b>
```

where ```<t>``` is the number of tasks and ```<b>``` the backlog. ```sysgen``` generate a set of systems and of commands suitable for ```combis```. All possible tasks deadlines ≤ backlog are generated. For instance:

```
./sysgen 2 3
```

generates:

```
#!/bin/bash
echo "2 0 0" | ./combis 3
echo "2 0 1" | ./combis 3
echo "2 0 2" | ./combis 3
echo "2 0 3" | ./combis 3
echo "2 1 1" | ./combis 3
echo "2 1 2" | ./combis 3
echo "2 1 3" | ./combis 3
echo "2 2 2" | ./combis 3
echo "2 2 3" | ./combis 3
echo "2 3 3" | ./combis 3
```

At the 7th line, ```2 1 3``` means 2 tasks, the first one has deadline 1 and the second has deadline 3.

```
./sysgen 2 3 > sys-2-3.sh && chmod +x sys-2-3.sh
```

renders the list of command suitable for execution.

## combis

```combis``` computes all feasible backlog combinations according to deadlines.

Compile the tool:

```
gcc -o combis combis.c
```

Usage:

```
echo "<system>" | ./combis [-t] <b>
```

where ```<system>``` is a task system as described above and ```<b>``` the backlog. ```-t``` is optional and traces the found combinations.

Continuing with the previous example, executing ```sys-2-3.sh``` gives:

```
2 tasks, d=(0,0), combis = 1
2 tasks, d=(0,1), combis = 2
2 tasks, d=(0,2), combis = 3
2 tasks, d=(0,3), combis = 4
2 tasks, d=(1,1), combis = 3
2 tasks, d=(1,2), combis = 5
2 tasks, d=(1,3), combis = 7
2 tasks, d=(2,2), combis = 6
2 tasks, d=(2,3), combis = 9
2 tasks, d=(3,3), combis = 10
```

executing the last one with trace: ```echo "2 3 3" | ./combis -t 3``` gives:

```
 0
     0
     1
     2
     3
 1
     0
     1
     2
 2
     0
     1
 3
     0
2 tasks, d=(3,3), combis = 10
```

Backlog attributed to t0 is in first column and backlog attributed to t1 is in second column.

