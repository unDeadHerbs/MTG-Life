# MTG-Life
Tracks life in Magic the Gathering; written in C++
_______________________________________________________
Reason Made: Used as extra Curricular learning of C++, used as Final project in C++ 1.
Use: Track life in the game of Magic: the Gathering. 

Features:
1)Lets you choose between multiple ways of play. 

2)Can track any number of players life totals.

3)Outputs to both screen and file.

4)Reports Win and loss at end of game.

5) Allows you to play many games.

Features to add:
1) Track win loss record during each run of program.

  a) possibly have seperate file that records each persons records and can be read from and change over multiple runs.

    i) problem: players with same initials.
2) Streamline multiple player life changes
  a) Current: When only one player's life changes, every other person must be inputed as 0.
  b) Possible: have input be player id and their life change, loop over players until get to id and then change.
     i) Problem: multiple life changes happen input slower then current and each has to be inputted seperately.
      A) Soluion: add a input that tells how many time the input loop should run, then have them enter id and change for each person
3) Track multiple simultanious games
  a)Problem: one input device
    i)Solution: create a new program that can run in a network, have it get input from several remote instances of this program
    
Use as framework for:
  1)Visual basic version
  2)Program that can also track:
    a)Poison
    b)deck size
    c)turns
_____________________________________________________
How to Use
All chooses inputted as corisponding number.
1) Choose what version of the game you are playing.
2) Choose further options if any:
  a)number of players or teams
  b)diferent life start
3)Each player inputs their initials
  a)have spaces between teammate
  b)hit enter after each team or seperate player if no teams

*Start playing game of Magic*

4) When life changes input life change
  a)input zero for each player whose life does not change even if player is out of game.
  b)if life lose put a "-" before number, life gain does not need "+"
  
*End game*
  
5) Decide if you want to go agian
  a)either save previous setting or change and repeat steps 1-3. 
