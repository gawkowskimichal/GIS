function [Flows,excesses] = push( Capacities, Flows, excesses, u, v )
%push - operacja push - ustawia maksymalną wartość przedprzepływu
%na krawędzi wychodzącej z wierzchołka u i wchodzącej do wierzchołka v
send = min(excesses(u), Capacities(u,v) - Flows(u,v));
Flows(u,v) = Flows(u,v) + send;
Flows(v,u) = Flows(v,u) - send;
excesses(u) = excesses(u) - send;
excesses(v) = excesses(v) + send;
end

