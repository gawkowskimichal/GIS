function [ max_flow, F, height ] = push_relabel_highest_label( C, n )
INF = 20;
F = zeros(n);
 excess = zeros(1,n);
  height = zeros(1,n);
  highest_label_index = 2;
  seen = zeros(1,n);
  list = zeros(1,n-2);
  for i=1:n-2
      list(i) = i+1;
  end
  height(1) = n;
  excess(1) = INF;
  for i=1:n
    [F,excess] = push(C, F, excess, 1, i);
  end
  active_nodes = 1;
  while(active_nodes)
    active_nodes = 0;
    for i=2:n-1;
        if excess(i) > 0
            active_nodes = 1;
        end
    end
    if excess(highest_label_index) <= 0
        highest_label_index = n;
        for j=n-1:-1:2
            if excess(j) > 0 && height(j) >= height(highest_label_index)
                highest_label_index = j;
            end
        end
    end
    u = highest_label_index;
    [ F,excess,seen,height,highest_label_index ] = discharge_highest_label(C, F, excess, height, seen, u, n, INF,highest_label_index);
  end
  max_flow = 0;
   for i=1:n
     max_flow = max_flow + F(1,i);
   end
end

