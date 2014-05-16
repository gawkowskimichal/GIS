%data read and copy to defined structures
out_file_path ='flow_out.txt';
[E,n,q] = read_data('out.txt');
capacities = zeros(n);
for i=1:q
    capacities(E{i,1},E{i,2}) = E{i,3};
end

tic;
[max_flow, flows] = push_relabel(capacities,n);
display('Czas wykonania: ');
time = toc

%display and save to file
display('Maksymalny przeplyw');
display(max_flow);
display('Przeplywy krawedzi');
display(flows);
save_data(out_file_path, time, max_flow, flows);