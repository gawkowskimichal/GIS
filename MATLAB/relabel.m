function [ height ] = relabel( C, F, height, u, INF, n  )
%//relabel - modyfikuje wysokość wierzchołka aktywnego,
%który nie ma dopuszczalnych krawędzi wychodzących w sieci przedprzepływów,
%przypisując najmniejszą możliwą wysokość, która spowoduje powstanie krawędzi dopuszczalnych
  min_height = INF;
  for v=1:n
    if (C(u,v) - F(u,v) > 0) 
      min_height = min(min_height, height(v));
      height(u) = min_height + 1;
    end
  end
end
