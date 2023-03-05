# Projects Cpp

 # Game of Life
## Implementation a mathematical game known as “Game of Life” devised by John Conway in 1970. 

## This zero-player game is set on a two dimensional array of cells (potentially infinite in dimensions). Each cell is either alive or dead. The game starts with an arbitrary pattern of cells set to live status.
# Implementation rules of game:
- If the cell is dead:
- Birth: if exactly three of its neighbors are alive, the cell will become alive at the next step.
- If the cell is already alive:
- Survival: if the cell has two or three live neighbors, the cell remains alive. Otherwise, the cell will die:
- Death by loneliness: if the cell has only zero or one live neighbors, the cell will become dead 
at the next step.
- Death by overcrowding: if the cell alive and has more than three live neighbors, the cell also 
dies
