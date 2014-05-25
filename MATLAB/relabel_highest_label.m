function [ height, max_height_index ] = relabel_highest_label( C, F, height, u, INF, n, excess, max_height_index  )
  min_height = INF;
  for v=1:n
    if (C(u,v) - F(u,v) > 0) 
      min_height = min(min_height, height(v));
      height(u) = min_height + 1;
      if height(max_height_index) < height(u) && excess(u) > 0
        max_height_index = u;
      end
    end
  end
end
