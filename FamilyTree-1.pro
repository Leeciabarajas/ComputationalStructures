%Family Tree
%Name:Leecia Barajas

%these people(X) are parents (Y)
parent(pamela,bob).
parent(tom,bob).
parent(tom,liz).
parent(bob,anna).
parent(bob,patricia).
parent(patricia,jim). 

%our females
female(pamela).
female(liz).
female(anna).
female(patricia).

%our males
male(tom).
male(bob).
male(jim).

%you are an offspring if you hae a parent
offspring(Y,X):-
    parent(X,Y).
%you are a mother if you are a parent and female    
mother(X,Y):- 
    parent(X,Y),
    female(X).
%you are a grandparents if you have a kid and your kid has a kid    
grandparent(X,Y):-
    parent(X,Kid),
    parent(Kid,Y).
%you are a sister if you're female and share a parent w/another       
sister(X,Y):-
    female(X),
    parent(D,X),
    parent(D,Y),
    X\=Y. %dont count yorself 
%you are an ancestor if you are a parent    
ancestor(X,Y):-
    parent(X,Y).
%you're an ancestor again if you are a parents had a baby   
ancestor(X,Y):-
    parent(X,Baby),
    ancestor(Baby,Y). 

 