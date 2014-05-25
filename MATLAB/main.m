function [] = main (path, flag)

%data read and copy to defined structures
out_file_path ='flow_out.txt';
[E,n,q] = read_data(path);
path_exists = DFS(E,n,1,n);
if path_exists
    display('Œcie¿ka od Ÿród³a do ujœcia istnieje!');
else
    display('Œcie¿ka od Ÿród³a do ujœcia NIE istnieje!');
    return;
end
capacities = zeros(n);
for i=1:q
    capacities(E{i,1},E{i,2}) = E{i,3};
end

tic;
if (flag == '1')
[max_flow, flows, height] = push_relabel(capacities,n);
else
[max_flow, flows, height] = push_relabel_highest_label(capacities,n);
end
time = toc;
display(height);
%display and save to file
display('Czas wykonania: ');
display(time);
display('Maksymalny przeplyw');
display(max_flow);
display('Przeplywy krawedzi');
display(flows);
save_data(out_file_path, time, max_flow, flows);
end