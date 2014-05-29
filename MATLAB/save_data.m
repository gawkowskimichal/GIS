function [] = save_data( path, time, max_flow, flows, flag )
%save_data - funkcja zapisująca do pliku tekstowego 
%informacje o wynikach wykonania algorytmu 
fid = fopen(path,'at+');
fprintf(fid,'Option: ');
fprintf(fid,'%s\n', flag);
fprintf(fid,'Czas wykonania: \n');
fprintf(fid,'%f\n',time * 1000);
fprintf(fid,'Maksymalny przeplyw: \n');
fprintf(fid,'%d\n\n',max_flow);
%fprintf(fid,'Przeplywy krawedzi: \n');
%[rows,cols] = size(flows);
%for row = 1:rows
%    for col = 1:cols
%    fprintf(fid,'%d\t', flows(row,col));
%    end
%    fprintf(fid,'\n');
%end
fclose(fid);
end

