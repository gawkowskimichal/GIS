%sample data
capacities = zeros(6);
   capacities(1,2) = 2;
   capacities(1,3) = 9;
   capacities(2,3) = 1;
   capacities(2,4) = 0;
   capacities(2,5) = 0;
   capacities(3,5) = 7;
   capacities(4,6) = 7;
   capacities(5,6) = 4;
flows = zeros(6);

[E,n,q] = read_data('out.txt');

%max_flow = push_relabel(capacities,E,n,q);
n = 6;
max_flow = push_relabel_sample(capacities,E,n);
display(max_flow);