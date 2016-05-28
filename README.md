# [ LEM'IN ] :ant: :ant: :ant: :ant: :ant:
## Path finding algo
- Langage: C
- see docs/lemin.pdf for more
- Date: may 2016

![alt tag](https://github.com/nesthub/c_lemin/raw/master/docs/lemin.png)

## About
This programme is initialized with a file containing the parameters. Paramaters
are describing a map with box and link beetwin them. A starting box and an ending
box + a numbers of ants. All ants have to go from the starting box to the endind box.
Each move are sequenced with a turn system and all ants can only do one move per
turn. A box can't contain more than one ant. It's all about finding wich way
are/is the best to achieve ?

## Personnal goal
Working on how implementing a faster code. Below is a todo list to help:
- Trying with more stack memory than malloc
- Rework some libft functions or make new one oriented on the goal.
- Using memcpy as often as possible.
- Reduce var number in structure.
- Use char unstead of int for boolean type

## Other
- Makefile is a new one recommended by another student.

## repo map
| repo path | description |
| ------------- | ------------- |
| docs/lemin.pdf	 | project description in french |
| incs/				 | headers location				 |
| libft/			 | libft.a project <a href="https://github.com/nesthub/c_libft" target="_blank">here</a> |
| srcs/				 | sources						 |
| auteur			 | 42 login file				 |

## Nameplate
| nameplate | description |
| ------------- | ------------- |
| parsing function | pRun, pAnts, pRead.. |
| data set function | dBox, dBoxCheck, dBoxAdd.. |
| free function	 | fDataBox, fDataRoads.. |
| recursive function | rRoads, rCouple |
| error function | eExit, eExit2 |
| output function | oData |
