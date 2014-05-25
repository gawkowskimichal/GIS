function [ F,excess,seen,height,max_height ] = discharge_highest_label( C, F, excess, height, seen, u, n, INF, max_height )
    while (excess(u) > 0)
        if (seen(u) < n+1)
          v = seen(u);
          if (v == 0)
            v = 1;
          end
          if ((C(u,v) - F(u,v) > 0) && (height(u) > height(v)))
            [F,excess] = push(C, F, excess, u, v);
          else
            seen(u) = seen(u) + 1;
          end
        else
          [height,max_height] = relabel_highest_label(C, F, height, u, INF, n, excess, max_height);
          seen(u) = 1;
        end
    end
end

