% DFS (kraw�dzie, liczba wierzcho�k�w, start, stop) (od pierwszego do ostatniego)
function [ path_exists ] = DFS( E, n, s, d)
%DFS - funkcja przeglądająca graf wgłąb, która służy do określania
%czy pomiędzy źródłem i ujściem istnieje ścieżka
path_exists = 0;
if s == d
    path_exists = true;
    return
else
    [NofEdges,NofParams] = size(E);
    for i=1:NofEdges
        if E{i,1} == s
            path_exists = path_exists | DFS(E,n,E{i,2},d);
        end
    end
end
end

