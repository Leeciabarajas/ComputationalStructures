%Prolog Weather and Birds
%Leecia Barajas

%list day and weather
weather(sunday,fair).
weather(monday,overcast).
weather(tuesday,fair).
weather(wednesday,fair).
weather(thursday,overcast).
weather(friday,rainy).
weatehr(saturday,overcast).

%when the sky is blue
sky(X,blue):-
    weather(X,fair).
%when sky is gray    
sky(X,gray):-
    weather(X,overcast). 
    
%when birds active    
active(sunday).
active(tuesday).
active(thursday). 
   
%when happy birders   
happyBirders(Day):-
    active(Day),
    weather(Day,fair).