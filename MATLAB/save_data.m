function [] = save_data( path, time, max_flow, flows )
fid = fopen(path,'at+');
fprintf(fid,'Czas wykonania: \n');
fprintf(fid,'%d\n',time);  % The format string is applied to each element of a
fprintf(fid,'Maksymalny przeplyw: \n');
fprintf(fid,'%d\n',max_flow);
fprintf(fid,'Przeplywy krawedzi: \n');
[rows,cols] = size(flows);
for row = 1:rows
    for col = 1:cols
    fprintf(fid,'%d\t', flows(row,col));
    end
    fprintf(fid,'\n');
end
fclose(fid);
end

