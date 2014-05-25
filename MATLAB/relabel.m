function [ height ] = relabel( C, F, height, u, INF, n  )
  min_height = INF;
  for v=1:n
    if (C(u,v) - F(u,v) > 0) 
      min_height = min(min_height, height(v));
      height(u) = min_height + 1;
    end
  end
end
