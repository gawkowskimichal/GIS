function [ A ] = move_to_front( i, A )
%move_to_front - funkcja przesuwająca dany wierzchołek na początek listy
  temp = A(i);
  for n = i:-1:1
      if n - 1 > 0
        A(n) = A(n-1);
      end
  end
  A(1) = temp;
end

