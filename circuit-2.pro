%Leecia Barajas
%Part of 1 of assigment 3
%Write prolog logic for the picture of circuit 



%definitions for logic 

and(0,0,0).%and truth table/logic 
and(0,1,0).
and(1,0,0).
and(1,1,1).

or(0,0,0). %or truth table/logic
or(1,0,1).
or(0,1,1).
or(1,1,1).

not(0,1). %note truth table/logic
not(1,0). 


%logic for my circuit
logic(X,Y,X,F):-
and(X,Y,A),
not(Z,B),
and(Y,B,C),
or(A,C,F).