# Projects_Cpp

Game of Life
 implement a mathematical game known as “Game of Life” devised by 
John Conway in 1970. This zero-player game is set on a two dimensional array of cells (potentially 
infinite in dimensions). Each cell is either alive or dead. The game starts with an arbitrary pattern of 
cells set to live status. The rules of game are as follows.
If the cell is dead:
1. Birth: if exactly three of its neighbors are alive, the cell will become alive at the next step.
If the cell is already alive:
2. Survival: if the cell has two or three live neighbors, the cell remains alive.
Otherwise, the cell will die:
3. Death by loneliness: if the cell has only zero or one live neighbors, the cell will become dead 
at the next step.
4. Death by overcrowding: if the cell alive and has more than three live neighbors, the cell also 
dies
